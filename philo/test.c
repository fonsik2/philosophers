#include <stdio.h>
#include <stdlib.h>

int *init(int *s)
{
	int *arr;

	arr = (int*)malloc(sizeof(int) * *s);
	return (arr);
}



int	main()
{
	int *arr;
	int i;
	int s;

	s = 5;
	arr = init(&s);
	i = 0;
	while (i < 5)
	{
		*(arr + i) = i;
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
	
