#include <stdio.h>
typedef struct node {
  int *fn; 
} T;

void h(int *r) {
  *r = 3; // crash
}

void g (T*q) {
  int *t = q->fn;
  h(t);
}

void f() {
  T p;
  T q2;
  p.fn = NULL; // blame point
  q2.fn = NULL;
  g(&p);
}

int main() {
 f();
 return 0;
}