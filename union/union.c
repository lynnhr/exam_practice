#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    char seen[256] = {0};
    int i = 0;
    int j = 0;
    int k = 0;

    if(ac == 3)
    {
        while(av[1][i])
        {
            k = 0;
            while(seen[k] != av[1][i] && seen[k] != 0)
                k++;
            if(seen[k] == 0)
            {
                seen[k] = av[1][i];
                write(1, &av[1][i], 1);
            }
            i++;
        }
        while(av[2][j])
        {
            k = 0;
            while(av[2][j] != seen[k] && seen[k] != 0)
                k++;
            if(seen[k] == 0)
            {
                seen[k] = av[2][j];
                write(1, &av[2][j], 1);
            }
            j++;
        }

    }
    write(1, "\n", 1);
    return 0;
}