#ifndef __ARRAY_
#define __ARRAY_

#include <iostream>
#include <initializer_list>
#include <cstring>
using namespace std;

template <typename T, size_t S>
class Array
{
    public:

        class Iterator
        {
            // Tags
            
            using iterator_category = bidirectional_iterator_tag;
            using difference_type = size_t;
            using value_type = T;
            using pointer = T*;
            using reference = T&;

            public:
                // Constructor
                Iterator(pointer ptr) : m_Pointer(ptr) { }

                // Reference operator
                reference operator*()  const { return *m_Pointer; }
                // Pointer operator
                pointer   operator->() const { return  m_Pointer; }

                // Pre-Increment operator.
                Iterator& operator++()    { ++m_Pointer; return *this; }
                // Post-Increment operator.
                Iterator  operator++(int) { Iterator tmp = *this; ++(*this); return  tmp; }

                // Pre-Decrement operator.
                Iterator& operator--()    { --m_Pointer; return *this; }
                // Post-Decrement operator.
                Iterator  operator--(int) { Iterator tmp = *this; --(*this); return  tmp; }
                
                // Equality comparison operator.
                friend bool operator==(const Iterator& a, const Iterator& b)
                { return a.m_Pointer == b.m_Pointer; }
                // Inequality comparison operator.
                friend bool operator!=(const Iterator& a, const Iterator& b)
                { return a.m_Pointer != b.m_Pointer; }

            private:
                pointer m_Pointer;
        };

        // Default constructor.
        Array()
        { 
            m_Data = new T[S];
        }

        // Copy constructor.
        Array(const Array<T, S>& other)
        {
            m_Data = new T[S];
            for(size_t i=0; i<S; ++i)
                m_Data[i] = other[i];
        }
        
        // Vector constructor.
        Array(const T* v)
        {   
            m_Data = new T[S];
            for(size_t i=0; i<S; ++i)
                m_Data[i] = v[i];
        }

        // Initializer list constructor.
        Array(const initializer_list<T>& array)
        {
            m_Data = new T[S];            
            for(size_t i = 0; i<S; ++i)
                m_Data[i] = array.begin()[i];
        }

        ~Array()
        {
            delete[] m_Data;
        }

        // Returns the number of elements in the array.
        constexpr size_t Size() const { return S; }

        // Reference by index
        T& operator[](const size_t index) { return m_Data[index]; }
        // Const reference by index
        const T& operator[](const size_t index) const { return m_Data[index]; }

        // Assignation by reference
        Array<T,S>& operator=(const Array<T,S>& other)
        {
            for(size_t i=0; i<S; ++i)
                m_Data[i] = other[i];
            
            return *this;
        }

        // Data pointer getter
        T* Data(){ return m_Data; }
        // Const data pointer getter
        const T* Data() const { return m_Data; }

        // Iterator begin
        Iterator begin() { return Iterator(&m_Data[0]);}
        // Iterator end
        Iterator end() { return Iterator(&m_Data[S]);} // S position is out of bounds!
        
    private:
        T* m_Data;
};

// Ostream operator
template <typename T, size_t S>
ostream& operator<<(ostream& stream, const Array<T, S>& array)
{
    size_t i;
    stream << "{";
    for(i=0; i<S-1; ++i)
        stream << array[i] << ",";
        
    return stream << array[i] << "}";
}

// Ostream operator char specialization
template <size_t S>
ostream& operator<<(ostream& stream, const Array<char, S>& array)
{
    size_t i;
    for(i=0; i<S; ++i)
        stream << array[i];
        
    return stream;
}

#endif