#include "stdio.h"

int main(void)
{
    int a = 0;
    int b = 10;
    int i = 0;
    
    for(i = 0;i < 5;i++)
    {
        a++;
        b--;
    }

    printf("Hello world! \r\n");


    getchar();

    return 0;
}


