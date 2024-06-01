#include <iostream>
#include <functional>

void TestFunction(int val)
{
    std::cout << "regular Function called with val = " << val <<std::endl;
}

class base
{
    public:
        virtual void testmemFunction() = 0;
};

class derived final
{
    std::string  data;
    public:
        derived(std::string& val) : data(val) {}
        void testmemFunction(void) const
        {
            std::cout<<" stringvalue "<< this->data << std::endl;
        }
};

struct Functor
{
    void operator()(std::string& strVal) const
    {
        std::cout << " Functor called with string val = " << strVal << std::endl;
    }
};

int main()
{
    int fact = 5;
    // std::function calling Regular Function
    std::function<void(int)> callFunc = TestFunction;
    callFunc(10);

    // std::function with Functor function
    Functor functor;
    std::function<void(std::string&)> functorFunc;
    functorFunc = functor;
    std::string str = "Hello Functor";
    functorFunc(str);

    //std::function with Lambda function
    std::function<int(int)> lambdaFunc;
    lambdaFunc = [fact] (int x) -> int {
        return fact * x;
    };
    int retVal = lambdaFunc(10);
    std::cout << retVal << std::endl; 
    
    //demo std::function with Member Function 
    std::string strVal = "Initialize class";
    derived obj(strVal);
    std::function<void(derived&)> memFunc = &derived::testmemFunction;
    memFunc(obj);
 }