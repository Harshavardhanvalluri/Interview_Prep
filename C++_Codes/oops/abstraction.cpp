#include <iostream>

using namespace std;

class stack
{
    public:
    stack( int stack_size )
    : STACK_MAX_SIZE( stack_size )
    {
        cout << "Stack size: " << stack_size << endl;
        ds_stack = new Ststack;
        ds_stack->stack_data = new int[stack_size];
    }

    bool stackfull()
    {
        return ( ds_stack->counter == STACK_MAX_SIZE );
    }

    bool stackempty()
    {
        return (ds_stack->counter == 0);
    }

    int push( int value )
    {
        if ( stackfull() )
        {
            cout << "Stack is full" << endl;
            return -1;
        }
        
        ds_stack->stack_data[ds_stack->counter++] = value;

        return 0;
    }

    int pop()
    {
        int value = 0;
        if ( stackempty() )
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return ds_stack->stack_data[--ds_stack->counter];
    }

    ~stack()
    {
        delete ds_stack->stack_data;
        delete ds_stack;
    }

    private:

    /// @brief  Data abstraction
    int STACK_MAX_SIZE = 0;

    struct Ststack
    {
        int *stack_data = nullptr;
        int counter = 0;
    };

    Ststack *ds_stack;

};

int main()
{
    int stack_size = 4;

    stack stack_obj( stack_size );

    stack_obj.push(12);
    stack_obj.push(2);
    stack_obj.push(13);
    stack_obj.push(24);

    cout << stack_obj.pop() << endl;
    cout << stack_obj.pop() << endl;
    cout << stack_obj.pop() << endl;
    cout << stack_obj.pop() << endl;
    
    return 0;
}
