 
#include<stdio.h>
#include<stdbool.h>
#include<math.h>
 
//判断给定的数字是否为素数
bool is_prime( int n );
 
int main(void){
//    int n = 100000;
    int n = 0;
    int i = 3;
    int count = 0;
 
    scanf("%d",&n);
    n -= 2;//因需要判断的是i及i+2，所以循环变量的值最大为n-2
 
    while( i <= n ){
        if( is_prime(i) && is_prime(i+2)){
            count++;
            i += 2;
            continue;
        }
        i++;
    }
    printf("%d\n",count);
    //
 
//    printf("hello\n");
    return 0;
}
 
 
bool  is_prime( int n ){
    bool flag = false;
    int i = 2;
    int j = (int)sqrt(n);
    for( i = 2; i <= j; i++ ){
        if( 0 == n % i ){
            break;
        }
    }
    if( i > j ){
        flag = true;
    }
 
    return flag;
}
