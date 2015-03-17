#include "helpers.h"

const int BUFFER_SIZE = 4096;

void swap(char *a, char *b) {
	char c = *a;
	*a = *b;
	*b = c;
}

void reverse(char *buf, int l, int r) {
	int i;
	for (i = l; i < r - i + l; i++) {
		swap(&buf[i], &buf[r - i + l]);
	}
}

int main() {
	char buf[BUFFER_SIZE];
	int cur_ptr = 0, i;
	while (1) {
		ssize_t readed;
		readed = read_until(STDIN_FILENO, buf + cur_ptr, BUFFER_SIZE - cur_ptr, ' ');
		if (readed < 0) {
			break;
		}
		if (readed == 0) {
			reverse(buf, 0, cur_ptr - 1);
			write_(STDOUT_FILENO, buf, cur_ptr);
			break;
		}
		int last_space = -1;
		for (i = cur_ptr; i < cur_ptr + readed; i++) {
			if (buf[i] == ' ') {
				reverse(buf, last_space + 1, i - 1);
				write_(STDOUT_FILENO, buf + last_space + 1, i - last_space);
				last_space = i;
			}
		}
		if (last_space != -1) {
			for (i = last_space + 1; i < cur_ptr + readed; i++) {
				buf[i - last_space - 1] = buf[i];
			}
			cur_ptr = cur_ptr + readed - last_space - 1;
		} else {
			cur_ptr += readed;
		}
	}

	return 0;
}
