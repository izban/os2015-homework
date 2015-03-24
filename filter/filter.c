#include "helpers.h"

const int BUFFER_SIZE = 4096;

#include <stdio.h>

int main(int argc, char * argv[]) {
    int i;
    char *a[argc + 1];
    for (i = 1; i < argc; i++) a[i - 1] = argv[i];
    a[argc - 1] = NULL;
    while (1) {
        char *begin, *end;
        ssize_t len = read_token(STDIN_FILENO, '\n', &begin, &end);
        if (len == 0) return 0;
        if (len < 0) return 1;
        char buf[len + 1];
        for (i = 0; i < len; i++) buf[i] = *(begin++);
        buf[len] = 0;
        a[argc - 1] = buf;
        a[argc] = NULL;
        int res = spawn(a[0], a);
        if (res == 0) {
            buf[len] = '\n';
            write_(STDOUT_FILENO, buf, len + 1);
        }
    }   
}
