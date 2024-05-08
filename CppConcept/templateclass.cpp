#include <iostream>

template <typename T>
class Math
{
    public:
        T add(T val1, T val2);
        T sub(T val1, T val2);
        T mul(T val1, T val2);
        T div(T val1, T val2);
};

template <typename T>
T Math<T>::add(T val1, T val2)
{
    return val1 + val2;
}

template <typename T>
T Math<T>::sub(T val1, T val2)
{
    return val1 - val2;
}

template <typename T>
T Math<T>::mul(T val1, T val2)
{
    return val1 * val2;
}

template <typename T>
T Math<T>::div(T val1, T val2)
{
    return val1 / val2;
}

// Template specialization 
template<>
double Math<double>::div(double val1, double val2)
{
    return val1 * val2;
}

int main()
{
    Math<int> obj1;
    Math<double> obj2;
    std::cout<<obj1.add(10,5)<<std::endl;
    std::cout<<obj1.sub(10,5)<<std::endl;
    std::cout<<obj1.mul(10,5)<<std::endl;
    std::cout<<obj1.div(10,5)<<std::endl;
    std::cout<<obj2.div(10,5)<<std::endl;
    return 0;
}