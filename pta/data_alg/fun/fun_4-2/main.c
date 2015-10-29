#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

void print( List L );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }

    print( L );
    
    
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }

    return 0;
}


List MakeEmpty(){
  List list = ( List )malloc( sizeof( struct LNode ) );
  list->Last = -1;
  return list;
}

//将X插入在位置P并返回true。若空间已满，则打印“FULL”并返回false；
//如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false；
bool Insert( List L, ElementType X, Position P ){
  if( NULL == L ){
    L = MakeEmpty();
  }

  //判断是否已满
  if( L->Last >= ( MAXSIZE - 1 ) ){
    printf( "FULL" );
    return false;
  }

  //判断P的位置是否非法
  if(  0 > P || P > ( L->Last + 1 ) || P > ( MAXSIZE - 1 )){
    printf( "ILLEGAL POSITION" );
    return false;
  }

  if( P == L->Last + 1 ){
    L->Data[ P ] = X;
    L->Last++;
    // print( L );
    return true;
  }

  if( P == L->Last ){
    L->Data[ P + 1 ] = L->Data[ L->Last ];
    L->Data[ P ] = X;
    L->Last++;
    // print( L );
    return true;
  }

  int i = L->Last + 1;
  while(  i > P ){
    L->Data[ i ] = L->Data[ i - 1 ];
    i--;
  }
  L->Data[ P ] = X;
  L->Last++;
  //print( L );
  return true;

  
}

//返回线性表中X的位置。若找不到则返回ERROR
Position Find( List L, ElementType X ){
  if( NULL == L || -1 == L->Last ){
    return ERROR;
  }

  int pos = ERROR;
  int i = 0;
  while(  i<= L->Last ){
    if( X == L->Data[ i ] ){
      pos = i;
      break;
    }
    i++;
  }

  return pos;
  
}

//将位置P的元素删除并返回true。
//若参数P指向非法位置，则打印“POSITION P EMPTY”（其中P是参数值）并返回false
bool Delete( List L, Position P ){
  //判断P是否非法
  if( P < 0 || P > L->Last ){
    printf( "POSITION %d EMPTY",P );
    return false;
  }

  int i = P;
  while( i<= L->Last - 1 ){
    L->Data[ i ] = L->Data[ i + 1 ];
    i++;
  }
  L->Last--;
  return true;
}

void print( List L ){
  int i = 0;
  while( i <= L->Last ){
    printf( "%d",L->Data[ i ] );
    i++;
  }

  putchar( '\n' );
}

