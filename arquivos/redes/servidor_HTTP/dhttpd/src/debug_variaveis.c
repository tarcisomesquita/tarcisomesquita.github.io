
    conf->port = 80;
    conf->backlog = 10; 
timeout
loop_child
    conf->script_pool = 10;
    conf->cache_size = 32;
    conf->max_cache_age = 60;
    conf->do_fork = 1;


    /* Request some space */

    MALLOC(conf->user, MAX_STR_LENGTH);

    conf->jail_root = malloc(256);
    memset(conf->jail_root, 0, 256);
    MALLOC(conf->jail_root, MAX_STR_LENGTH);
conf->config_file = NULL;
    MALLOC(conf->php_bin, MAX_STR_LENGTH);
    MALLOC(conf->perl_bin, MAX_STR_LENGTH);
    MALLOC(conf->mime_file, MAX_STR_LENGTH);
    MALLOC(conf->default_mime_type, MAX_STR_LENGTH);
    MALLOC(conf->bind_addr, MAX_STR_LENGTH);

conf->vhl->name
conf->vhl->doc_base,
conf->vhl->index_doc;
conf->vhl->log_type;
conf->vhl->log_ok,
conf->vhl->log_err;
conf->vhl->log_fd_ok
conf->vhl->log_fd_err;
conf->vhl->next->

    conf->use_large_access_log_buffer =
    conf->php_available = 
    conf->perl_available = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

debug = 0

NONE = 0
GLOBAL = 1
VHOST = 2
QOS = 3

