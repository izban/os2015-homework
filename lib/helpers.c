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

// use [begin..end] before next reading!
ssize_t read_token(int fd, char delimeter, char** begin, char** end) {
    static char buf[4096];
    static ssize_t sz = 0, ptr = 0;
    while (ptr < sz && buf[ptr] == delimeter) ptr++;
    if (ptr == sz) {
        sz = read_until(fd, buf, 4096, delimeter);
        ptr = 0;
    }
    if (sz <= 0) return sz;
    *begin = buf + ptr;
    while (ptr < sz && buf[ptr] != delimeter) ptr++;
    *end = buf + ptr;
    return *end - *begin;
}

int spawn(const char * file, char * const argv []) {
    //int i;
    //printf("%s\n", file);
    //for (i = 0; argv[i]; i++) printf("%s\n", argv[i]);

    int status = 0;
    pid_t pid = fork();    
    if (pid == -1) return -1;
    if (pid == 0) {
        int result = execvp(file, argv);
        //printf("%s: %d\n", file, result);
        if (result < 0) {
            _exit(-1);
        }
        _exit(0);
    } else {
        pid_t o = waitpid(pid, &status, 0);
        //printf("smth: %d, %d\n", o, status);
        if (o < 0) return -1;
        //printf("%d %d\n", WIFEXITED(status), WEXITSTATUS(status));
        //if (!WIFEXITED(status) || WEXITSTATUS(status) == 255) return -1;
        if (status != 0) return -1;
        return 0; 
    }
}
