#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int ft_count_digits(long n)
{
    int count = 0;

    if(n <= 0)
        count++;
    if( n<0)
        n = -n;
    while(n>0)
    {
        count++;
        n /= 10;
    }
    return count;
}
char *ft_itoa(int nbr)
{
    char *res;
    long n = nbr;
    int len = ft_count_digits(n);

    res = (char *)malloc(sizeof(char) * (len + 1));
    if(!res)
        return NULL;

    res[len] = '\0';
    --len;

    if(n == 0)
        res[0] = '0';
    
    if(n<0)
    {
        res[0] = '-';
        n = -n;
    }

    while(n > 0)
    {
        res[len] = (n%10) + '0';
        n /= 10;
        len--;
    }
    return res;
}

int main()
{
    printf("%s", ft_itoa(678));
}