/**
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的
 * 两个链表的所有节点组成的。 
 *
 *	示例：
 *	输入：1->2->4, 1->3->4
 *	输出：1->1->2->3->4->4
 *
 *	来源：力扣（LeetCode）
 *	链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
 *	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Definition for singly-linked list.
struct ListNode {
	int val;   
	struct ListNode *next;
};

//创建链表
struct ListNode* ListNodeCreat(int n){
	struct ListNode *head, *node, *end;		//定义头尾和中间节点
	head = (struct ListNode*)malloc(sizeof(struct ListNode*));
	end  = head;							//尾节点
	puts("Creat LK, please input the nums:");
	for(int i = 0; i < n;i++){
		node = (struct ListNode*)malloc(sizeof(struct ListNode*));
		scanf("%d", &node->val);
		//重点把握节点的变换顺序
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}

//创建链表
struct ListNode* ListNodeChange(struct ListNode *list, int n){
	struct ListNode *p = list;
	for(int i = 0; (i < n) && (p->next) ;i++){
		p = p->next;
	}
	if(p->next){
		printf("Please input %d value:", n);
		scanf("%d", &p->val);
	}
	else 
		puts("The node is NULL!");
}

//打印链表
struct ListNode* ListNodePrint(struct ListNode *p){
	while(p->next){
		p = p->next;
		printf("%d ", p->val);
		// //寻找最后一位
		// if(!p->next)	
		// 	printf("End: %d ", p->val);
	}
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
// 遍历l2，插入l1对应的位置。
// 要为l1创建一个虚拟头结点，这样如果l2的最小值小于l1的最小值就可以头插了。
// l1链表 ： l1 在左 ， p1 在右 ， l1从虚拟头结点开始， p1紧跟其后。
// l2链表 ： l2 在左 ， p2 在右 ， l2从第一个结点开始， p2紧跟其后。
// 每次比较 l2所指结点的值 与 p1所指结点的值 ， 若满足l2 <= p1 , 则把l2 
// 插到 p1 前面。 然后l2 与 p2 后移一位, 否则 l1 与 p1 后移一位。 

	if(l1 == NULL)	return l2;
	if(l2 == NULL)	return l1;

	struct ListNode newhead, *p1, *p2;
	//虚拟的头结点
	newhead.next = l1;
	l1 = &newhead;

	//开始遍历l2
	while(l2->next){
		p1 = l1->next;
		p2 = l2->next;
		if(p1 == NULL){		//P1结束直接连接到p2即可（因为是顺序的）
			l1->next = l2;
			break;
		}
		if(l2->val <= p1->val){
			l2->next = l1->next;
			l1->next = l2;
			l2 = p2;
		}
		l1 = l1->next;
	}
	return newhead.next->next;

	// struct ListNode *node;		
	// //先获得初始值
	// int m = 0, n = 0;
	// // int m = l1->next->val, n = l2->next->val;	
	
	// while(l1->next && l2->next){
	// 	l1 = l1->next;
	// 	l2 = l2->next;
	// 	//先获得初始值
	// 	m = l1->val;
	// 	n = l2->val;
	// 	while( (m > n) && (l2->next) ){
	// 		node = (struct ListNode*)malloc(sizeof(struct ListNode*));
	// 		node->val = l2->val;
	// 		l2 = l2->next;
	// 	}
		
	// 	//if()
		
		
	// 	//scanf("%d", &node->val);
	// 	// //重点把握节点的变换顺序
	// 	// end->next = node;
	// 	// end = node;

	// 	//printf("%d %d. ", l1->val, l2->val);
	// 	//printf("%d ", l1->val);

	// }
	// if(l1->next)		//如果l1还没有结束就继续链接l1
	// 	;
	// else 			//否则就链接l2
	// 	l1->next = l2->next;
}
// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//     if(l1 == NULL) return l2;
//     if(l2 == NULL) return l1;
    
//     struct ListNode newhead, *p1, *p2;
//     newhead.next = l1;
//     l1 = &newhead;
    
//     while(l2 != NULL) {
//         p1 = l1->next;
//         p2 = l2->next;
//         if(p1 == NULL) {
//             l1->next = l2;
//             break;
//         }
//         if(l2->val <= p1->val) {
//             l2->next = l1->next;
//             l1->next = l2;
//             l2 = p2;
//         }
//         l1 = l1->next;
//     }
//     return newhead.next;
// }

int main(void )
{
	struct ListNode *Lk1, *Lk2;
	Lk1 = ListNodeCreat(3);
	Lk2 = ListNodeCreat(3);
	// ListNodeChange(Lk2,2);
	// ListNodePrint(Lk1);
	// ListNodePrint(Lk2);

	ListNodePrint(mergeTwoLists(Lk1, Lk2));


	// lkprint(mergeTwoLists(Lk1, Lk2));
	//addTwoNumbers(Lk1, Lk1);

	getchar();
	return 0;
}