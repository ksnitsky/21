#include "ft_printf.h"
#include <stdio.h>
int     prf_percent(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
            return (i);
        i++;
    }
    return (-1);
}

int     main()
{
    printf("%d", prf_percent("kasdiqj %%"));
    return (0);
}
