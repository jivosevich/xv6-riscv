#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/riscv.h"

int
main(int argc, char *argv[])
{

  char *start = sbrk(0);
  sbrk(PGSIZE);
  *start=100;
  mprotect(start, 1) ;
  int child=fork();

  if(child==0){
        printf("Valor protegido = %d\n", *start);   
        munprotect(start, 1) ;  
        *start=5;
        printf("Después de desproteger el valor pasó a ser = %d\n", *start); 
        exit(0);
  }
  else if(child>0){
        wait(0);
        printf("\nTe capturé, ahora\n"); 
        *start=5; 
        printf("\nEsta declaración no se imprimirá.\n");
        exit(0); 
  } 

 return 0;
}