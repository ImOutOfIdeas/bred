#ifndef __BRED_H__
#define __BRED_H__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define BUFSIZE 2048

typedef struct bred bred;

bred *bred_create();
void bred_enable_raw_mode();
void bred_disable_raw_mode();
int bred_open_file(char* buf, long size, char *filepath);
void bred_set_cursor(unsigned int y, unsigned int x);
void bred_get_curosr(unsigned int *y, unsigned int *x);
void bred_clear();

#endif // __BRED_H__
