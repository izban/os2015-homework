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

ssize_t read_until(int fd, void *buf, size_t count, char delimeter) {
	ssize_t processed = 0;
	char was_delimeter = 0;
	while (processed < count && !was_delimeter) {
		ssize_t readed = read(fd, buf + processed, count - processed);
		if (readed < 0) {
			return -1;
		}
		if (readed == 0) {
			break;
		}
		int i;
		for (i = 0; i < readed; i++) {
			was_delimeter |= ((char*)buf)[processed + i] == delimeter;
		}
		processed += readed;
	}
	return processed;
}

int spawn(const char * file, char * const argv []) {
    int pid = fork();    
    if (pid == 0) {
        if (execvp(file, argv) == -1) {
            return -1;
        }
        return 0;
    } else {
        int status;
        return waitpid(pid, &status, 0); 
    }
}
