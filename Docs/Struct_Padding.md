### Structure Padding in C

Here in the below example we see that the padding of the structure depend on the largest data type present in the structure.

```
// Structure size without padding
typedef struct {
    signed long int value1;
    char name;
    double Double; 
    float value2;
} structure;

 ./struct_pad_bin
Size: 32
Size (signed long int): 8
Size (char): 1
Size (float): 4
Size (Double): 8

// Structure size with 4 bytes padding
typedef struct __attribute__((packed, aligned(4))) {
    signed long int value1;
    char name;
    double Double; 
    float value2;
} structure;

./struct_pad_bin
Size: 24
Size (signed long int): 8
Size (char): 1
Size (float): 4
Size (Double): 8

// Structure size with 1 byte padding
typedef struct __attribute__((packed, aligned(1))) {
    signed long int value1;
    char name;
    double Double; 
    float value2;
} structure;

./struct_pad_bin
Size: 21
Size (signed long int): 8
Size (char): 1
Size (float): 4
Size (Double): 8

```