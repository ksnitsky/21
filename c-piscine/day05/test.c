#include <stdio.h>

int strcmp(const char *s1, const char *s2) {
	int i;

	i = 0;
	while (!(i = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2) 
	{
		++s1;
		++s2;
	}
	if (i < 0) {
		return (-1);
	} else if (i > 0) {
    	return (1);
	}
	return (0);
}

int     main()
{
    int a = strcmp("Hellos", "Hello");
    printf("%d", a);
}