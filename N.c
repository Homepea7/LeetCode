#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int a = 10;
int b = 20;

int myAtoi(char * str)
{
	int Int_Value, flag = 0 ;	//返回值和正负的flag

	//先移除开头的空格
	while(*str == ' ')
		str++;
	//判断第一位
	if(*str == '-')
		flag = -1, ++str;	//负数
	else if( ! ((*str >= '0') && (*str <= '9') ) )
	{
		printf("0");
		return 0;
	}	
	while(*str != '\0' )
	{
		
		//开始计算
		if((*str >= '0') && (*str <= '9') )
		{
			printf("bit: %c\r\n", *str);
			Int_Value = Int_Value*10 + *(str) - '0';


			if( (* (str+1) >= '0') && (* (str+1) <= '9') ) 	//结尾
				;//Int_Value = Int_Value*10 + dig;
			else 
				return flag == -1 ? -Int_Value : Int_Value;
		 }	
		//printf("%c",*str);
		str++;
	}

	return flag == -1 ? -Int_Value : Int_Value;
}

int myAtoi2(char * str){
    // 移除开头的空格
    while(*str == ' ')
        ++str;

    // 记录正负性
    int flag = 1;
    if (*str == '-') {
        flag = -1;
        ++str;
    }
    else if (*str == '+')
        ++str;

    int ret = 0;
    // 因为只能使用 32 位 int，因此将 ret 乘 10 后再与 INT_MAX 比较可能会溢出
    // 因此使用 ret 与 INT_MAX/10 比较
    int div = INT_MAX / 10;
    while (*str <= '9' && *str >= '0') {
        int dig = *str - '0';
        // 若 ret 比 div 小，则 ret * 10 + dig 也一定小于 INT_MAX，不会溢出
        // 若 ret 与 div 相等，只有 dig 比 8 小时不会溢出
        // 此处本来需要正负分开讨论，INT_MAX 个位是 7，INT_MIN 个位是 8
        // -INT_MIN 在 int 中会溢出，当 dig == 8 时直接当作溢出处理
        if (ret < div || (ret == div && dig < 8)) {
            ret = ret * 10 + dig;
            ++str;
        }
        // 溢出，根据正负性返回值
        else
            return (flag == 1? INT_MAX: INT_MIN);
    }
    return flag * ret;
}
int myAtoi3(char * str)
{
		int Int_Value, flag = 0 ;	//返回值和正负的flag

		//先移除开头的空格
		while(*str == ' ')
			str++;
		//判断第一位
		if(*str == '-')
			flag = -1, ++str;	//负数
		else if( ! ((*str >= '0') && (*str <= '9') ) )
		{
			printf("0");
			return 0;
		}	

    int div = INT_MAX / 10;
    while (*str <= '9' && *str >= '0') 
	{
        int dig = *str - '0';
        if (Int_Value < div || (Int_Value == div && dig < 8)) {
            Int_Value = Int_Value * 10 + dig;
            ++str;
        }
        else
            return (flag == 1? INT_MAX: INT_MIN);
    }
    return (flag == -1 ? -Int_Value : Int_Value);
}

int main(void)
{
	int a = 5;
	int* p = &a;
	int *q = &a;

	// printf("%d %d",*p,*q);
    // int i = i;

	printf("%d", myAtoi3("-42"));

//	printf("Hello  world! \r\n");
  	return 0;
}