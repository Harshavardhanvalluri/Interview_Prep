### Storage class in C
1. auto:
    - The auto storage class is the default storage class for local variables.
    - Variables declared as auto are local to the block they are defined in.
    - It is rarely used explicitly, as local variables are considered auto by default.
2. register:
    - The register storage class is used to suggest to the compiler that a variable should be stored in a register for faster access.
    - The use of register is merely a hint to the compiler, and it may choose to ignore it.
    - Modern compilers are generally efficient at managing registers, so the use of register is less common in contemporary code.
3. static:
    - The static storage class has different meanings based on where it is used:
    Static Local Variables:
    - A static local variable retains its value between function calls.
    - It is initialized only once, and its value persists across multiple invocations of the function.
    Static Global Variables:
    - A static global variable is visible only within the file it is declared in.
    - It is not accessible from other files using the extern keyword.
    Static Functions:
    - A static function is limited to the file in which it is declared.
    - It is not accessible from other files using the extern keyword.
4. extern:
    - The extern storage class is used to declare variables or functions that are defined in another file.
    - It tells the compiler that the actual definition exists somewhere else.

### Qualifiers:
1. const: Used to declare variables as constants, indicating that their values cannot be modified.
2. volatile: Indicates to the compiler that a variable's value may change at any time, without any action being taken by the code the compiler finds nearby.