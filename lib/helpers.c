#include "helpers.h"

ssize_t read_(int fd, void *buf, size_t count) {
	ssize_t processed = 0;
	while (processed < count) {
		ssize_t readed = read(fd, buf + processed, count - processed);
		if (readed < 0) {
			return -1;
		}
		if (readed == 0) {
			break;
		}
		processed += readed;
	}
	return processed;
}

ssize_t write_(int fd, const void *buf, size_t count) {
	ssize_t processed = 0;
	while (processed < count) {
		ssize_t writed = write(fd, buf + processed, count - processed);
		if (writed < 0) {
			return -1;
		}
		processed += writed;
	}
	return processed;
}
