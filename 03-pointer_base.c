#include <stdio.h>
#include <stdlib.h>


int main()
{
  int a = 6, b=0;
  int *p = &a; // 指针p指向a, a的地址给赋值到p
  printf("&a: %d, &p: %d\n", &a, p); 
  printf("a: %d, b: %d\n", a, b);
  *p = 10; // *p在=的左边, *p去间接修改a的值
  b = *p; // *p在=的右边, 从p指向的内存空间中读取数据赋值给b
  printf("a: %d, b: %d\n", a, b);
 
}
