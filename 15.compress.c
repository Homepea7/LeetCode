/************************************************************************
 *	给定一组字符，使用原地算法将其压缩。
 *	压缩后的长度必须始终小于或等于原数组长度。
 *	数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
 *	在完成原地修改输入数组后，返回数组的新长度。
 *	进阶：
 *	你能否仅使用O(1) 空间解决问题？
 *	
 *	示例 1：
 *	
 *	输入：
 *	["a","a","b","b","c","c","c"]
 *	输出：
 *	返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
 *	说明：
 *	"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。

 *	示例 2：
 *	输入：
 *	["a"]
 *	输出：
 *	返回1，输入数组的前1个字符应该是：["a"]
 *	说明：
 *	没有任何字符串被替代。
 *	示例 3：
 *	
 *	输入：
 *	["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 *	输出：
 *	返回4，输入数组的前4个字符应该是：["a","b","1","2"]。
 *	说明：
 *	由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
 *	注意每个数字在数组中都有它自己的位置。

 *	注意：
 *	所有字符都有一个ASCII值在[35, 126]区间内。
 *	1 <= len(chars) <= 1000。
 *	
 *	来源：力扣（LeetCode）
 *	链接：https://leetcode-cn.com/problems/string-compression
 *	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *Trans(char c, int n){
	//将字符和数字转化为字符串返回
	char *ret = (char*)malloc(sizeof(char)*4);
	sprintf(ret, "%c%d", c, n);
	return ret;
}

int compress(char* chars, int charsSize){
	char c = chars[0];				//初始的字符
	int  cnt = 0;					//重复的字符数
	char ret_char[1000];			//结果字符串
	char tmp_char[5];				//临时字符串
	int  ret = 0;					//返回值（长度）
	
	for(int i = 0; i < charsSize; i++)	{	//开始读取
		while(i < charsSize &&  c == chars[i])	{
			c = chars[i];
			i++, cnt++;
		}
		
		sprintf(tmp_char, "%c%d", c, cnt);
		strcat(ret_char, tmp_char);
		c = chars[i];
		if(cnt < 10)		ret += 1;
		else if(cnt < 100)	ret += 2;
		else 				ret += 3;
		
		ret++, cnt = 1;		//i从0开始，有重叠，cnt从1开始

	}
	printf("%s",ret_char);
	return ret;
}



int main(void)
{
	//char *reps[13]  = {"a", "asss", "bdd", "bdd", "c", "c", "c"};
	// char *reps = malloc(sizeof(char)* 20);
	// char temp[10] = "10";

	// strcpy(reps[1], temp);

	char strArr[28]  = "aabbcccccccccccccccccccccccc";

	printf("Result: %d!", compress(strArr, 28));

	

	// compress(reps, 7);
    return 0;
}


