#include <iostream>

#define QUEUE_MAX_SIZE 3
#define ERROR -1
#define SUCCESS 0

/// @brief  Queue Data structure
typedef struct Queue
{
    int queue[QUEUE_MAX_SIZE] = { 0 } ; 
    int front = 0;
    int rear = 0;
} Queue;

bool empty( Queue *queue )
{
    return (queue->rear == queue->front ? true : false );
}

int full( Queue *queue )
{
    return (queue->front == QUEUE_MAX_SIZE ? true : false );
}

int enqueue( Queue *queue , int value )
{
    if ( queue == nullptr )
    {
        return ERROR;
    }

    queue->queue[queue->front++] = value;
    return SUCCESS;
}

int dequeue( Queue *queue )
{
    if ( queue == nullptr ||  empty(queue) )
    {
        return ERROR;
    }

    return queue->queue[queue->rear++];
}

int main()
{
    Queue *queue_instance = new Queue;

    enqueue( queue_instance , 1 );
    enqueue( queue_instance , 2 );
    enqueue( queue_instance , 3 );
    enqueue( queue_instance , 4 );


    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;
    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;
    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;
    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;
    std::cout << " dequeue " << dequeue(queue_instance) << std::endl;

    return 0;
}