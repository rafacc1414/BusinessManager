#include <iostream>

#define MAJOR_VERSION 0
#define MINOR_VERSION 1
#define MICRO_VERSION 0

int main()
{
    std::printf("BusinessManager App version: %d.%d.%d\n\n",
                MAJOR_VERSION, MINOR_VERSION, MICRO_VERSION);
    return 0;
}
