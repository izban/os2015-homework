#include "helpers.h"

const int BUFFER_SIZE = 4096;

int main(int argc, const char * argv) {
    char* args[] = {"ls", "/bin", NULL};
    int res = spawn("ls", args);
    
    return 0;
}
