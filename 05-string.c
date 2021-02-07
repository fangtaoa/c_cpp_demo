#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * 重要思想:
 * 1.引入辅助指针变量
 * 2.辅助指针变量和操作逻辑之间的关系
 * 
 * */

int sub_str_cnt(const char *str, const char *sub_str, int *count)
{
  while(*str != '\0')
  {
    str = strstr(str, sub_str);
    //printf("str: %s\n", str);
    if (str == NULL)
      break;
    else
    {
      (*count)++;
      str+=strlen(sub_str);
    }
  }
  return 0;
}


// 去除字符串首尾的空格, 并返回新的字符串
int trim_space(const char *src, char *dest)
{
  int ret_val = 0;
  char *src_begin_ptr = src;
  char *src_end_ptr = src + strlen(src) -1;
  char *dest_ptr = dest;
  if (src == NULL || dest ==  NULL)
  {
    ret_val = -1;
    printf("func trim_space() error: (src_ptr == NULL || dest_ptr ==  NULL)");
    return ret_val;
  }
  if(*src_begin_ptr != ' ' && *src_end_ptr != ' ') 
  {
    dest = src;
    return ret_val;
  }

  printf("src_begin_ptr: [%s]\n", src_begin_ptr);
  while(*src_begin_ptr++ != '\0')
  {
    if (*src_begin_ptr != ' ')
      break;
  }
  while(*src_end_ptr-- != '\0')
  {
    if(*src_end_ptr != ' ')
      break;
  }
  while (src_begin_ptr != src_end_ptr)
  {
    *dest_ptr++=*src_begin_ptr++;
  } 
  *dest_ptr = *src_end_ptr;
  return ret_val;
}

// 获取偶数位和奇数位的字符串
int get_even_odd_str(const char *str, char *even_str, char *odd_str)
{
  int ret_val = 0, i=0;
  int str_len = strlen(str);
  if (str == NULL ||  even_str == NULL || odd_str == NULL)
  {
    ret_val = -1;
    printf("func get_even_odd_str() error: (str == NULL ||  envn_str == NULL || odd_str == NULL)\n");
    return ret_val;
  }
  for(; i < str_len; i++)
  {
    if(i % 2 != 0)
      *even_str++=str[i];
    else
      *odd_str++ = str[i];
  } 
  
  return ret_val;

}

// 通过key获取对应的value, 并把value中的空格去除
int get_value_by_key(const char *str /*in*/, char *key /*in*/, char *value /*out*/)
{
  int ret_val = 0;
  int i=0;
  if (str == NULL || key == NULL ||  value == NULL)
  {
    ret_val = -1;
    printf("func get_value_by_key() error: (str == NULL || key == NULL ||  value == NULL)\n");
    return ret_val;
  }
  char *str_ptr = str;
  char *key_ptr = NULL;
  char *new_key_ptr = NULL;
  char *value_ptr = value;
  key_ptr = (char*)malloc(100);
  new_key_ptr = (char*)malloc(100);

  while(*str_ptr != '=')
  {
    key_ptr[i] = *str_ptr;
    i++;
    str_ptr++;
  } 
  printf("key ptr: [%s]\n", key_ptr);
  // ret_val = trim_space(key_ptr, new_key_ptr); 
  strcpy(new_key_ptr, key_ptr); 
  printf("new key: [%s]\n", new_key_ptr);
  if (ret_val != 0)
  {
    printf("func get_value_by_key() error: %d\n", ret_val);
    return ret_val;
  }
  
  ret_val = strcmp(new_key_ptr, key);
  if (ret_val != 0)
  {
    printf("func get_value_by_key() error: %s != %s\n", new_key_ptr, key);
    return ret_val;
  }

  ret_val = trim_space(str_ptr++, value);
  if (ret_val != 0)
  {
    printf("func get_value_by_key() error: value is not found by [%s]\n", key);
    return ret_val;
  }

  free(key_ptr); 
  free(new_key_ptr); 
  key_ptr=NULL;
  new_key_ptr=NULL;

  return ret_val;

}
int main()
{
    int count=0;
    int ret = 0;
    char *str = "abcd11123abcd22223abcd";
    char *sub_str="abcd";
    printf("==========sub_str_cnt()=======\n");
    printf("str: [%s]\n", str);
    printf("sub_str: [%s]\n", sub_str);
    ret = sub_str_cnt(str, sub_str, &count);
    if (ret == 0)
        printf("count: %d\n", count);

    printf("\n=========trim_space()===========\n"); 

    char *str2 = "      abcde dkafjkdaf dajkff      ";
    char *dest = NULL;
    dest = (char*)malloc(100);
    ret = trim_space(str2, dest);
    if (ret == 0)
    {
      printf("dest: [%s]\n",  dest);
    }

    printf("\n========get_even_odd_str()============\n"); 

    char *str3="a1a1a1a1a1";
    char *even_str = NULL;
    char *odd_str = NULL;
    even_str = (char*)malloc(10);
    odd_str = (char*)malloc(10);

    ret = get_even_odd_str(str3, even_str, odd_str); 
    if (ret == 0)
      printf("str: [%s]\neven_str: [%s]\nodd_str: [%s]\n", str3, even_str, odd_str);
    

    printf("\n========get_value_by_key()============\n"); 
    char *str4 = "key1=value1";
    char *key = "key1";
    char *value = NULL;
    value = (char*)malloc(32);
    
    ret = get_value_by_key(str4, key, value);
    if (ret == 0)
      printf("str: [%s], key: [%s], value: [%s]\n", str4, key, value);

    free(dest);
    free(even_str);
    free(odd_str);
    free(value);

    dest=NULL;
    even_str=NULL;
    odd_str=NULL;
    value=NULL;
}





