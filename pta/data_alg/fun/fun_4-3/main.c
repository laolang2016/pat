#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
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

int Length( List L ){
  PtrToLNode node = L;
  int len = 0;
  if(  NULL == L  ){
    
  }
  while(  NULL != node ){
    len++;
    node = node->Next;
  }

  return len;
}
