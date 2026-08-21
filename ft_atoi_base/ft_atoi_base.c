#include <stdio.h>
#include <unistd.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int res = 0;
    int i = 0;
    int digit;

    if(str_base < 2 || str_base > 16)
        return 0;
    
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }

    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';
        else if(str[i] >='a' && str[i] <= 'z')
            digit = str[i] - 'a' + 10;
        else if(str[i] >='A' && str[i] <= 'Z')
            digit = str[i] - 'A' + 10;
        else
            break;
        if(digit >str_base)
            break;
        res = res *str_base + digit;
        i++;
    }

    return res * sign;

}

int main()
{
     int test = ft_atoi_base("ff", 16);
     printf("%d", test);
}