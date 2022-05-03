#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

int main()
{
    Array<string, 3> array = {"Hola", "Hello", "Hallo"};
    Array<string, 3> array2 = array;
    //array = {"Hola", "Hello", "Hallo"};

    array2[2]="Bonjour";

    for(size_t i=0; i<array.Size(); ++i)
        cout << array[i] << endl;

    cout << endl;

    for(size_t i=0; i<array2.Size(); ++i)
        cout << array2[i] << endl;
    
    cout << array2.Size();

    return 0;
}