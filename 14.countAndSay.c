/************************************************************************
 *	「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。
 *	前五项如下：
 *	1.     1
 *	2.     11
 *	3.     21
 *	4.     1211
 *	5.     111221
 *	1 被读作  "one 1"  ("一个一") , 即 11。
 *	11 被读作 "two 1s" ("两个一"）, 即 21。
 *	21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 *
 *	给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 *
 *	注意：整数序列中的每一项将表示为一个字符串。
 *
 *	示例 1:
 *	输入: 1
 *	输出: "1"
 *
 *	示例 2:
 *	输入: 4
 *	输出: "1211"
 *
 *	来源：力扣（LeetCode）
 *	链接：https://leetcode-cn.com/problems/count-and-say
 *	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char * countAndSay(int n){
	char* res = (char*)malloc(sizeof(char) * 5000);
	char* tmp = (char*)malloc(sizeof(char) * 5000);
	strcpy(res, "1");					//初始化(从1开始的)
	// printf("%s", res);

	int len = 1;						//res的有效长度
	while(--n)	{
		int i = 0, j = 0;
		while(i < len ){				//开始计数
			int count = 1;
			char c = res[i++];

			while(i < len && res[i] == c)
				i++, count++;
			
			tmp[j++] = count + '0';		//将结果保存到tmp
			tmp[j++] = c;
		}
		tmp[j] = '\0';					//结束符
		strcpy(res, tmp);
		len = j;
	}
	return res;
}



int main(void)
{


	printf("%s",countAndSay(5));


    return 0;
}


