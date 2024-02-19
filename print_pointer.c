#include "ft_printf.h"

static char    *calculateHexSize(unsigned long x, int *position)
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


int   print_pointer(unsigned long value, int up)
{
    unsigned long y;
    char *str;
    int i;
    int *pos;
    unsigned long x;

    x = value;
    pos = &i;
    str = calculateHexSize(x, pos);
    if(!str)
        return (0);
    while(x != 0 && i-->=0) //why >=0
    {
        y = x % 16;
        x = x / 16;
        
        if(y<=9)
            str[i+1] = y + 48;
        else
            str[i+1] = y + up;
    }
    i = ft_strlen(str);
    i = i + print_string("0x");
    ft_putstr_fd(str, 1);
    free(str);
    if(value == 0)
        { i += print_char('0'); // why 
        printf("%d", i);}
    return(i);
}
