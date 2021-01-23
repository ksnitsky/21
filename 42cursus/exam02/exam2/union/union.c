#include <unistd.h>

void
  no_doubles(char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str[i])
  {
	j = i + 1;
	while (str[j])
	{
	  if (str[i] == str[j])
		str[j] = '*';
	  j++;
	}
	i++;
  }
}

void
  print_union(char *one, char *two)
{
  while (*one)
  {
	if (*one != '*')
	  write(1, one, 1);
	one++;
  }
  while (*two)
  {
	if (*two != '*')
	  write(1, two, 1);
	two++;
  }
}

void
  ft_union(char *one, char *two)
{
  int	i;
  int	j;

  i = 0;
  no_doubles(one);
  no_doubles(two);
  while (one[i])
  {
	j = 0;
	while (two[j])
	{
	  if (one[i] == two[j])
		two[j] = '*';
	  j++;
	}
	i++;
  }
  print_union(one, two);
}

int
  main(int argc, char **argv)
{
  if (argc == 3)
	ft_union(argv[1], argv[2]);
  write(1, "\n", 1);
  return (0);
}
