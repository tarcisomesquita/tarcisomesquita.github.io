const { Builder, By, Key, until } = require('selenium-webdriver');
require('geckodriver'); // Isso inicializa o GeckoDriver automaticamente

async function exemploSimplesWebDriverFirefoxJs() {
    let driver;

    try {
        console.log("Inicializando o WebDriver para o Firefox...");
        driver = await new Builder().forBrowser('firefox').build();

        console.log("Navegando para o Google com Firefox...");
        await driver.get('https://www.google.com');
        await driver.sleep(2000); // Pausa de 2 segundos para ver a página carregar

        // 3. Encontra a barra de pesquisa pelo seu atributo 'name'
        console.log("Encontrando a barra de pesquisa...");
        const searchBox = await driver.findElement(By.name('q'));
        await driver.sleep(1000);

        // 4. Digita um texto na barra de pesquisa
        console.log("Digitando 'Automação Selenium JavaScript Firefox'...");
        await searchBox.sendKeys('Automação Selenium JavaScript Firefox');
        await driver.sleep(2000);

        // 5. Pressiona Enter para realizar a busca
        console.log("Pressionando Enter para buscar...");
        await searchBox.sendKeys(Key.RETURN);
        await driver.sleep(3000); // Pausa de 3 segundos para ver os resultados

        console.log("Busca realizada com sucesso!");

    } catch (error) {
        console.error(`Ocorreu um erro: ${error}`);
    } finally {
        // 6. Fecha o navegador
        if (driver) {
            console.log("Fechando o navegador Firefox...");
            await driver.quit();
            console.log("Exemplo com Firefox concluído.");
        }
    }
}

// Chama a função para executar o exemplo
exemploSimplesWebDriverFirefoxJs();
