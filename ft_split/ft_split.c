#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int is_sep(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *s)
{
    int i = 0;
    int count = 0;

    while(s[i])
    {

        while( s[i] && is_sep(s[i]))
            i++;

        if(s[i] && !is_sep(s[i]))
        {
            count++;
            while(s[i] && !is_sep(s[i]))
                i++;
        }
    }
    return count;

}

char *word_dup(char *str, int start, int end)
{
    char *word;
    int i = 0;

    word = (char *)malloc(sizeof(char) * (end -  start) + 1);
    if(!word)
        return NULL;
    while(start < end)
    {
        word[i] = str[start];
        start++;
        i++;
    }
    word[i] = '\0';
    return word;

}

char    **ft_split(char *str)
{
    char **res;
    int  i = 0;
    int j = 0;
    int start;

    res = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
    if(!res)
        return NULL;
    while(str[i])
    {
        while(is_sep(str[i]))
            i++;
    
        start = i;
        while( str[i] && !is_sep(str[i]))
            i++;

        if ( i >start)
            res[j++] = word_dup(str, start, i);
    }
    res[j] = NULL;
    return res;
}

int main()
{
    char **split = ft_split("hello lynn how are you");
    int i = 0;

    while (split[i])
    {
        printf("[%s]\n", split[i]);
        free(split[i]);
        i++;
    }
    free(split);
}