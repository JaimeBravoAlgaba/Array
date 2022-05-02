using namespace std;

template <typename T, size_t S>
class Array
{
    public:
         //Returns the number of elements in the array.
        constexpr size_t Size() const { return S; }

        T& operator[](size_t index) { return container[index]; }
        const T& operator[](size_t index) const { return container[index]; }

        T* Data(){ return container; }
        const T* Data() const { return container; }
        
    private:
        T container[S];
};