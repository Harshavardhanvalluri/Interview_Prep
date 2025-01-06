#include <iostream>

using namespace std;

class Engine
{
    public:
    Engine( string eng_name )
    : protected_engine_name( eng_name )
    {
        cout << "This is Engine" << endl;
    }

    Engine(){};

    virtual int get_cyclinder() = 0;

    protected:
    string protected_engine_name;

    int engine = 10;

    int vers;

    private:
    string private_brand_name;
};

class V8 : public Engine
{
    public:
    V8( string eng_name , int value )
    : Engine( eng_name ) ,
      cylinder( value )
    {
        cout << "This is V" << get_cyclinder() << " engine" << endl;
    }

    int get_cyclinder()
    {
        return cylinder;
    }

    int get_version()
    {
        return vers;
    }

    private:
    int cylinder = 0;
};

int main()
{
    Engine* eng = new V8( "VW" , 8 );
    return 0;
}