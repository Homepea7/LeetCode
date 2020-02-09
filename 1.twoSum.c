/*
*	给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
*
*	你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
*
*	示例:
*	给定 nums = [2, 7, 11, 15], target = 9
*	因为 nums[0] + nums[1] = 2 + 7 = 9
*	所以返回 [0, 1]
*
*	来源：力扣（LeetCode）
*	链接：https://leetcode-cn.com/problems/two-sum
*	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include "stdio.h"
#include "stdlib.h"

int* sum(int* a, int *b, int* res) 
{
	int* sum;
	sum = (int*)malloc(sizeof(int));
	*sum = *a +*b;
	return sum;
}



int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	//测试
	// for(int i = 0; i < numsSize; i++)
	// 	printf("%d ", nums[i]);

    int* res = (int *)malloc(sizeof(int) * 2);
    *returnSize=0;
    for(int i = 0; i < numsSize-1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums [j] == target) {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }
}




int main(void )
{

	int *p;
	//printf("%d",*p);
	int tmp[4] = {2,7,11,15};
	int r[2];

	*r = *twoSum(tmp, 4, 26, p);
	//printf("Test %d %d \r\n", );
	getchar();
	return 0;
}