////////////////////////////////////////////  
// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

// 示例 1:
// 输入: 2.00000, 10
// 输出: 1024.00000

// 示例 2:
// 输入: 2.10000, 3
// 输出: 9.26100

// 示例 3:
// 输入: 2.00000, -2
// 输出: 0.25000
// 解释: 2-2 = 1/22 = 1/4 = 0.25

// 说明:
// -100.0 < x < 100.0
// n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/powx-n
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
////////////////////////////////////////////   
#include <stdio.h>  
#include <stdlib.h>  

//这个思路计算的时间太长了
double myPow(double x, int n){
	if(x == 0)	//先考虑特殊情况
		if(n == 0) 	return 1;
		else 		return 0;
	else 	
	{
		double ex_x = x;
		if(n > 0)
		{
			for(int i = 0; i < n-1; i++){
				x *= ex_x;
			}
		}
		else if(n == 0)
			return 1;
		else
		{
			x = (1/x);		
			for(int i = 0; i > n+1; i--){
				x *= (1/ex_x);
				//printf("% .4f \r\n", x);
			}
		}
		return x;
	}
}

//用递归
double myPow1(double x, int n){
	if (n == 0)
		return 1.0;
	double tmp = myPow1(x, n / 2);
	if (n % 2)
		return n < 0 ? 1 / x*tmp*tmp : x*tmp*tmp;
	else
		return tmp*tmp;
	
}


int main(void)
{
	
	printf("%.5f\r\n",myPow1(1.00000, -2147483648));
}









