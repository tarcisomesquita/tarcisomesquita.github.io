


/* Opens the log files */
void open_logs(struct config *conf)
{
    struct vhost *vhlp;
    int temp_fd;

    for (vhlp = conf->vhl; vhlp != NULL && vhlp->name != NULL; vhlp = vhlp->next) {
	/* Check if we are fully configured, abort if not the case */
	if (vhlp->log_ok == NULL) {
	    (void) fprintf(stderr,
			   "It seems you neglected to indicate where"
			   " I should write/open the access log file for vhost %s\n",
			   vhlp->name);
	    abort();
	} else if (vhlp->log_err == NULL) {
	    (void) fprintf(stderr,
			   "It seems you neglected to indicate where"
			   " I should write/open the error log file for vhost %s\n",
			   vhlp->name);
	    abort();
	}

	/* If the logfiles aren't opened, open them, abort if we can't open it */
	if (vhlp->log_fd_ok == NULL && 
		((temp_fd = open(vhlp->log_ok, 
			O_WRONLY | O_SYNC | O_CREAT | O_APPEND,"r")) > 0) && 
		(vhlp->log_fd_ok = fdopen(temp_fd, "a")) == NULL) {
	    DEBUG_OUT2
		("Couldn't open logfile %s, with the following reason:\n",
		 vhlp->log_ok);
	    perror("open()");
	    abort();
	} else if (!conf->use_large_access_log_buffer) {
	    setlinebuf(vhlp->log_fd_ok);
	}

	/* Same here */
	if (vhlp->log_fd_err == NULL && 
		((temp_fd = open(vhlp->log_err, 
			O_WRONLY | O_SYNC | O_CREAT | O_APPEND,"r")) > 0) && 
		(vhlp->log_fd_err = fdopen(temp_fd, "a")) == NULL) {
	    DEBUG_OUT2
		("Couldn't open logfile %s, with the following reason:\n",
		 vhlp->log_err);
	    perror("open()");
	    abort();
	} else {
	    setlinebuf(vhlp->log_fd_err);
	}
    }
}

/* Closes the log fds if nessecairy */
void close_logs(struct config *conf)
{
    struct vhost *vhlp;
#ifndef RELEASE
    if (debug)
	DEBUG_OUT("Flushing logs..\n");
#endif
    for (vhlp = conf->vhl; vhlp != NULL; vhlp = vhlp->next) {
	if (vhlp->log_fd_ok != NULL)
	    if (fclose(vhlp->log_fd_ok))
		perror("closing access log");
	if (vhlp->log_fd_err != NULL)
	    if (fclose(vhlp->log_fd_err))
		perror("Closing error log");
    }
}

/* Clears the config struct */
void free_config(struct config *conf)
{
    struct vhost *vhlp;

    for (vhlp = conf->vhl; vhlp != NULL; vhlp = vhlp->next) 
	free_vh_config(vhlp);
    free(conf->user);
    free(conf->jail_root);
    free(conf->php_bin);
    free(conf->perl_bin);
    free(conf->mime_file);
    free(conf->default_mime_type);
    free(conf->bind_addr);
}

void free_vh_config(struct vhost *vh)
{
    free(vh->doc_base);
    free(vh->index_doc);	
    free(vh->log_ok);
    free(vh->log_err);
}
