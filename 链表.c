////////////////////////////////////////////  
//单链表的初始化，建立，插入，查找，删除。//  
//**头结点是没有数据域**
//**尾节点指针域都是NULL**
////////////////////////////////////////////   
#include <stdio.h>  
#include <stdlib.h>  
typedef int ElemType;  
typedef unsigned int uint;
uint lendth = 3;				//暂定的链表的长度
////////////////////////////////////////////   
//定义结点类型   
typedef struct Node  
{  
	ElemType data;              //单链表中的数据域   
	struct Node *next;          //单链表的指针域   
}Node,*LinkedList;  			
////////////////////////////////////////////   

//单链表的建立2，尾插法建立单链表  
LinkedList LinkedListCreatT()  
{  
	uint i = 0;
	//头节点
	Node* L;
	L = (Node*)malloc(sizeof(Node));
	L->next = NULL;

	//尾节点
	Node* R;
	R = (Node*)malloc(sizeof(Node));
	R = L;		//尾节点指针一直是NULL

	for(i = 0; i < lendth; i++)
	{
		//中间节点
		Node* P;
		P = (Node*)malloc(sizeof(Node));

		P->data = i;
		R->next = P;
		R = P;
	}

	R->next = NULL;
	return L;
}


//打印单链表的所有值
void Print_LinkedList(LinkedList Llist)
{
	LinkedList list,start;
	//list = LinkedListCreatT();

    for(start = Llist->next; start != NULL; start = start->next)  
        printf("%d ",start->data);  
}

int main(void)
{
	LinkedList list,start;
	list = LinkedListCreatT();
	Print_LinkedList(list);

    printf("\n");


	printf("HH\r\n");
}









