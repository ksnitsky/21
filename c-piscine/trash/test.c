/*--ex00--*/
#include <stdio.h>
int		main()
{
	t_list* temp;

	temp = ft_create_elem("klad");
	
	printf(" %s", temp->data);
	printf(" %p", temp->next);
	temp->next = ft_create_elem("oqw");
	printf(" %s", (*temp).next->data);
	printf(" %p", temp->next);
}

/*--ex01--*/
#include <stdio.h>
int         main(void)
{
    t_list *a;

    a = ft_create_elem("Hello");
    a->next = ft_create_elem("World");
    a->next->next = ft_create_elem("Bye");
    printf("%s\n", a->data);
	printf("%p\n", a->next);
    printf("%s\n", a->next->data);
	printf("%p\n", a->next->next);
    printf("%s\n", a->next->next->data);
	printf("%p\n\n", a->next->next->next);
    ft_list_push_front(&a, "Bonjour");
    printf("%s\n", a->data);
	printf("%p\n", a->next);
    printf("%s\n", a->next->data);
	printf("%p\n", a->next->next);
    printf("%s\n", a->next->next->data);
	printf("%p\n", a->next->next->next);
    printf("%s\n", a->next->next->next->data);
	printf("%p\n", a->next->next->next->next);
    return (0);
}

/*--ex02--*/
#include <stdio.h>
t_list	*ft_create_elem(void *data)
{
	t_list* temp;

	temp = (t_list*)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->data = data;
	return (temp);
}

int         main(void)
{
    t_list *a;

    a = ft_create_elem("Hello");
    a->next = ft_create_elem("World");
    a->next->next = ft_create_elem("Bye");
	printf("%s\n", a->data);	
	printf("%p\n", a->next);
    printf("%s\n", a->next->data);
	printf("%p\n", a->next->next);
    printf("%s\n", a->next->next->data);
	printf("%p\n\n", a->next->next->next);
	printf("%d\n", ft_list_size(a));
	printf("%s\n", a->data);
	printf("%p\n", a->next);
    printf("%s\n", a->next->data);
	printf("%p\n", a->next->next);
    printf("%s\n", a->next->next->data);
	printf("%p\n", a->next->next->next);
    return (0);
}

/*--ex03--*/
#include <stdio.h>
t_list	*ft_create_elem(void *data)
{
	t_list* temp;

	temp = (t_list*)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->data = data;
	return (temp);
}

int         main(void)
{
    t_list *a;
	t_list *b;
    a = ft_create_elem("Hello");
    a->next = ft_create_elem("World");
    a->next->next = ft_create_elem("Bye");
	b = ft_list_last(a);
	printf("%s\n", b->data);	
	printf("%p\n", b->next);
    return (0);
}

/*--ex04--*/
#include <stdio.h>
t_list	*ft_create_elem(void *data)
{
	t_list* temp;

	temp = (t_list*)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->data = data;
	return (temp);
}

int         main(void)
{
    t_list *a;

    a = ft_create_elem("Hello");
    a->next = ft_create_elem("World");
    a->next->next = ft_create_elem("Bye");
	printf("%s\n", a->data);	
	printf("%p\n", a->next);
    printf("%s\n", a->next->data);
	printf("%p\n", a->next->next);
    printf("%s\n", a->next->next->data);
	printf("%p\n\n", a->next->next->next);
	ft_list_push_back(&a, "Bonjour");
    printf("%s\n", a->next->next->next->data);
	printf("%p\n", a->next->next->next->next);
	printf("%s\n", a->next->next->data);
	printf("%p\n\n", a->next->next->next);
    return (0);
}

/*--ex05--*/
#include <stdio.h>
t_list	*ft_create_elem(void *data)
{
	t_list *temp;

	temp = (t_list*)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->data = data;
	return (temp);
}

int         main(int argc, char **argv)
{
	t_list *temp = NULL;

	temp = ft_list_push_str(argc, argv);
	while (temp != NULL)
	{
		printf("%s\n", temp->data);
		printf("%p\n", temp->next);
		temp = temp->next;
	}
    return (0);
}

/*
t_list	*ft_list_push_str(int size, char **strs)
{
	t_list *temp;
	t_list *tmp1;

	if (size == 0 || strs == NULL)
		return (0);
	temp1 = ft_create_elem(strs[--size]);
	tmp1 = temp;
	while (size > 0)
	{
		tmp1->next = ft_create_elem(strs[--size]);
		tmp1 = tmp1->next;
	}
	return (temp);
}
*/

/*--ex06--*/

