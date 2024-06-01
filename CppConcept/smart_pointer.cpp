/*Demonstrate use of unique pointer to shared pointer*/
/*Demonstrate return smart pointer object*/
#include <iostream>
#include <vector>
#include <memory>

class smart_PointeTest
{
    std::vector<std::string> Data;
    public:
        smart_PointeTest(const std::string& str)
        {
            Data.push_back(str);
        }
        void showAllItem()
        {
            for(const auto& elem: Data)
            {
                std::cout<<"String name ="<< elem << std::endl; 
            }
        }
        void setName(const std::string& str)
        {
            Data.push_back(str);
        }
};
std::unique_ptr<smart_PointeTest> returnUniqueptr()
{
    std::unique_ptr<smart_PointeTest> obj = std::make_unique<smart_PointeTest>(std::string("Madhab"));
    return obj;
}
std::shared_ptr<smart_PointeTest> returnSharedptr()
{
    std::shared_ptr<smart_PointeTest> obj = std::make_shared<smart_PointeTest>(std::string("Sasmita"));
    return obj;
}
int main()
{
    /* Demonstrate the unique pointer */
    std::unique_ptr<smart_PointeTest> obj1Ptr = returnUniqueptr();
    std::cout << "Unique pointer all items" << std::endl;
    obj1Ptr->showAllItem();
    std::unique_ptr<smart_PointeTest> objuniqptr = std::move(obj1Ptr);
    if(obj1Ptr)
    {
        std::cout << "The obj1ptr should have been moved to objuniqptr" << std::endl;
        exit -1;
    }
    std::cout << "Unique pointer after move to objuniqptr" << std::endl;
    objuniqptr->showAllItem();

    /* Demonstrate the shared pointer */
    std::shared_ptr<smart_PointeTest> obj2ptr = returnSharedptr();
    std::cout << "shared  pointer  obj2ptr shared count="<< obj2ptr.use_count() << std::endl;
    std::shared_ptr<smart_PointeTest> obj3ptr = obj2ptr;
    obj2ptr->setName(std::string("Padhi"));
    obj2ptr->showAllItem();
   
    std::cout << "shared  pointer  obj3ptr use count=" << obj2ptr.use_count() << std::endl;
    obj3ptr->showAllItem();
    obj3ptr.reset();
    if(obj3ptr)
    {
        std::cout << "The obj3ptr should have been reset" << std::endl;
        exit -1;
    }
        std::cout << "shared  pointer  obj2ptr use count=" << obj2ptr.use_count() << std::endl;
    return 0;

}