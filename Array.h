#include <initializer_list>
using namespace std;

template <typename T, size_t S>
class Array
{
    public:
        // Default constructor.
        Array() { };

        // Initializer list constructor.
        Array(const initializer_list<T> array)
        {
            if(S != array.size()){
                __throw_length_error("Array's length differs from expected.");
            }
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
        
    private:
        T m_Data[S];
};