#include "ft_printf.h"


static int     help(unsigned int value)
{
    int i;
    if(value > 9)
        print_unsigned(value/10);
    if(value <= 9)  
    {
        ft_putchar_fd(value +48, 1);
        return;
    }
    ft_putchar_fd((value % 10) + 48, 1)
}



int     print_unsigned(unsigned int value)
{
    int i;

    help(value);
	i = 1;
	while (value > 9)
	{
		value = value / 10;
		i++;
	}
	return (i);
}