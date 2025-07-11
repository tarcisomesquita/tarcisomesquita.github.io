#ifndef CONF_H
#define CONF_H

#include "types.h"

void set_defaults(struct config *);
void set_vh_defaults(struct vhost *);
void open_logs(struct config *);
void close_logs(struct config *);
void free_config(struct config *);
void free_vh_config(struct vhost *);

#endif /* CONF_H */
