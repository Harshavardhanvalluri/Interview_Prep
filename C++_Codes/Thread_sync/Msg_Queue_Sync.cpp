#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <any>
#include <thread>
#include <vector>
#include <unistd.h>
#include <stdio.h>



#define MAX_MSG_CNT 5
#define MAX_MSG_SIZE 4

struct message
{
    long msg_type = 1;
    char buffer[MAX_MSG_SIZE];
};

int msgid = 0;

void *send_msg()
{
    int count = 0;
    message msg;
    msg.msg_type = 1;

    while ( count++ < MAX_MSG_CNT )
    {
        memcpy( msg.buffer , &count , sizeof(count) );
        std::cout << "Sending " << count << std::endl;
        // Send the message
        if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1) 
        {
            perror("msgsnd");
            return nullptr;
        }
        sleep(1);
    }
    
    return nullptr;
}

void *recv_msg()
{
    int count = 0;
    int tmp = 0;
    message msg;
    msg.msg_type = 1;
    
    while ( count++ < MAX_MSG_CNT )
    {
        // Send the message
        if (msgrcv(msgid, &msg , sizeof(msg), 1, 0) == -1)
        {
            perror("msgsnd");
            return nullptr;
        }

        memcpy( &tmp , msg.buffer , sizeof(count) );

        std::cout << "Recv:" << tmp << std::endl;
    }
    
    return nullptr;
}

int main() {

    // Example usage
    key_t key = ftok("/tmp/queue.txt", 'A');
    msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    std::thread send_msg_inst(send_msg);
    std::thread recv_msg_inst(recv_msg);

    if ( send_msg_inst.joinable() )
    {
       send_msg_inst.join();
    }
    
    if ( recv_msg_inst.joinable() )
    {
        recv_msg_inst.join();
    }

    std::cout << " Exit " << std::endl;

    return 0;
}
