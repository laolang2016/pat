/*

给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。
字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多余的空格。

输出格式：每个测试用例的输出占一行，输出倒序后的句子。
输入样例：

Hello World Here I Come

输出样例：

Come I Here World Hello


*/



#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int str_sub_reverse( char * str, int begin, int end );
/**
 * @brief 将字符串中间的空白字符压缩为一个空格，并返回新的字符串
 *
 * @pre 字符串两人边不能有空白字符
 * @param 要处理的字符串
 *
 * @return 返回连续空白转换为一个空格的字符串
 *
 */
char * str_constrict_space( char * str );


/**
 * @brief 将字符串两人边的空白字符删除，并返回一个新的字符串
 *
 * @param str 要处理的字符串
 * 
 * @return 返回删除两边空白字符的新字符串
 */
char * str_trim(  char * str );

/**
 * @brief 检测字符串是只包含空白字符
 *
 */
int str_is_space( char * str );

int str_chr_count( char * str, char ch );

int main( void ){
  char strr[ 80 ];
  fgets( strr,80,stdin );
  strr[ strlen( strr ) - 1 ] = '\0';
  char * str = strr;

  int count = str_chr_count( strr,' ' );
  if( strlen(strr) == count  ){
    return 0;
  }


  str = str_trim( str );
  str = str_constrict_space( str );

  count = str_chr_count( str,' ' );
  if(  0 == count  ){
    printf( "%s\n",str);
    return 0;
  }

      str_sub_reverse( strr,0,strlen( strr ) - 1 );

  
  int i = 0;
  int len = strlen( str );
  char ch = ' ';
  int j = i;




  i = 0;
  while( i < len ){
    j = i;
    ch = str[ j ];
    while( ' ' != ch && j < len ){
      ch = str[ j ];
      j++;
    }

    if(  j >= len ){
      break;
    }

    str_sub_reverse( str,i,j-2 );
    i = j;
  }
  
  i = strlen( str ) - 1;
  while( ' ' != str[ i-- ]) ;
  str_sub_reverse( str,i+2,strlen( str ) - 1 );

  str_sub_reverse( str,0,strlen( str ) - 1 );
  printf( "%s\n",str );
  //  printf( "Hello World!\n小代码！\n" );
  return 0;
}

int str_sub_reverse( char * str, int begin, int end ){
  int len = ( begin + end ) / 2 ;
  char ch = ' ';

  while(  begin <= len ){
    ch = str[ begin ];
    str[ begin ] = str[ end ];
    str[ end ] = ch;
    
    begin++;
    end--;
  }

  return 0;
}


/**
 * @brief 将字符串中间的空白字符压缩为一个空格，并返回新的字符串
 *
 * @pre 字符串两人边不能有空白字符
 * @param 要处理的字符串
 *
 * @return 返回连续空白转换为一个空格的字符串
 *
 */
char * str_constrict_space( char * str ){
  int str_len = strlen( str );
  char * t = ( char* )malloc( sizeof( str_len ) * str_len );
  int i = -1;
  int j = 0;
  while( i++ < str_len  ){
    if( !isspace( str[ i ] ) ){
      t[ j++ ] = str[ i ];
    }else{
      if( !isspace( str[ i+1 ] ) ){
    t[ j++ ] = ' ';
      }
    }
  }
  t[ j ] = '\0';
  return t;
}

/**
 * @brief 将字符串两人边的空白字符删除，并返回一个新的字符串
 *
 * @param str 要处理的字符串
 * 
 * @return 返回删除两边空白字符的新字符串
 */
char * str_trim(  char * str ){
  int str_len = strlen( str );
  int begin = 0;
  int end = str_len - 1;
  int i = 0;
 
  while( isspace( str[ begin++ ] ) ) ;
  begin--;
  while( isspace( str[ end-- ] ) ) ;
  end++;
 
  char *t = ( char* )malloc( sizeof( char )*( end - begin + 2 ) );
  i = 0;
  while( begin <= end && ( t[ i++ ] = str[ begin++ ] )) ;
  t[ i ] = '\0';
     
  return t;
}

int str_is_space( char * str ){

  int len = strlen( str );
  int i = 0;
  while( i < len ){
    if( isspace( str[ i ] )){
      i++;
    }
  }
  if( i >= len ){
    return 0;
  }else{
    return 1;
  }
}

int str_chr_count( char * str, char ch ){
  int count = 0;
  int i = 0;
  int len = strlen( str );

  while( i < len ){
    if( ch == str[ i ] ){
      count++;
    }
    i++;
  }

  return count;
  
}
