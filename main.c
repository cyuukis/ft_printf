#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
	printf("%5c", '');
	ft_printf("%5c", '');
	printf("|%5c|\n", ' ');
	ft_printf("|%5c|\n", ' ');
	printf("|%.1c|\n", 'c');
	ft_printf("|%.1c|\n", 'c');
	printf("|%-3.5c|\n", 'c');
	ft_printf("|%-3.5c|\n", 'c');
	printf("|%-5.3c|\n", 'c');
	ft_printf("|%-5.3c|\n", 'c');
	// ft_printf("|%-c|\n", 'c');
	// ft_printf("|%-5c|\n", 'c');
	// ft_printf("|%.1c|\n", 'c');
	// ft_printf("|%.c|\n", 'c');
	// ft_printf("|%-3.5c|\n", 'c');
	// ft_printf("|%-5.3c|\n", 'c');
	// ft_printf("|%03.5c|\n", 'c');
	// printf("|%-5c|\n", 'c');
	// ft_printf("|%-5c|\n", 'c');
	//  printf("|%-6s|\n", "Hello");//
	//  ft_printf("|%-6s|\n", "Hello");
	//  printf("|%-.3s|\n", "Hello");
	//  ft_printf("|%-.3s|\n", "Hello");
	//  printf("|%-1.3s|\n", "Hello");
	//  ft_printf("|%-1.3s|\n", "Hello");
	//  printf("|%0.6s|\n", "Hello");
	//  ft_printf("|%0.6s|\n", "Hello");
	//  ft_printf("|%s|", "Hello");
	// printf("|%05.3s|\n", "Hello");
	// ft_printf("|%05.3s|\n", "Hello");//
	// printf("|%05c|\n", 'c');
	// ft_printf("|%c|\n", 'c');
	// printf("|%c|\n", 'c');
	// ft_printf("|%c|\n", 'c');
  //////////////////////////////
	// printf("|%7d|\n", -14);
	// ft_printf("|%7d|\n", -14);
	// printf("|%-6d|\n", 10);
	// ft_printf("|%-6d|\n", 10);
	// printf("|%06d|\n", 10);
	// ft_printf("|%06d|\n", 10);
	// printf("|%6.d|\n", 10);
	// ft_printf("|%6.d|\n", 10);
	// printf("|%-6.d|\n", 10);
	// ft_printf("|%-6.d|\n", 10);
	//  printf("|%06.3d|\n", 0);//6
	//  ft_printf("|%06.3d|\n", 0);
	// printf("|%06d|\n", 0);
	// ft_printf("|%06d|\n", 0);
	// printf	 ("|%-6.4d|\n", 1);
	// ft_printf("|%-6.4d|\n", 1);
	// printf("|%0d|\n", 0);
	// ft_printf("|%0d|\n", 0);

	// ft_printf("%7d\n", 33);
	// printf("%7d\n", -14);
	// ft_printf("%7d\n", -14);
	// printf("%3d\n", 0);
	//  printf("|%1c|\n", '!');
	//  ft_printf("|%1c|\n", '!');
	return (0);
}
