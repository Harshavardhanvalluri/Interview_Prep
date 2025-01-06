#include <iostream>

#define MAX_STACK_SIZE 100
#define SUCCESS 0
#define ERROR -1

typedef struct stack {
    int data[MAX_STACK_SIZE] = {0};
	int top = 0;
} stack;


int init_stack( stack *stack )
{
    if ( stack == nullptr)
	{
		return ERROR;
	}

	stack->top = -1;
    return SUCCESS;
}

bool isempty( stack *stack )
{
	return ( stack->top == -1 );
}

bool isfull( stack *stack )
{
	return ( stack->top == MAX_STACK_SIZE - 1 );
}

int push( stack *stack , int element)
{
	if ( stack == nullptr || isfull(stack) )
	{
		printf("Stack is full \n");
		return -1;
	}

	stack->data[++stack->top] = element;
	
	return SUCCESS;
}

int pop(stack *stack)
{
	if ( stack == nullptr || isempty(stack) )
	{
		printf("Stack is empty \n");
		return ERROR;
	}

	return stack->data[stack->top--];
}

int peek(stack *stack)
{
    if ( stack == nullptr || isempty(stack) )
	{
		printf("Stack is empty ");
		return ERROR;
	}

	return stack->data[stack->top];
}

int main()
{
    stack *stack_ = new stack;

    init_stack(stack_);

    push( stack_ , 12 );
    push( stack_ , 2 );
    push( stack_ , 1 );
    push( stack_ , 5 );

    std::cout << "peek:" << peek(stack_) << std::endl;
    std::cout << "pop:" << pop(stack_) << std::endl;
    std::cout << "pop:" << pop(stack_) << std::endl;
    std::cout << "pop:" << pop(stack_) << std::endl;
    std::cout << "pop:" << pop(stack_) << std::endl;
    std::cout << "peek:" << peek(stack_) << std::endl;

    return 0;
}
