#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int get_mem(char **p_array, int *nums)
{
  int ret_val = 0;
  if (p_array != NULL)
  {
   ret_val = -1;
   printf("func get_mem() error: (p_array != NULL)\n"); 
   return ret_val;
  }
  if (nums == NULL)
  {
   ret_val = -1;
   printf("func get_mem() error: (nums == NULL)\n"); 
   return ret_val;
  }

  p_array = (char**)malloc(100*sizeof(char*));
  return ret_val; 
}

int free_mem(char **p_array, int *nums)
{
  int i = 0, ret_val = 0;
  if (p_array == NULL)
  {
    ret_val = -1;
    printf("func free_mem() error: if (p_array == NULL)\n");
    return ret_val;
  }
  if (nums == NULL)
  {
    ret_val = -1;
    printf("func free_mem() error: if (nums == NULL)\n");
    return ret_val;
  }
  if(p_array != NULL)
  {
    for(i=0; i<*nums; i++)
    {
      free(p_array[i]);
      p_array[i] = NULL;
    }
    free(p_array);
    p_array = NULL;
  }
  return ret_val;

}


int split_str(const char *str, char **p_array, char ch, int *rows)
{
  int i =0, ret_val=0;
  char *str_ptr = str;
  char *tmp_ptr = str;
  if (str == NULL)
  {
    ret_val = -1;
    printf("func split_str() error: (str == NULL)");
    return ret_val;
  }
  
  if (str_ptr == NULL)
  {
    ret_val = -1;
    printf("func split_str() error: (str_ptr == NULL)");
    return ret_val;
  }
  if (tmp_ptr == NULL)
  {
    ret_val = -1;
    printf("func split_str() error: (tmp_ptr == NULL)");
    return ret_val;
  }
  while(*str_ptr != '\0')
  {
    if (*str_ptr == ch)
    {
      p_array[i] = (char*)malloc(str_ptr-tmp_ptr);      
      strncpy(p_array[i], tmp_ptr, str_ptr-tmp_ptr); 
      tmp_ptr=++str_ptr;
      i++;
    } 
    str_ptr++;
  }
  if (strlen(tmp_ptr) != 0)
  {
    p_array[i] = (char*)malloc(str_ptr-tmp_ptr);
    strncpy(p_array[i], tmp_ptr, str_ptr-tmp_ptr);
    *rows = ++i;
  } else
  {
    *rows = i;
  }
  return ret_val;

}

int main()
{
  int i=0,ret=0;
  // 1. 二级指针的第1种内存模型
  char *buf1[] = {"aaaa", "cccc", "ddddd", "eeee", "bbbb"};
  // 2. 二级指针的第2种内存模型
  char buf2[10][30] = {0};
  // 3. 二级指针的第3种内存模型
  char **buf3 = (char**)malloc(100*sizeof(char *));
  char *str="aaa,bbbb,cccc,dddd,e";
  int rows=0;
  char ch = ',';
  ret =split_str(str, buf3, ch, &rows);
  if(ret != 0)
  {
    printf("func split_str() error: %d\n", ret);
    // return ret;
    goto end;

  }
  print_array(buf3, rows); 
  printf("rows: %d\n", rows);
  // for (i=0;i<rows;i++)
  // {
  //   if(buf3[i] != NULL)
  //   {
  //     free(buf3[i]);
  //     buf3[i]=NULL;
  //   }
  // }
  // ret = free_mem(buf3, &rows);
  // return ret;
  goto end;

end:
  ret = free_mem(buf3, &rows);
  if (ret != 0)
  {
    printf("func free_mem() error: %d\n", ret);
    return ret;

  }
}

