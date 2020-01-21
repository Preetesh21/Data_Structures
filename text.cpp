#include <iostream>
#include <fstream>
int main(int argc, char * argv[])
{
    std::fstream myfile("input03.txt", std::ios_base::in);

    char  a;
    char b=  (myfile >> a);
    printf("%c",b);
    // while (myfile >> a)
    // {
    //     printf("%f ", a);
    // }

    //getchar();

    return 0;
}