/*********************************************************************
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/length-of-last-word
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **********************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *Trans(char c, int n){
	//将字符和数字转化为字符串返回
	char *ret = (char*)malloc(sizeof(char)*4);
	sprintf(ret, "%c%d", c, n);
	return ret;
}

int lengthOfLastWord(char *s){
	// int length = 0, length_last = 0;	//随时可能到最后一个，因此实时保存一个数
	// char flag = 0;
	// while(*s!='\0')
	// {
	// 	//printf("%c",*s);
	// 	//判断是不是空格
	// 	if(*s != ' ')		flag = 1;
	// 	else 				flag = 0;
		
	// 	if(1 == flag)
	// 		length ++ ;//长度++;
	// 	else {
	// 		length_last = length;
	// 		length = 0;
	// 	}
	// 	s++;
	// }
	// if(0 == length)		length = length_last;
	// printf("%d  ", length);
	// return length;
	
	
    int lenth = strlen(s);
    if (lenth == 0) 	return 0;
    
    int i;
    int flag = 0;
	int count = 0;
    //从后往前遍历第一个字母
    for (i = lenth-1; i >= 0;i--) {
        if (*(s+i) == ' ' && flag==0 ) {
            
        } else if ( ('a' <= *(s+i)  &&  *(s+i) <= 'z') || ('A' <= *(s+i) && *(s+i) <= 'Z')) {
            count++;
            flag = 1;
        } else if (*(s+i) == ' ' && flag==1) {
            return count;
        }
    }
    return count;
}



int main(void)
{
	char strArr[15]  = "a ";
	lengthOfLastWord(strArr);

    return 0;
}


