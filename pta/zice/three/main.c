#include<stdio.h>


//将数组元素右移一位
int move_right( int * arr, int arr_len);

int main(void){
    int arr[100];
    int arr_len = 0;
    int n = 0;
    int m = 0;
    int i = 0;

    while( EOF != scanf("%d %d",&n,&m)){
        arr_len = n;
        m = m % n;
        for( i = 0; i < arr_len; i++ ){
            scanf("%d",&arr[i]);
        }
        while(m > 0 ){
            move_right(arr,arr_len);
            m--;
        }
        arr_len--;
        for( i = 0; i < arr_len; i++ ){
            printf("%d ",arr[i]);
        }
        printf("%d\n",arr[i]);
    }

//    printf("hello\n");
    return 0;
}


int move_right( int * arr, int arr_len){
    int key = arr[arr_len - 1];
    int i = arr_len - 1;

    while( i > 0 ){
        arr[i] = arr[i - 1];
        i--;
    }
    arr[0] = key;

    return 0;
}
