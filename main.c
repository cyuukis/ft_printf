#include "ft_printf.h"
#include <stdio.h>
int main(void)
{
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
	printf("|%6d|\n", 10);
	ft_printf("|%6d|\n", 10);
	printf("|%-6d|\n", 10);
	ft_printf("|%-6d|\n", 10);
	printf("|%06d|\n", 10);
	ft_printf("|%06d|\n", 10);
	printf("|%6.d|\n", 10);
	ft_printf("|%6.d|\n", 10);
	printf("|%-6.d|\n", 10);
	ft_printf("|%-6.d|\n", 10);
	 printf("|%06.3d|\n", 10);
	 ft_printf("|%06.3d|\n", 10);
	printf("|%06d|\n", 10);
	ft_printf("|%06d|\n", 10);
	printf	 ("|%-6.4d|\n", 10);
	ft_printf("|%-6.4d|\n", 10);
	printf("|%0d|\n", 10);
	ft_printf("|%0d|\n", 10);
	printf("|%-.d|\n", 10);
	ft_printf("|%-.d|\n", 10);
	return (0);
}
