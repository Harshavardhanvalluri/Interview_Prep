#include <iostream>

#define QUEUE_MAX_SIZE 5
#define ERROR -1
#define SUCCESS 0

/// @brief  Queue Data structure
typedef struct Queue
{
    int queue[QUEUE_MAX_SIZE] = { 0 } ; 
    int front = 0;
    int rear = 0;
} Queue;

void init_queue( Queue *queue )
{
    queue->front = -1;
    queue->rear = -1;
}

bool isempty( Queue *queue )
{
    return (queue->rear == -1 && queue->front == -1);
}

int isfull( Queue *queue )
{
    return ( queue->front == (queue->rear + 1) % QUEUE_MAX_SIZE  );
}

int enqueue( Queue *queue , int value )
{
    if (queue == nullptr || isfull(queue))
    {
        std::cout << "Queue is full. Cannot enqueue.\n";
        return ERROR;
    }

    if ( isempty(queue) )
    {
        queue->front = 0;
    }
    
    queue->rear = ( queue->rear + 1 ) % QUEUE_MAX_SIZE;
    queue->queue[queue->rear] = value;
    
    return SUCCESS;
}

int dequeue( Queue *queue )
{
    if ( isempty(queue) )
    {
        std::cout << "Queue is empty. Cannot dequeue.\n";
        return ERROR;
    }

    int element = queue->queue[queue->front] ;
    
    if ( queue->front == queue->rear )
    {
        init_queue(queue);
    }
    else
    {
        queue->front = ( queue->front + 1 ) % QUEUE_MAX_SIZE;
    }

    return element;
}

int main()
{
    Queue *queue_instance = new Queue;

    init_queue(queue_instance);

    enqueue( queue_instance , 1 );
    enqueue( queue_instance , 2 );
    enqueue( queue_instance , 3 );
    enqueue( queue_instance , 4 );


    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;
    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;
    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;
    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;

    return 0;
}