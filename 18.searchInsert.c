/*********************************************************************
 *	给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值
 *	不存在于数组中，返回它将会被按顺序插入的位置。
 *
 *	你可以假设数组中无重复元素。
 *
 *	示例 1:
 *	输入: [1,3,5,6], 5
 *	输出: 2

 *	示例 2:
 *	输入: [1,3,5,6], 2
 *	输出: 1

 *	示例 3:
 *	输入: [1,3,5,6], 7
 *	输出: 4

 *	示例 4:
 *	输入: [1,3,5,6], 0
 *	输出: 0
 *
 *	来源：力扣（LeetCode）
 *	链接：https://leetcode-cn.com/problems/search-insert-position
 *	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * **********************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int searchInsert(int* nums, int numsSize, int target){
	if(1 == numsSize)	//如果只有一位提前返回
	{
		if(nums[0] < target)		return 1;
		else 						return 0;
	}
	if(target <= nums[0])			return 0;
	
	//int num = nums[1], last_num  = num;

	for(int i = 0; i < numsSize-1 ; i++)	{	//开始遍历
		// printf("%d ", nums[i]);
		if(nums[i] == target)	return i;
		if( (nums[i] < target) && (target < nums[i+1]) )	return i+1;
	}

	if(target == nums[numsSize-1])			return (numsSize-1);
	else 									return numsSize;
}

int main(void)
{
	int *returnSize = (int *)malloc(sizeof(int));
	int strArr[4]  = {1, 3, 5, 6};
	int length  = sizeof(strArr) / sizeof(int);

	printf("%d \r\n",searchInsert(strArr, length, 2));


    return 0;
}


