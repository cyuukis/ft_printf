#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
	printf("|%0*d|\n", 'c', 6);
	//ft_printf("|%000000000020d|", 5);
	return (0);
}
