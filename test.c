
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	node
{
	int			x;
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
	new_node->x = n;
	new_node->next = NULL;

	if (q->tail != NULL)
		q->tail->next = new_node;
	q->tail = new_node;
	if (q->head == NULL)
		q->head = new_node;
	printf("x = %d\n", new_node->x); 
}
int main(void)
{
	int	i;
	queue	q;

	init_queue(&q);
	i = 0;
	while (i < 10)
	{
		// printf("i = %d\n", i);
		enqueue(&q, i);
		i++;
	}
	return (0);
}