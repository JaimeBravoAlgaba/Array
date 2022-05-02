#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

int main()
{
    Array<string, 3> array = {"Hola", "Hello", "Hallo"};
    //array = {"Hola", "Hello", "Hallo"};

    for(size_t i=0; i<array.Size(); ++i)
        cout << array[i] << endl;
    
    cout << array.Size();

    return 0;
}