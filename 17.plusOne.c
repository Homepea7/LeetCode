/*********************************************************************
 *	给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 *	
 *	最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 *	
 *	你可以假设除了整数 0 之外，这个整数不会以零开头。
 *	
 *	示例 1:
 *	
 *	输入: [1,2,3]
 *	输出: [1,2,4]
 *	解释: 输入数组表示数字 123。
 *	示例 2:
 *	
 *	输入: [4,3,2,1]
 *	输出: [4,3,2,2]
 *	解释: 输入数组表示数字 4321。
 *	
 *	来源：力扣（LeetCode）
 *	链接：https://leetcode-cn.com/problems/plus-one
 *	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 **********************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int* plusOne(int* digits, int digitsSize, int* returnSize){
	int i = 0, j = 0, flag = 0;			//进位的标志
	int ret[digitsSize+1];				//可能会长一位，比如9+1
	
	int tmp = digits[digitsSize-i-1];
	tmp++;								//末位加一


	if(tmp >= 10)	flag = 1;
	else 			flag = 0;

	for(i = digitsSize-1; i >= 0; i-- )	{
		if(flag == 1)	{
			

		}
		
		printf("%d ", digits[digitsSize-i-1]);

	}
	return returnSize;
}



int main(void)
{
	int *returnSize = (int *)malloc(sizeof(int));
	int strArr[10]  = {1,2,3,4,5,6,7,8};
	int length  = sizeof(strArr) / sizeof(int);

	plusOne(strArr, length, returnSize);


	//lengthOfLastWord(strArr);

    return 0;
}


