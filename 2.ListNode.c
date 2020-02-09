/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是
按照 逆序 的方式存储的，并且它们的每个节点只能存储一位数字。如果，
我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

 */


#include "stdio.h"
#include "stdlib.h"

//Definition for singly-linked list.
struct ListNode {
	int val;   
	struct ListNode *next;
};

//创建链表
struct ListNode* creat(int n){
	struct ListNode *head, *node, *end;		//定义头尾和中间节点
	head = (struct ListNode*)malloc(sizeof(struct ListNode*));
	end  = head;							//尾节点
	puts("Please input the nums: \r\n");
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

//打印链表
struct ListNode* lkprint(struct ListNode *p){
	while(p->next != NULL){
		p = p->next;
		printf("%d ", p->val);
		//寻找最后一位
		if(!p->next)	
			printf("End: %d ", p->val);
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	char flag = 0;			//进位的标志
	struct ListNode* p;		//最多多一位
	while(l1->next && l2->next ){
		l1 = l1->next;
		l2 = l2->next;
		l1->val = (l1->val + l2->val + flag )%10;
		flag    = (l1->val + l2->val + flag )/10;
		//printf(" %d %d :",l1->val, l2->val);
	}
	//后面的部分，注意最高位
	if(l1->next){			//l1非空
		while(l1->next){
			l1 = l1->next;
			l1->val = (l1->val + flag )%10;
			flag    = (l1->val + flag )/10;
			//寻找最后一位
			if(!l1->next)	
			{

				l1->val = (l1->val + flag )%10;
				flag    = (l1->val + flag )/10;
				if(flag){
					p  = (struct ListNode*)malloc(sizeof(struct ListNode*));
					p->val = 1;
					p->next  = l1->next;
					l1->next = p;
				}
			}
			else ;
		}
	}
	else {
		l1->next = l2;	//将l2连接到l1尾部
		while(l2->next){
			l2 = l2->next;
			l2->val = (l2->val + flag )%10;
			flag    = (l2->val + flag )/10;
			//寻找最后一位
			if(!l2->next)	
			{

				l2->val = (l2->val + flag )%10;
				flag    = (l2->val + flag )/10;
				if(flag){
					p  = (struct ListNode*)malloc(sizeof(struct ListNode*));
					p->val = 1;
					p->next  = l2->next;
					l2->next = p;
				}
			}
			else ;
		}
	}

	return l1;

	// int temp = 0, num1 = 0, num2 = 0;
	// while(l1->next != NULL){
	// 	l1 = l1->next;
	// 	temp = l1->val;
	// 	num1 = 10*num1 + temp;
	// }
	// while(l1->next != NULL){
	// 	l1 = l1->next;
	// 	temp = l1->val;
	// 	num1 = 10*num1 + temp;
	// }
	// temp = 0;
	// while(l2->next != NULL){
	// 	l2 = l2->next;
	// 	temp = l2->val;
	// 	num2 = 10*num2 + temp;
	// }
	// printf("n1,n2: %d, %d\r\n",num1, num2);
}


int main(void )
{
	struct ListNode* Lk1;
	Lk1 = creat(3);
	lkprint(addTwoNumbers(Lk1, Lk1));
	//addTwoNumbers(Lk1, Lk1);

	getchar();
	return 0;
}