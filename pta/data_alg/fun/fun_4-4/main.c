#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

List Read(){

  int num = 0;
  scanf( "%d",&num );
  if( -1 == num  ){
    return NULL;
  }

  List list = ( List )malloc( sizeof( struct LNode ) );
  List last = list;
  list->Data = num;
  list->Next = NULL;
  
  scanf( "%d",&num );
  while( -1 != num  ){
    PtrToLNode node = ( List )malloc( sizeof( struct LNode ) );
    node->Data = num;
    node->Next = NULL;
    last->Next = node;
    last = node;
    scanf( "%d",&num );
  }

  return list;
}

//返回链式表的第K个元素。如果该元素不存在，则返回ERROR
ElementType FindKth( List L, int K ){
  if( NULL == L  ){
    return ERROR;
  }

  if( K <= 0  ){
    return ERROR;
  }

  PtrToLNode node = L;
  int i = 1;
  while(  NULL != node && i < K ){
    //    printf( "data = %d\n",node->Data );
    if( NULL == node->Next  ){
      break;
    }
    node = node->Next;
    i++;
  }
  if( i< K ){
    return ERROR;
  }else{
    return node->Data;
  }
}
