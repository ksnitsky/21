#include "get_next_line.h"

static int
  gnl_strlen(char *str)
{
  int	len;

  if (!str)
    return (0);
  len = 0;
  while (str[len])
    len++;
  return (len);
}

static char
  *gnl_charjoin(char *str, char c)
{
  char	*newstr;
  int	len;
  int	index;

  if (!str)
  {
	if (!(newstr = malloc(sizeof(char) * BUFFER_SIZE + 1)))
	  return (NULL);
	index = 0;
	if (c != '\n')
	  newstr[index++] = c;
	newstr[index] = '\0';
	return (newstr);
  }
  if (c == '\n')
	return (str);
  len = gnl_strlen(str);
  if (!(newstr = malloc(sizeof(char) * len + 2)))
	return (NULL);
  index = -1;
  while (str[++index])
	newstr[index] = str[index];
  free(str);
  newstr[len++] = c;
  newstr[len] = '\0';
  return (newstr);
}

int
  get_next_line(char **line)
{
  char	temp;
  char	*buff;
  int	ret;

  if (!line)
	return (-1);
  ret = 1;
  buff = NULL;
  while ((ret = read(0, &temp, BUFFER_SIZE)))
  {
	if (ret < 0)
	  return (-1);
	buff = gnl_charjoin(buff, temp);
	if (temp == '\n')
	  break ;
  }
  *line = buff;
  return ((ret == 0) ? 0 : 1);
}
