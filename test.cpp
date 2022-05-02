#include <iostream>
#include "Array.h"

using namespace std;

int main()
{
    Array<string, 4> array;
    array[0] = "Hola";
    array[1] = "Hello";
    array[2] = "Bonjour";
    array[3] = "Hallo";

    for(size_t i=0; i<array.Size(); ++i)
        cout << array[i] << endl;

    return 0;
}