////////////////////////////////////////////  
//单链表的初始化，建立，插入，查找，删除。//  
//**头结点是没有数据域**
//**尾节点指针域都是NULL**
////////////////////////////////////////////   
#include <stdio.h>  
#include <stdlib.h>  

int reverse(int x){
	long int Reverse_x = 0;
	int max = 0x7fffffff, min = 0x80000000, Temp;//int的最大值最小值
	//long Reverse_x = 0x80000000;

	while( x!=0 )
	{
		Temp = x%10;
		Reverse_x = Reverse_x*10 + Temp;
		x /= 10;
	}
	if( (Reverse_x > max)||(Reverse_x < min) )
		return 0;
	return Reverse_x;

}

int main(void)
{
	// char *str[4] = {"aaa", "bbb", "ccc"};
	printf("Test ");

	char str[15] = "000";
	char a[10]  = "sssss";
 	// char str[80];
	char *temp[4] = {"aaa", "bbb", "ccc"};


    strcat (str,*temp);
	puts(str);

	strcat (str,*(temp+1));
	puts(str);
	
	strcat (str,*(temp+2)); 
    puts (str);
	
	//printf("%d\r\n",reve rse(-23));
	
	getchar();
	return 0;
}









