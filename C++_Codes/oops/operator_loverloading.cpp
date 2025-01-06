#include <iostream>

using namespace std;

class sum
{
    public:

    sum( int a )
    : val_a( a )
    {}


    sum operator + ( const sum &object )
    {
        cout << "val_a: " << val_a  << " object: " << object.val_a << endl;
        sum obj(val_a + object.val_a);
        return obj;
    }

    void print()
    {
        cout << endl;
        cout << val_a << endl;
    }

    private:
    int val_a = 0;
};


int main()
{
    sum object1(23);
    sum object2(30);

    sum object3 = object1 + object2;

    object3.print();

    return 0;
}
