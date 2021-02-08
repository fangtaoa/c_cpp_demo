#include <stdio.h>


int print_array(char **p_array, int len)
{
  int i =0, ret_val=0;
  if (p_array == NULL)
  {
    ret_val = -1;
    return ret_val;
  }
  for(i=0; i<len; i++)
    // printf("array item [%d]: [%s]\n", i, *(p_array+i));
    printf("array item [%d]: [%s]\n", i, p_array[i]);

  return ret_val;
}

int sort_array(char **p_array, int len)
{
  int i=0, j=0;
  char *p_tmp = NULL;
  for(; i<len; i++)
  {
    for(j=i+1; j<len; j++)
    {
      if(strcmp(p_array[i], p_array[j]) > 0)
      {
        p_tmp = p_array[i];
        p_array[i] = p_array[j];
        p_array[j] = p_tmp;
      }
    }

  }
}


int split_str(const char *str, char **p_array, int *rows)
{
  int i =0;
  char *str_ptr = str;
  char *tmp_ptr = str;
  
  while(*str_ptr!= '\0')
  {
    if (*str_ptr == ',')
    {
      p_array[i] = (char*)malloc(str_ptr-tmp_ptr);      
      strncpy(p_array[i], tmp_ptr, str_ptr-tmp_ptr); 
      tmp_ptr=++str_ptr;
      i++;
    } 
    str_ptr++;
  }
  p_array[i] = (char*)malloc(str_ptr-tmp_ptr);
  strncpy(p_array[i], tmp_ptr, str_ptr-tmp_ptr);
  *rows = ++i;
}

void main()
{
  int i=0,ret=0;
  // 1. 二级指针的第1种内存模型
  char *buf1[] = {"aaaa", "cccc", "ddddd", "eeee", "bbbb"};
  // 2. 二级指针的第2种内存模型
  char buf2[10][30] = {0};
  // 3. 二级指针的第3种内存模型
  char **buf3 = (char**)malloc(5*sizeof(100));
  char *str="aaa,bbbb,cccc,dddd";
  int rows=0;
  ret =split_str(str, buf3, &rows);

  print_array(buf3, rows); 
  printf("rows: %d\n", rows);
  for (i=0;i<rows;i++)
  {
    if(buf3[i] != NULL)
    {
      free(buf3[i]);
      buf3[i]=NULL;
    }
  }
  free(buf3);
  buf3=NULL;

}

