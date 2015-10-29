/*
5-1 最大子列和问题   (20分)

给定K个整数组成的序列{ N​1​​, N​2​​, ..., N​K​​ }，“连续子列”被定义为{ N​i​​, N​i+1​​, ..., N​j​​ }，其中 1≤i≤j≤K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。
输入格式:

输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。
输出格式:

在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。
输入样例:

6
-2 11 -4 13 -5 -2

输出样例:

20


*/

#include<stdio.h>
#include<stdlib.h>


void print_c( int * arr, int len, int n );

int main( void ){
  int N = 0;
  int * arr = NULL;
  scanf( "%d",&N );
  arr = ( int* )malloc( sizeof( int )*N );
  int n = 0;
  scanf( "%d",&n );
  int i = 1;
  for( i = 1; i <= N; i++ ){
    arr[ i-1 ] = i;
  }


  
  print_c( arr,N,n );
  printf( "\nHello World!\n小代码！\n" );
  return 0;
}

void print_c( int * arr, int len, int n ){
  int i = 0;
  int end = len - n;

  for( i = 0; i <= end ; i++  ){
    int k = i;
    printf( "%d ",arr[ k ] );
    while(  k <= end  ){
      
      k++;
    }
    putchar( '\n' );
  }
}
