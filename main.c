#include <stdio.h>
#include "calculator.h"




int main()
{
    char str[80];
    scanf("%s", str);

    int val = getG(str);
    printf("val = %d\n", val);
    
    return 0;
}