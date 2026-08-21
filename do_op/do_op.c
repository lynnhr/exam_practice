#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if(ac == 4)
    {
        int a = atoi(av[1]);
        int b = atoi(av[3]);
        int sign = av[2][0];
        int res = 0;

        if (sign == '+')
            res = a + b;
        else if (sign == '-')
            res = a - b;
        else if (sign == '/')
            res = a / b;
        else if (sign == '*')
            res = a * b;
        else if(sign == '%')
            res = a%b;
        printf("%d", res);

    }
    // write(1, "\n", 1);
    return 0;
}