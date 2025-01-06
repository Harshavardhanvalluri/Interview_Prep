#include <iostream>

using namespace std;

class drv
{
    public:
    drv(){}
    
    void print( int value )
    {
        cout << value << endl;
    }
        
    void print( float value )
    {
        cout << value << endl;
    }
        
    void print( string value )
    {
        cout << value << endl;
    }
};

int main()
{

    drv driver;

    int int_val = 10;
    float flo_val = 123.4;
    string str_val = "Hello";

    driver.print( int_val );

    driver.print( flo_val );

    driver.print( str_val );

    driver.print( int_val );

    return 0;
}