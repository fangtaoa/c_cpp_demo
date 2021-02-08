#include <stdio.h>


int arr1[100];
int arr2[100];

void f1(int *ptr)
{
  ptr[1] = 3;
  *ptr = 3;
  printf("ptr[0]: [%d], ptr[1]: [%d]\n", ptr[0], ptr[1]);
  ptr = arr2;
  printf("ptr[0]: [%d], ptr[1]: [%d]\n", ptr[0], ptr[1]);

}

void f2(int arr[])
{
  arr[1] = 3;
  *arr = 3;
  printf("arr[0]: [%d], arr[1]: [%d]\n", *arr, *arr++);
  arr = arr2; // arr实际是一个指针
  printf("arr[0]: [%d], arr[1]: [%d]\n", *arr, *arr++);

}

void main()
{

  arr1[1] = 3;
  *arr1 = 3;
  //arr1++; // lvalue required as increment operand
  //arr1 = arr2; // compiler error: assignment to expression with array type
  f1(arr1);
  f2(arr1);

}
