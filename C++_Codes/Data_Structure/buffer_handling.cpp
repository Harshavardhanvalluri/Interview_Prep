#include <iostream>
#include <any>
#include <string>

#define MAX_BUFF_SIZE 10

template<typename T>
class Message {
    public:
    Message( T buffer)
    {
        this->data = buffer;
    }

    T get_buffer()
    {
        return std::any_cast<T>(data);
    }

    private:
    long messageType = 1;
    std::any data;
};



int main() {

    int value = 10;
    // Use std::any as a buffer for passing data
    std::any buffer = new Message<int>( value );

    std::cout << "Size : " << sizeof(buffer) << std::endl;

    Message<int> *msg = std::any_cast<Message<int>*>(buffer);

    std::cout << "value:" <<  msg->get_buffer() << std::endl;

    return 0;
}
