#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
  char *p, *p_head = NULL;
  p_head = p = (char*)malloc(100);
  strcpy(p, "1234567890");

  p = p+3; // 修改指针指向
  *p = 'a';
  printf("p: %s\n", p);
  free(p_head); // 释放的内存空间必须是通过首地址
  p_head=NULL;
  p=NULL;

  printf("p: %s\n", p);
}
