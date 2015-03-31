#include "bufio.h"
#include <memory.h>
#include <stdlib.h>

struct buf_t *buf_new(size_t capacity) {
    struct buf_t *res = (struct buf_t*)malloc(sizeof(struct buf_t));
    if (res == NULL) return NULL;
    res->capacity = capacity;
    res->size = 0;
    res->data = (char*)malloc(sizeof(char) * capacity);
    if (res->data == NULL) {
        free(res);
        return NULL;
    }
    return res;
}

void buf_free(struct buf_t *buf) {
    my_assert(buf != NULL);
    free(buf->data);
    free(buf);
}

size_t buf_capacity(struct buf_t *buf) {
    my_assert(buf != NULL);
    return buf->capacity;
}

size_t buf_size(struct buf_t *buf) {
    my_assert(buf != NULL);
    return buf->size;
}

ssize_t buf_fill(int fd, struct buf_t *buf, size_t required) {
    my_assert(buf != NULL);
    my_assert(required <= buf->capacity);
    buf->size = 0;
    while (buf->size < required) {
        ssize_t readed = read(fd, buf->data + buf->size, required - buf->size);
        if (readed < 0) return -1;
        if (readed == 0) break;
        buf->size += readed;
    }  
    return buf->size;
}

ssize_t buf_flush(int fd, struct buf_t *buf, size_t required) {
    my_assert(buf != NULL);
    ssize_t writed = 0;
    while (writed < required) {
        ssize_t cur_writed = write(fd, buf->data + writed, buf->size - writed);
        if (cur_writed < 0) return -1;
        if (cur_writed == 0) break;
        writed += cur_writed;
    }
    memmove(buf->data, buf->data + writed, buf->size - writed);
    buf->size -= writed;
    return writed;
}
