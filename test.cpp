#include <iostream>
#include <array>
#include "Array.h"

using namespace std;

template<typename T,size_t S>
ostream& operator<<(ostream& stream, array<T,S> arr)
{
    stream << "{";

    size_t i;
    for(i=0; i<S-1; ++i)
        stream << arr[i] << ",";

    return stream << arr[i] << "}";
} 

int main()
{
    //array<string, 3> a ={"3", "2", "1"};
    typedef array<string, 3> type1;
    typedef Array<type1 , 3> type2;

    type1 a, b, c;
    a = {"hola", "adios", "buenas tardes"};
    b = {"España", "Francia", "Portugal"};
    c = {"Jaime", "Bravo", "Algaba"};

    type2 myArray = {a,b,c};

    a = {"Jesus", "Maria", "Jose"};
    swap(b[1], b[2]);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << myArray << endl;

    return 0;
}