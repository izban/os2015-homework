#include "helpers.h"

const int BUFFER_SIZE = 4096;

int main() {
	char buf[BUFFER_SIZE];
	while (1) {
		ssize_t readed;
		readed = read_(STDIN_FILENO, buf, BUFFER_SIZE);
		if (readed <= 0) {
			break;
		}
		write_(STDOUT_FILENO, buf, readed);
	}

	return 0;
}
