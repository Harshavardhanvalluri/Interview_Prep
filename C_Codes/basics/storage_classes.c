#include <stdio.h>

int main()
{
    /// As good as a local variable.
    auto int x;

    /// Not used much as most of the compilers ignore this these days.
    register int count;

    /// It's scope is limited to  the file.
    /// It stays percistent accross function calls.
    static int counter = 0;

    /// it is used to declare variables and functions in another file
    extern int globalVar;  // Declaration of a variable defined elsewhere

    return 0;
}
