#include <stdio.h>
#include "libft/libft.h"
#include "ft_print.h"


int main(void)
{
	int n;
	n = ft_printf("%s%d\n", "Hello World!", 42);
	printf("%d\n", n);

	return 0;
}