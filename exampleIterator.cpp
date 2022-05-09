#include "Array.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{ 
    Array<string, 3> arr = {"Madrid", "Barcelona", "Valencia"};
    Array<string, 3>::Iterator it {arr.Data()};

    // 1. Range-based iterator
    cout << endl << ":  Range-based Iterator" << endl;
    for(auto item : arr)
        std::cout << "\t" << item << endl;

    // 2. Forward iterator
    cout << endl << ">> Forward Iterator" << endl;
    for(it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << "\t" << *it << endl;
    }

    // 3. Backwards iterator
    cout << endl << "<< Backwards Iterator" << endl;
    for(it = --arr.end(); it != --arr.begin(); --it)
    {
        std::cout << "\t" << *it << endl;
    }

    return 0;
}