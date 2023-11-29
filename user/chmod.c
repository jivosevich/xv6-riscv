#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf(2, "Usage: chmod <filename> <mode>\n");
        exit();
    }

    char *filename = argv[1];
    int mode = atoi(argv[2]);

    if (chmod(filename, mode) < 0) {
        printf(2, "chmod failed\n");
    }

    exit();
}