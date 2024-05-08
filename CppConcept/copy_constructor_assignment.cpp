#include <iostream>
#include <memory>


class TestCopyAssignment
{
    std::unique_ptr<int> dataptr;
    
    public:
        TestCopyAssignment(int val) {
            dataptr = std::make_unique<int>(val) ;
        }
        TestCopyAssignment& operator=(const TestCopyAssignment& other);
        TestCopyAssignment(const TestCopyAssignment& other)
        {
            if(this != &other)
            {
                dataptr = std::make_unique<int>(*other.dataptr);
            }
        }
        void show()
        {
            std::cout<<" dataptr value"<<*dataptr<<std::endl;
        }
};

TestCopyAssignment& TestCopyAssignment::operator=(const TestCopyAssignment& other)
{
    if(this != &other)
    {
        *dataptr = *(other.dataptr);
    }
    return *this;
}

int main()
{
    TestCopyAssignment obj1(20);
    TestCopyAssignment obj2(30);
    TestCopyAssignment obj3 = obj2; // copy constructor
    
    obj1.show();
    obj2 = obj1; // copy assignment operator 
    obj2.show();
    obj3.show();

    return 0;

}