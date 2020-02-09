/*
*	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
*
*	有效字符串需满足：
*
*	左括号必须用相同类型的右括号闭合。
*	左括号必须以正确的顺序闭合。
*	注意空字符串可被认为是有效字符串。
*
*	示例 1:
*
*	输入: "()"
*	输出: true
*	示例 2:
*
*	输入: "()[]{}"
*	输出: true
*	示例 3:
*
*	输入: "(]"
*	输出: false
*	示例 4:
*
*	输入: "([)]"
*	输出: false
*	示例 5:
*
*	输入: "{[]}"
*	输出: true
*
*	来源：力扣（LeetCode）
*	链接：https://leetcode-cn.com/problems/valid-parentheses
*	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

/*
    if (s == NULL || s[0] == '\0') return true;
    char *stack = (char*)malloc(strlen(s)+1); 
    int top =0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack[++top] = s[i];       
        else if((s[i] == (stack[top] + 1))||(s[i] == (stack[top] + 2))) top--;        
        else return false;
    }
    free(stack);
    return (!top);


*/

bool isValid(char * s){
	int length = 0, a = 0;
	while(*(s+length)) length++;
	char* str = (char*)malloc(length+1);
	//类似堆栈的思路，直接开辟空间写
	for(int i = 0; i < length ;i++)	
	{
		if( (*(s+i) == '(') || (*(s+i) == '[') || (*(s+i) == '{') )
			a++, *(str+a) = *(s+i);
		else if( (*(s+i) == (*(str+a) + 1)) || ( (*(s+i) == (*(str+a) + 2))) )
			a--;
		else 	
		{
			free(str);
			return false;
		}
	} 
	free(str);
	return (a == 0) ? true : false;
}

int main(void)
{

	printf("%d",isValid("[][]"));
    return 0;
}


