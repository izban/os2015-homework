#ifndef HELPERS_H
#define HELPERS_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

ssize_t read_(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count);
ssize_t read_until(int fd, void *buf, size_t count, char delimeter);
int spawn(const char * file, char * const argv []);
ssize_t read_token(int fd, char delimeter, char** begin, char** end);

#endif
