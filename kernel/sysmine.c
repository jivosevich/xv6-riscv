#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"

int ancestor(int gen) {
  struct proc *p = myproc();
  int pid = p->pid;
  int counter = 0;

  while (p != 0 && counter < gen ) {
    p = p->parent;
    counter += 1;
  }

  if (p != 0) {
    pid = p->pid;
  } else {
    pid = -1;
  }
  return pid;
}

uint64
sys_ancestor(void)
{
  int gen;
  argint(0, &gen);
  return ancestor(gen);
}