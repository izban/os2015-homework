#ifndef BUFIO_H 
#define BUFIO_H

#include <unistd.h>
#include <sys/types.h>

#ifdef DEBUG
#define my_assert(x) if (!(x)) abort()
#else
#define my_assert(x)
#endif

struct buf_t {
    char* data;
    size_t capacity;
    size_t size;    
};

struct buf_t *buf_new(size_t capacity);
void buf_free(struct buf_t *);
size_t buf_capacity(struct buf_t *);
size_t buf_size(struct buf_t *);
ssize_t buf_fill(int fd, struct buf_t *buf, size_t required);
ssize_t buf_flush(int fd, struct buf_t *buf, size_t required);

#endif
