#include<stdio.h>

typedef struct{
  int *a;
  float b;
} T;  

void g(T *q);
float f() { 
  T p;
  p.a = NULL;
  g(&p);
  return p.b; 
}

void h(int *r);
void g(T *q) {
  int *t = q->a;
  float fl = q->b;
  if (fl > 0.0) {
    q->b = 2.0;
  }
  else {
    q->b = 3.0;
  }
    
    
  h(t);
}

void h(int *r) {
  *r = 0; // crash!!
}

int main() {
  float val = f();
  printf("%f\n", val);
  return 0;
}
