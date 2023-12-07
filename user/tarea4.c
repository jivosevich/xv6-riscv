#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"

void manipulateFile(const char *file, int custom_mode) {
    int fd = open(file, O_CREATE);

    int result = chmod(file, custom_mode);
    if (result < 0) {
        printf("Error al modificar los permisos del archivo: %d\n", result);
        exit(1);
    }

    fd = open(file, O_WRONLY);
    if (fd < 0) {
        printf("Error al abrir el archivo: %d\n", fd);
        exit(1);
    }

    printf("El archivo se manipuló correctamente\n");

    close(fd);
}

int main(int argc, char *argv[]) {
    const char *custom_file = argv[1];
    int custom_mode = atoi(argv[2]);

    manipulateFile(custom_file, custom_mode);

    exit(0);
}