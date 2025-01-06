### Memory Management in C
1. Text Segment (Code Segment):
	The text segment is also known as the code segment.
	It contains the executable code of the program.
	The code segment is read-only, and the instructions are fetched from this segment during the program's execution.
2. Data Segment:
	The data segment is divided into two parts:
	a. Initialized Data:
		- Contains global and static variables that are initialized before the program starts.
		- Variables in this segment have a fixed size and are initialized with explicit values.
	b. Uninitialized Data (BSS - Block Started by Symbol):
		- Contains global and static variables that are uninitialized or explicitly initialized to zero.
		- Variables in this segment are initialized to zero by the operating system at program startup.
3. Heap:
	- The heap is the dynamic memory area that is used for dynamic memory allocation.
	- It is managed by functions like malloc(), calloc(), realloc(), and free().
	- Memory allocated on the heap persists until it is explicitly deallocated using free().
4. Stack:
	- The stack is used for local variables and function call management.
	- Each function call creates a new stack frame, which includes local variables, function parameters, and return addresses.
	- The stack is a last-in, first-out (LIFO) data structure.
	- Memory allocated on the stack is automatically reclaimed when a function exits.
5. Memory-Mapped Segment:
	- This segment is used for memory-mapped files and shared memory.
	- It allows processes to communicate by mapping a shared portion of memory into their respective address spaces.
6. Constant Segment (Read-Only Data Segment):
	- The constant segment contains constants and string literals.
	- String literals, for example, are stored in this segment, and they are typically read-only.