/*
  Session Boss
  A Firefox extension to manage the browser tab sessions.
  Copyright (C) 2018 William Wong.  All rights reserved.
  williamw520@gmail.com
*/

// db module
(function(scope, modulename) {
    "use strict";

    // Import:
    // import /pkg/spark-md5/spark-md5.min.js
    // import logger
    // import appcfg
    // import app

   let log = new logger.Logger(appcfg.APPNAME, modulename, appcfg.LOGLEVEL);

    var module = function() { };       // Module object to be returned; local reference to the package object for use below.
    if (modulename)
        scope[modulename] = module;    // set module name in scope, otherwise caller sets the name with the returned module object.
    
    const INDEXED_DB_NAME = "sessionboss-db";
    const INDEXED_DB_VERSION = 2;

    let openedDB;       // cached opened db


    // The IndexedDb API is kind of fucked up.  Add adaptors to make it easier to use.

    // Adaptor to turn a request into a promise.
    function pRequest(req) {
        return new Promise(function(resolve, reject) {
            req.onsuccess   = event => resolve(event.target.result);    // pRequest(req).then( result )
            req.onerror     = event => reject(event.target.error);      // pRequest(req).catch( error )
        });
    }

    // Adaptor to turn a transaction into a promise.
    function pTransaction(tx) {
        return new Promise(function(resolve, reject) {
            tx.oncomplete   = event => resolve(event.target.result);    // pRequest(req).then( result )
            tx.onerror      = event => reject(event.target.error);      // pRequest(req).catch( error )
            tx.onabort      = event => reject(event.target.error);      // pRequest(req).catch( error )
        });
    }


    function pCreateDB() {
        let req = window.indexedDB.open(INDEXED_DB_NAME, INDEXED_DB_VERSION);
        req.onupgradeneeded = event => {
            log.info("onupgradeneeded");
            let db = event.target.result;
            if (!db.objectStoreNames.contains("faviconImage")) {
                let store = db.createObjectStore("faviconImage", { keyPath: "key" });   // Don't change any of the key fieldname; Firefox doesn't seem to like it.
            }
            if (!db.objectStoreNames.contains("faviconLastUse")) {
                let store = db.createObjectStore("faviconLastUse", { keyPath: "key" });
                store.createIndex("timestamp", "timestamp", { unique: false });
            }
            if (!db.objectStoreNames.contains("faviconTabUrl")) {
                let store = db.createObjectStore("faviconTabUrl", { keyPath: "key" });
            }
        };
        return pRequest(req);
    }

    function pOpenDB() {
        if (openedDB) {
            return Promise.resolve(openedDB);
        } else {
            return pCreateDB().then( db => openedDB = db );             // save and return db.
        }
    }

    function closeDB() {
        if (openedDB) {
            openedDB.close();
            openedDB = null;
        }
    }

    async function pSaveFaviconImage(tab) {
        if (!(tab.favIconUrl && tab.favIconUrl.startsWith("data:image/"))) {
            return Promise.resolve(null);
        }
        let favhash = new SparkMD5().append(tab.favIconUrl).end();      // image content based hash
        let urlhash = new SparkMD5().append(tab.url).end();             // tab url content based hash
        let db      = await pOpenDB();
        let tx      = db.transaction(["faviconImage", "faviconTabUrl", "faviconLastUse"], "readwrite");
        let imStore = tx.objectStore("faviconImage");
        let tuStore = tx.objectStore("faviconTabUrl");
        let luStore = tx.objectStore("faviconLastUse");
        if (await pRequest(imStore.count(favhash)) == 0)
            await pRequest(imStore.add({ key: favhash,  image: tab.favIconUrl }));  // store mapping of image-hash to image
        if (await pRequest(luStore.count(urlhash)) == 0)
            await pRequest(tuStore.put({ key: urlhash,  favhash: favhash }));       // store mapping of url-hash to image-hash
        await pRequest(luStore.put({ key: favhash,  timestamp: new Date() }));      // store mapping of image-hash to last-use timestamp; garbage collection will use the timestamp.
        return pTransaction(tx).then( () => favhash );
    }

    async function pTxRead(storeNames, pTxProcessor) {
        let db = await pOpenDB();
        let tx = db.transaction(storeNames, "readonly");
        let valueObj = await pTxProcessor(tx);
        await pTransaction(tx);
        return valueObj;
    }

    async function pGetRecord(storeName, key) {
        return pTxRead(storeName, tx => pRequest(tx.objectStore(storeName).get(key)));
    }

    function pGetRecordValue(storeName, key, fieldName) {
        return pGetRecord(storeName, key).then(record => record ? record[fieldName] : null);
    }

    async function pGetFaviconImage(tab) {
        let image = null;
        if (tab.favhash)                // load image using favhash first
            image = await pGetRecordValue("faviconImage", tab.favhash, "image");
        //image = await pGetRecord("faviconImage", tab.favhash).then(res => res ? res.image : null);
        if (!image && tab.favIconUrl)   // next use favIconUrl if it exists
            image = tab.favIconUrl;
        if (!image) {                   // as a last resort do a reverse lookup from tab url to favhash and then load image with it.
            let urlhash = new SparkMD5().append(tab.url).end();
            let favhash = await pGetRecordValue("faviconTabUrl", urlhash, "favhash");
            if (favhash)
                image = await pGetRecordValue("faviconImage", favhash, "image");
        }
        return {tid: tab.id, favIconUrl: image};
    }

    function pGetFaviconLastUse(tab) {
        return pGetRecord("faviconLastUse", tab.favhash).then( lu => ({tid: tab.id, timestamp: (lu ? lu.timestamp : null)}) );
    }

    async function pClearFaviconDb() {
        let db      = await pOpenDB();
        let tx      = db.transaction(["faviconImage", "faviconTabUrl", "faviconLastUse"], "readwrite");
        await pRequest(tx.objectStore("faviconImage").clear());
        await pRequest(tx.objectStore("faviconTabUrl").clear());
        await pRequest(tx.objectStore("faviconLastUse").clear());
        return pTransaction(tx);
    }

    async function pExportFaviconDb() {
        let db      = await pOpenDB();
        let tx      = db.transaction(["faviconImage", "faviconTabUrl", "faviconLastUse"], "readonly");
        let imArray = await pRequest(tx.objectStore("faviconImage").getAll());
        let tuArray = await pRequest(tx.objectStore("faviconTabUrl").getAll());
        let luArray = await pRequest(tx.objectStore("faviconLastUse").getAll());
        let result  = {
            "faviconImage":     await pRequest(tx.objectStore("faviconImage").getAll()),
            "faviconTabUrl":    await pRequest(tx.objectStore("faviconTabUrl").getAll()),
            "faviconLastUse":   await pRequest(tx.objectStore("faviconLastUse").getAll()),
        };
        return pTransaction(tx).then( () => result );
    }

    function validateImportFaviconDb(dbJson) {
        if (!dbJson["faviconImage"]) throw Error("Favicon data 'faviconImage' is not found.");
        if (!dbJson["faviconTabUrl"]) throw Error("Favicon data 'faviconTabUrl' is not found.");
        if (!dbJson["faviconLastUse"]) throw Error("Favicon data 'faviconLastUse' is not found.");
        return dbJson;
    }
    
    async function pImportFaviconDb(dbRecordsJson) {
        let stores  = ["faviconImage", "faviconTabUrl", "faviconLastUse"];
        let db      = await pOpenDB();
        let tx      = db.transaction(stores, "readwrite");
        // TODO: get faviconLastUse first and merge the timestamps.
        return Promise.all( stores.map( table => pBatchPuts(tx.objectStore(table), dbRecordsJson[table]) ) )
            .then(() => pTransaction(tx));
    }

    async function pBatchPuts(store, records) {
        return new Promise(function(resolve, reject) {
            // Sequential batch inserts in IndexedDB have very poor performance if the onsuccess event of each put is handled.
            // Skip handling the onsuccess events for all puts except the last one.
            let req;
            records.forEach( record => req = store.put(record) );
            req.onsuccess   = event => resolve(event.target.result);    // pBatchPuts(...).then( result )
            req.onerror     = event => reject(event.target.error);      // pBatchPuts(...).catch( error )
        });
    }


    // Module export
    module.pOpenDB = pOpenDB;
    module.closeDB = closeDB;
    module.pSaveFaviconImage = pSaveFaviconImage;
    module.pGetFaviconImage = pGetFaviconImage;
    module.pGetFaviconLastUse = pGetFaviconLastUse;
    module.pClearFaviconDb = pClearFaviconDb;
    module.pExportFaviconDb = pExportFaviconDb;
    module.pImportFaviconDb = pImportFaviconDb;
    module.validateImportFaviconDb = validateImportFaviconDb;

    return module;

}(this, "db"));    // Pass in the global scope as 'this' scope.

