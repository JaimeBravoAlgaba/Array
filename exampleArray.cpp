#include "Array.h"
#include <iostream>

using namespace std;

int main()
{ 
    // Declaration
    Array<int, 4> arr = {1, 2, 3, 4};
    cout << endl << "Declaration: " << arr << endl;

    // You can also assign vectors
    int v [4] = {5, 6, 7, 8};
    arr = v;
    cout << "Assigning a vector: " << arr << endl;

    // You can get the Data pointer and modify an element
    arr.Data()[0] = 10;
    cout << "Access an element using Data(): " << arr << endl;

    // Or you can use [] operator
    arr[1] = 15;
    cout << "Access an element using []: " << arr << endl;

    // You can also use the std namespace functions
    swap(arr[0], arr[1]);
    cout << "Swapping two elements:" << arr << endl;

    // Char typed arrays are printed as strings when using <<
    Array<char, 12> carr = "Hello World!";
    cout << "Char array: " << carr << endl << endl;

    return 0;
}