
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	node
{
	int			x;
	struct node	*preview;
	struct node	*next;
}	node;

typedef struct 
{
	node	*head;
	node	*tail;
}	queue;

void	init_queue(queue *q)
{
	q->head = NULL;
	q->tail = NULL;
}

void	enqueue(queue *q, int n)
{
	node	*new_node;

	new_node = malloc(sizeof(node));
	if (!new_node)
		return ;
	new_node->x = n;
	new_node->preview = NULL;
	new_node->next = NULL;

	if (q->tail != NULL)
	{
		q->tail->next = new_node;
		new_node->preview = q->tail;
	}
	q->tail = new_node;
	if (q->head == NULL)
		q->head = new_node;
}

int main(void)
{
	int i = 2;
	int j = 42;
	printf("%d\n", i - j);
	return (0);
}