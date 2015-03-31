#include "bufio.h"

const int BUFFER_SIZE = 4096;

int main() {
	struct buf_t *buf = buf_new(BUFFER_SIZE);

        int code = 0;
	while (1) {
		ssize_t readed = buf_fill(STDIN_FILENO, buf, 1);
		if (readed < 0) {
                    code = -1;
                    break;
                }
                if (readed == 0) break;
                ssize_t writed = buf_flush(STDOUT_FILENO, buf, buf_size(buf));
                if (writed < 0) {
                    code = -1;
                    break;
                }
                if (writed == 0) break;        
	}
        buf_free(buf);
	return 0;
}
