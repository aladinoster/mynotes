#include <iostream>
#include <array>

#define LOG(x) std::cout << x << std::endl;
int main()
{
    int example[5]; //array of 5 integers; Data is allocated in a sequence.

    int *ptr = example; // because example is a pointer to the head of the array where the first datum is located

    example[2] = 4;
    LOG(example[2]);
    *(ptr + 2) = 5; // Moving in memory (Adds 2 int memory positions 1 int 4 bytes -> 8 bytes forward)
    LOG(example[2]);
    *(int *)((char *)ptr + 8) = 6; // cast the pointer as char, moves +8  bytes forward) -> cast as int pointer (because we want to assign 4bytes) -> dereference to assign effeciently de value not the address
    LOG(example[2]);

    example[0] = 3; //assign 3 to the 0-index position of the array
    example[4] = 4; // assign the last index of the array
    LOG(example[0]);
    LOG(example); // this prints memory since it is apointer.

    // example[-1] = 4; this is possible in relase mode not debug. (Safety check)
    for (int i = 0; i < 5; i++)
        example[i] = 2;

    LOG(example[3]);

    int *another = new int[5]; // array allocated in heap memory
    for (int i = 0; i < 5; i++)
        another[i] = 2;
    delete[] another;

    // Estimating the n
    int count = sizeof(example) / sizeof(int); // only on stack allocated array
    LOG("I am");
    LOG(count); // Number of positions of the array.

    // C++ 11 (Safer in terms of memory handling)
    std::array<int, 5> newarray; // A bit of overhead;
    for (int i = 0; i < newarray.size(); i++)
    {
        newarray[i] = 2;
    }
    LOG(newarray[0])

    std::cin.get();
}