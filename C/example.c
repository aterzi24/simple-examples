#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct var {
	int po;
	struct var *next;
}var;

int main()
{
	var *head, *temp;
	int num;
	head = NULL;
	while (1)
	{
		scanf("%d", &num);
		if (num == -1)
			break;
		temp = (var *) malloc(sizeof(var));
		temp->po = num;
		temp->next = head;
		head = temp;
	}
	temp = head;
	while (temp)
	{
		printf("%d\n", temp->po);
		temp = temp->next;
	}
	return 0;
}
