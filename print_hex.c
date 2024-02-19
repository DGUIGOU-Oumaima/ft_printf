#include <stdio.h>
#include <stdlib.h>

static char    *calculateHexSize(unsigned int x, int *position)
{
    int i;
    char *str;

    i = 0;
    while(x!=0)
    {
        x = x / 16;
        i++;
    }
    *position = i - 1;
    str = calloc(i + 1, sizeof(char));
    return (str);
}


int   print_hex(unsigned int value, int up)
{
    unsigned int y;
    char *str;
    int i;
    int *pos;
    unsigned int x;

    x = value;
    pos = &i;
    str = calculateHexSize(x, pos);
    if(!str)
        return (0);
    while(x != 0)
    {
        y = x % 16;
        x = x / 16;
        
        if(y<=9)
            str[i] = y + 48;
        else
            str[i] = y + up;
        i--;
    }
    ft_putstr_fd(str, 1);
    i = ft_strlen(str);
    free(str);
    if(value == 0)
        { i += print_char('0'); // why 
        printf("%d", i);}
    return(i);
}
