#include <iostream>
#include <stdlib.h>

typedef struct Node {
    int id = 0;
    Node *next = nullptr;
} Node;

void print_list( Node *head )
{
	Node* tmp_node = head;
	while( tmp_node != nullptr )
	{
		std::cout << tmp_node->id << ",";
		tmp_node = tmp_node->next;
	}

    std::cout << std::endl;

    return;
}

void insert_node( Node **head , int value )
{
	/// Create new node
	Node *new_node = (Node*)malloc(sizeof(Node));

	new_node->id = value;
	new_node->next = nullptr;

	if( *head == nullptr )
	{
		*head = new_node;
		return;
	}

	Node *tmp_node = *head;
    
    *head = new_node;

    new_node->next = tmp_node;

    return;
}

int main()
{
    Node *head = nullptr;

    insert_node( &head , 1 );
    insert_node( &head , 3 );
    insert_node( &head , 5 );
    insert_node( &head , 6 );
    insert_node( &head , 4 );

    print_list(head);

    return 0;
}
