#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

int main()
{
    //void *ptr = NULL; // Same as void* ptr=0;

    int var = 8;
    void *ptr = &var;
    int *ptr2 = &var;              // same as before
    double *ptr3 = (double *)&var; // casting int as double

    *ptr2 = 10; // this a way to access data in the pointer
    LOG(var);
    *ptr3 = 10; // this does not work because of type inference?
    LOG(var);

    // heap memory
    char *buffer = new char[8]; // Allocate 8 bites
    memset(buffer, 0, 8);

    // Pointer to pointer
    char **ptr4 = &buffer;

    delete[] buffer; // Cleaning allocate dmemory
    std::cin.get();
}
