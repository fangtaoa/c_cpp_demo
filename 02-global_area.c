#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* get_str1()
{
  char *p = "abc";
  return p;

}

char* get_str2()
{
  char *p = "abc";
  return p;

}


char *get_str3()
{
  char buf[20];
  memset(buf, 0, sizeof(buf));
  strcpy(buf, "abc");
  return buf;

}

int main()
{
  char *p1 = NULL;
  char *p2 = NULL;
  char *buf = NULL;
  p1 = get_str1();
  p2 = get_str2();
  buf = get_str3();
  printf("&p1: %d\n", p1);
  printf("p1: %s\n", p1);
  printf("&p2: %d\n", p2);
  printf("p2: %s\n", p2);
  printf("&buf: %d\n", buf);
  printf("buf: %s\n", get_str3());

}
