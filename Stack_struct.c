#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	int length;
	int size;
	int *val;
}stack;
	
stack* create(int length)
{
	stack *s;
    s = (stack *)malloc(sizeof(stack));
    s->val = (int *)malloc(sizeof(int)*length);
    s->size = 0;
    s->length = length; 
    return s;
} 

void pop(stack *s)
{
	if(s->size == 0)
	{
		printf("\nStack is Empty\n");
	}
	else
	{
		s->size--;
		printf("\nElement is Popped\n");
	}
}
void push(stack *s,int key)
{
	if(s->size == s->length)
	{
		printf("\nStack Is Full");
	}
	else
	{
		s->val[s->size]=key;
		s->size++;
		printf("\nElement is PUSHED\n");
	}
}

void display(stack *s)
{
	int i=s->size-1;
	while(i >= 0)
	{
		printf("\n- %d -",s->val[i]);
		i--;
	}
	
}

int main()
{
	int choice=0,n,key,size;
	printf("Enter size of Stack");
	scanf("%d",&size);
	stack *s = create(size);
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Exit\nEnter Choice::");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				printf("\nEnter element to PUSH::");
				scanf("%d",&key);
				push(s,key);
				break;
			case 2:
				pop(s);
				break;
			case 3:
				display(s);
				break;
			case 4:
				exit(0);
			default:
				printf("\nEnter Correct choice::");
				break;
		}
		n--;
	}
	return 0;
}
