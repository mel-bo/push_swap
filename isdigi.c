
#include <unistd.h>
#include <stdio.h>

// void ft_isdigit(int n)
// {
// 	if (n == 'a')
// 		printf("false\n");
// }
int main(void)
{
	int i = 2147483647;
	printf("%d\n", i);
	i += 2147483647;
	printf("%d\n", i);
	return (0);
}