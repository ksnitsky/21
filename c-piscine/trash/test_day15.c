#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
t_btree		*btree_create_node(void *item)
{
	t_btree *node;

	node = (t_btree*)malloc(sizeof(t_btree));
	node->left = NULL;
	node->right = NULL;
	node->item = item;
	return (node);
}

void	ft_putstr(void *str)
{
	int count;
	count = 0;
	while (*(char *)(str + count) != '\0')
	{
		write(1, str + count, 1);
		count++;
	}
}

int   main(void)
{
	void (*f)(void *) = &ft_putstr;
  t_btree *a;
  a = btree_create_node("1\n");
  a->left = btree_create_node("2\n");
  a->right = btree_create_node("3\n");
  a->left->left = btree_create_node("4\n");
  a->left->right = btree_create_node("5\n");
  btree_apply_suffix(a, f);
}