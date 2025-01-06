#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mutex_lock;
int count = 0;
std::condition_variable con_var;

#define MAX_COUNTER 20

void *print_even()
{
    while ( count < MAX_COUNTER )
    {
        std::unique_lock<std::mutex> lock(mutex_lock);
        if ( count % 2 == 0 )
        {
            std::cout << count++ << std::endl;
            con_var.notify_one();
        }
        else
        {
            con_var.wait(lock, [] { return count; }); 
        }   
    }
    return nullptr;
}

void *print_odd()
{
    while ( count < MAX_COUNTER )
    {
        std::unique_lock<std::mutex> lock(mutex_lock);
        if ( count % 2 != 0 )
        {
            std::cout << count++ << std::endl;
            con_var.notify_one();
        }
        else
        {
            // waiting 
            con_var.wait(lock, [] { return count; }); 
        }   
    }
    return nullptr;
}

int main()
{
    std::thread print_odd_thread(print_odd);
    std::thread print_even_thread(print_even);

    print_odd_thread.join();
    print_even_thread.join();

    return 0;
}