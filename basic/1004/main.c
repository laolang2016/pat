/*

2015/10/17 09:52:01

1004. 成绩排名

读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。

输入格式：每个测试输入包含1个测试用例，格式为

  第1行：正整数n
  第2行：第1个学生的姓名 学号 成绩
  第3行：第2个学生的姓名 学号 成绩
  ... ... ...
  第n+1行：第n个学生的姓名 学号 成绩

其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。

输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
输入样例：

3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95

输出样例：

Mike CS991301
Joe Math990112

*/




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


struct __student{
  char name[ 25 ];
  char num[ 25 ];
  int score;
};

typedef struct __student _student;

int main( void ){

  _student stuhigh;
  _student stulow;
  stuhigh.score = -1;
  stulow.score = 101;
  _student t;

  int N = 0;

  scanf( "%d",&N );

  while( N-- ){
    scanf( "%s",t.name );
    scanf( "%s",t.num );
    scanf( "%d",&t.score );

    if( t.score > stuhigh.score ){
      strcpy( stuhigh.name,t.name );
      strcpy( stuhigh.num,t.num );
      stuhigh.score = t.score;
    }

    if( t.score < stulow.score  ){
      strcpy( stulow.name,t.name );
      strcpy( stulow.num,t.num );
      stulow.score = t.score;
    }

      
  }

  printf( "%s %s\n",stuhigh.name,stuhigh.num );
  printf( "%s %s\n",stulow.name,stulow.num );
    
  
  return 0;
}
