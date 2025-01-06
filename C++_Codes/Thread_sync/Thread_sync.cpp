#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#define MAX_COUNT 10

std::mutex mutex;
std::condition_variable con_var;
int count;


void* even_thread()
{
    while ( count < MAX_COUNT )
    {
        std::unique_lock<std::mutex> lock(mutex);
        if ( count % 2 == 0 )
        {
            std::cout << count++ << std::endl;
            con_var.notify_one();
        }
        else
        {
            con_var.wait( lock , []{ return count; } );
        }
    }
    return nullptr;
}

void* odd_thread()
{
    while (  count < MAX_COUNT )
    {
        std::unique_lock<std::mutex> lock(mutex);
        if ( count % 2 != 0 )
        {
            std::cout << count++ << std::endl;
            con_var.notify_one();
        }
        else
        {
            con_var.wait( lock , []{ return count; } );
        }
    }

    return nullptr;
}


int main()
{
    std::thread even_thread_ins ( even_thread ); 
    std::thread odd_thread_ins ( odd_thread );

    even_thread_ins.join();
    odd_thread_ins.join();

    return 0;
}
