#include "stdio.h"

int main()
{
    int num = 24;
    int temp = 0;
    for(int i = 2; i>0; i--)
    {
        temp = num % 10;
        num /= 10;
    }

    return 0;
}