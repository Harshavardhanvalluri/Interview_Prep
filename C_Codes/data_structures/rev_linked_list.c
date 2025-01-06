#include <stdio.h>
#include <stdlib.h>

/// Node struct
typedef struct node
{
    int id;
    struct node *next;
} node;

/// Print list
void print_list( node* head )
{
    if( head == NULL )
    {
        printf("ERROR: Invalid arguments\n");
        return;
    }

    node* print_node = head;

    printf("ID: ");

    while ( print_node != NULL )
    {
        printf("%d, ", print_node->id );
        print_node = print_node->next;
    }

    printf("\n");
       
    return;
}


/// Insert node
void insert_list( node *head, int value )
{
    if( head == NULL || value == 0 )
    {
        printf("ERROR: Invalid arguments\n");
        return; 
    }

    node *tmp_node = head;
    node *new_node = malloc( sizeof(node) );

    if ( new_node == NULL )
    {
        printf("ERROR: Memory allocation failed\n");
        return;
    }

    new_node->id = value;

    while ( tmp_node->next != NULL )
    {
        tmp_node = tmp_node->next;
    }

    tmp_node->next = new_node;

    return;
}

/// delete node
void delete_node( node *head,  int node_id )
{
    if ( node_id == 0 )
    {
        printf("ERROR: Invalid arguments\n");
        return; 
    }

    node *tmp_node = head;
    node *prev_node = NULL;

    while ( tmp_node != NULL )
    {
        if ( tmp_node->id == node_id )
        {
            /// perform delete operation
            prev_node->next = tmp_node->next;
            free(tmp_node);
            return;
        }
        prev_node = tmp_node;
        tmp_node = tmp_node->next;
    }

    printf("%d node not found \n", node_id );
    
    return;
}

int get_list_size( node *head )
{
    if ( head == NULL )
    {
        printf("ERROR: Invalid input arguments");
        return -1;
    }

    int list_size = 0;
    node *tmp_node = head;

    while ( tmp_node->next != NULL )
    {
        list_size++;
        tmp_node = tmp_node->next;
    }

    return list_size;
}


void rev_linked_list( node **head )
{
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while ( current != NULL )
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/// Sort linked list based on ID's
void sort_list( node *head )
{
    if ( head == NULL )
    {
        printf("ERROR: Invalid input arguments");
        return;
    }

    node *current_node = head;
    node *index_node = NULL;
    int value = 0;

    while ( current_node != NULL )
    {
        index_node = current_node->next;
        /// Compare index node value
        while ( index_node != NULL )
        {
            if ( current_node->id > index_node->id )
            {
                // Copy current node value
                value = current_node->id;

                /// swap current value with the updated value
                current_node->id = index_node->id;

                /// update the index value
                index_node->id = value;
            }
            
            index_node = index_node->next;
        }
        current_node = current_node->next;
    }
}

int main()
{
    node* head = malloc(sizeof(node));

    head->id = 10;
    head->next = NULL;
    
    /// Inserting elements to list
    insert_list( head , 80 );
    insert_list( head , 10 );
    insert_list( head , 8 );
    insert_list( head , 60 );
    insert_list( head , 23 );
    insert_list( head , 19 );

    /// Printing list
    print_list ( head );

    /// rev list
    rev_linked_list( &head );

    /// Printing list
    print_list ( head );

    return 0;
}
