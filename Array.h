#ifndef __ARRAY_
#define __ARRAY_

#include <initializer_list>
using namespace std;

template <typename T>
class ArrayIterator
{
    // Tags:
    using iterator_category = bidirectional_iterator_tag;
    using difference_type = size_t;
    using value_type = T;
    using pointer = T*;
    using reference = T&;

    public:
        // Constructor.
        ArrayIterator(pointer ptr) : m_Pointer(ptr) { }

        // Reference operator.
        reference operator*()  const { return *m_Pointer; }
        // Pointer operator.
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
        Array() { };

        // Copy constructor.
        Array(const Array<T, S>& other)
        {
            for(size_t i=0; i<S; ++i)
                m_Data[i] = other[i];
        };
        
        Array(const T* v)
        {       
            for(size_t i=0; i<S; ++i)
                m_Data[i] = v[i];
        };

        // Initializer list constructor.
        Array(const initializer_list<T> array)
        {
            if(S != array.size())
                __throw_length_error("Array's length differs from expected.");
            else
                for(size_t i=0; i<array.size(); ++i)
                    m_Data[i] = array.begin()[i];
        }

         //Returns the number of elements in the array.
        constexpr size_t Size() const { return S; }

        // Reference by index
        T& operator[](const size_t index) { return m_Data[index]; }
        // Const reference by index
        const T& operator[](const size_t index) const { return m_Data[index]; }

        // Data pointer
        T* Data(){ return m_Data; }
        // Const data pointer
        const T* Data() const { return m_Data; }

        // Iterator begin
        ArrayIterator<T> begin() { return ArrayIterator<T>(&m_Data[0]);}
        // Iterator end
        ArrayIterator<T> end() { return ArrayIterator<T>(&m_Data[S]);} // S position is out of bounds!

    private:
        T m_Data[S];
};

#endif