#ifndef __ARRAY_
#define __ARRAY_

#include <initializer_list>
#include <cstring>
using namespace std;

template <typename T>
class ArrayIterator
{
    // Tags
    
    using iterator_category = bidirectional_iterator_tag;
    using difference_type = size_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    public:
        // Constructor
        ArrayIterator(pointer ptr) : m_Pointer(ptr) { }

        // Reference operator
        reference operator*()  const { return *m_Pointer; }
        // Pointer operator
        pointer   operator->() const { return  m_Pointer; }

        // Pre-Increment operator.
        ArrayIterator& operator++()    { ++m_Pointer; return *this; }
        // Post-Increment operator.
        ArrayIterator  operator++(int) { ArrayIterator tmp = *this; ++(*this); return  tmp; }

        // Pre-Decrement operator.
        ArrayIterator& operator--()    { --m_Pointer; return *this; }
        // Post-Decrement operator.
        ArrayIterator  operator--(int) { ArrayIterator tmp = *this; --(*this); return  tmp; }
        
        // Equality comparison operator.
        friend bool operator==(const ArrayIterator& a, const ArrayIterator& b)
        { return a.m_Pointer == b.m_Pointer; };
        // Inequality comparison operator.
        friend bool operator!=(const ArrayIterator& a, const ArrayIterator& b)
        { return a.m_Pointer != b.m_Pointer; };

    private:
        pointer m_Pointer;
};

template <typename T, size_t S>
class Array
{
    public:
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
        ArrayIterator<T> begin() { return ArrayIterator<T>(&m_Data[0]);}
        // Iterator end
        ArrayIterator<T> end() { return ArrayIterator<T>(&m_Data[S]);} // S position is out of bounds!
        
    private:
        T* m_Data;
};

// Addition operator
template <typename T, size_t S>
const Array<T,S> operator+(const Array<T,S>& a, const Array<T,S>& b)
{
    Array<T,S> c;

    for(size_t i=0; i<S; ++i)
        c[i] = a[i] + b[i];

    return c;
}

// Substraction operator
template <typename T, size_t S>
const Array<T,S> operator-(const Array<T,S>& a, const Array<T,S>& b)
{
    Array<T,S> c;

    for(size_t i=0; i<S; ++i)
        c[i] = a[i] - b[i];

    return c;
}

// Substraction operator string specialization
template <size_t S>
const Array<string,S> operator-(const Array<string,S>& a, const Array<string,S>& b) = delete;

// Scalar product operator
template <typename T, size_t S>
const T operator*(const Array<T,S>& a, const Array<T,S>& b)
{
    T c = 0;
    for(size_t i=0; i<S; ++i)
        c += a[i] * b[i];

    return c;
}

// Scalar product exceptions
template <size_t S>
const char operator*(const Array<char,S>& a, const Array<char,S>& b) = delete;

template <size_t S>
const string operator*(const Array<string,S>& a, const Array<string,S>& b) = delete;

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