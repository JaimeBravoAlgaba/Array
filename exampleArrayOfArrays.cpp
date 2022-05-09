#include "Array.h"
#include <iostream>

using namespace std;

int main()
{ 
    typedef Array<int, 4> Array1x4;
    typedef Array<Array1x4, 2> Array2x4;

    // 1. Inicialization list
    Array2x4 m = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    cout << "1. Initializing with List" << endl << m << endl;

    // 2. Initializing elementwise
    Array2x4 n;
    Array1x4 v1 = {1, 2, 3, 4};
    Array1x4 v2 = {5, 6, 7, 8};

    n[0] = v1;
    n[1] = v2;
    cout << endl << "2. Initializing elementwise" << endl << n << endl;

    // 3. Extracting and modifiying an element
    Array1x4 v3 = n[1];
    swap(v3[0], v3[2]);
    cout << endl << "3. Extracting and modifiying an element" << endl << v3 << endl;

    return 0;
}