#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc > 1) {
        int gen = atoi(argv[1]);
        int pid = ancestor(gen);
        if (pid != -1) {
            printf("Ancestro anterior %d tiene PID: %d\n", gen, pid);
        } else {
            printf("No hay tantos ancestros anteriores!\n");
        }
    } else {
        printf("Debe ingresar un numero de ancestro anterior!\n");
        exit(-1);
    }
    return 0;
}