#include <iostream>

template <class T, int size>
class Array
{
    T array[size]{};
public:
    T& operator[](int index)
    {
        return array[index];
    }
};

template <class T>
class Storage
{
    T value;
public:
    Storage(T value) : value{ value } {}

    void Print()
    {
        std::cout << value << "\n";
    }
};

template<>
void Storage<double>::Print()
{
    std::cout << std::scientific << value << "\n";
}

template <class T>
class StorageArray
{
    T array[8]{};
public:
    void SetItem(int index, const T& value)
    {
        array[index] = value;
    }

    const T& GetItem(int index)
    {
        return array[index];
    }
};

template<>
class StorageArray<bool>
{
    unsigned char byte{};
public:
    void SetItem(int index, bool value)
    {
        int mask{ 1 << index };
        if (value)
            byte |= mask;
        else
            byte &= ~mask;
    }

    bool GetItem(int index)
    {
        int mask{ 1 << index };
        return byte & mask;
    }
};

int main()
{
    
    /*Array<int, 3> array;
    array[0] = 100;*/

    /*Storage<int> istore(10);
    Storage<double> dstore(20.23);

    istore.Print();
    dstore.Print();*/

    StorageArray<int> isArray;
    for (int i = 0; i < 8; i++)
        isArray.SetItem(i, i + 1);
    for (int i = 0; i < 8; i++)
        std::cout << isArray.GetItem(i) << " ";
    std::cout << "\n";

    std::cout << std::boolalpha;

    StorageArray<bool> bsArray;
    for (int i = 0; i < 8; i++)
        bsArray.SetItem(i, i % 3);
    for (int i = 0; i < 8; i++)
        std::cout << bsArray.GetItem(i) << " ";
    std::cout << "\n";

}
