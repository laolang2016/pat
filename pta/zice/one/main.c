#include<stdio.h>
 
int levels( int n , int * val);
 
void print( int level_num ,char ch);
 
int main(void){
 
  int val = 0;
  int n = 0;
  int level = 0;
  int * pval = &val;
  char ch = '\0';
  scanf("%d %c",&n,&ch);
  level = levels(n,pval);
  print(level,ch);
  printf("%d\n",val);
 
  return 0;
}
 
int levels( int n , int * val ){
  int level_num = 1;
  int test = ( level_num * level_num ) * 2 - 1;
  //  printf("test = %d\n",test);
   
   
  while(  test <= n  ){
    level_num++;
    test = ( level_num * level_num ) * 2 - 1;
    //test = level_num * level_num - 1;
    //    printf("test = %d\n",test);
  }
   
  level_num--;
   
  *val = n - (( level_num * level_num ) * 2 - 1);
  //  printf("level_num = %d\n",level_num);
   
   
  //  printf("test = %d\n",test);
  level_num = level_num * 2 - 1;
   
 
  return level_num;
}
 
void print( int level_num , char ch){
  //输出上半部分
  //  char ch = '*';
  int space_num = 0;
  int i = 1;
  int ch_num = 0;
  int level  = ( level_num + 1 ) / 2;
  for( i = 1; i <= level; i++ ){
    //输出空格
    space_num = i - 1;
    while( space_num > 0 ){
      putchar(' ');
      space_num--;
    }
 
    //输出符号
    ch_num = level_num - ( i - 1 ) * 2;
    while( ch_num > 0 ){
      putchar(ch);
      ch_num--;
    }
 
    putchar('\n');
  }
  //  puts("-------");
 
  //输出下半部分
  level = ( level_num - 1 ) / 2;
  ch_num = 3;
  i = 0;
  for( i = 0; i < level; i++ ){
    //输出空格
    space_num = level - 1 - i;
    while( space_num > 0 ){
      putchar(' ');
      space_num--;
    }
 
    //输出符号
    int j = 1;
    for( j = 1; j <= ch_num; j++ ){
      putchar(ch);
    }
   
    ch_num += 2;
   
    putchar('\n');
  }
}


