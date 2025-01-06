#include <iostream>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


// Template class definition
template <typename T>
class Event {
public:
    Event(T value) : data(value) {}


    Event(){}

    void add_event( T value )
    {
        data = value;
    }

    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

private:
    long message_type = 1;
    T data;
};

// Define a message queue class
template <typename M>
class MessageQueue {
public:
    MessageQueue(key_t key) {
        msgid_ = msgget(key, IPC_CREAT | 0666);
        if (msgid_ == -1) {
            perror("msgget");
            std::exit(EXIT_FAILURE);
        }
    }

    ~MessageQueue() {
        if (msgctl(msgid_, IPC_RMID, nullptr) == -1) {
            perror("msgctl");
        }
    }

    void sendMessage(const M& message) {
        if (msgsnd(msgid_, &message, sizeof(message), 0) == -1) {
            perror("msgsnd");
        }
    }

    M receiveMessage() {
        M message;
        if (msgrcv(msgid_, &message, sizeof(message), 0, 0) == -1) {
            perror("msgrcv");
            std::exit(EXIT_FAILURE);
        }
        return message;
    }

private:
    int msgid_;
};

int main() {
    
    Event<int> *int_msg = new Event<int>(10);
    Event<double> *double_msg = new Event<double>(12.4);

    // Example usage
    key_t key = ftok("/tmp/queue.txt", 'A');
    MessageQueue<Event<int>> messageQueue(key);

    messageQueue.sendMessage(*int_msg);

    Event<int> Rec_int_msg = messageQueue.receiveMessage();


    Rec_int_msg.printData();
    return 0;
}
