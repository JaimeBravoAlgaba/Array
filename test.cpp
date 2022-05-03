#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

int main()
{
    Array<int, 3> array = {1, 2, 3};
    Array<int, 3> array2 = array;

    swap(array[0], array[1]);

    cout << "First array:" << endl;
    for(auto item : array)
        cout << item << endl;

    cout << endl << "Second array:" << endl;

    for(auto item : array2)
        cout << item << endl;

    return 0;
}