#include "monty.h"

/**
 * f_mod - performs modulus function
 * @head: pointer to the head
 * @counter: iterator
 */

void f_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(doc.file);
		free(doc.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(doc.file);
		free(doc.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = h->next->n % h->n;
	h->next->n = ptr;
	*head = h->next;
	free(h);
}
