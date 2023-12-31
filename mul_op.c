#include "monty.h"

/**
 * f_mul - multiplies stack elements.
 * @head: pointer to the stack head
 * @counter: iterator
 */

void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, ptr;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(doc.file);
		free(doc.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ptr = h->next->n * h->n;
	h->next->n = ptr;
	*head = h->next;
	free(h);
}
