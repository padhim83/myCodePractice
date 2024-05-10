#include <iostream>
#include <map>

class TestMoveConstrtor
{
    std::map<int, int> testmap;
    public:
    TestMoveConstrtor() = default;
    TestMoveConstrtor(TestMoveConstrtor&& oth) noexcept{
        if (this != &oth)
        {
            testmap = std::move(oth.testmap);
        }
    }
    TestMoveConstrtor& operator=(TestMoveConstrtor&& oth) noexcept {
        if(this != &oth)
        {
            testmap = std::move(oth.testmap);
        }
        return *this;
    }
    void Addelement(int key, int val)
    {
        testmap[key]=val;
    }
    void Showelement()
    {
        for(const auto &item: testmap)
        {
            std::cout<< item.first << ":" <<item.second<<std::endl;
        }
    }

};
int main()
{
    TestMoveConstrtor obj;
    obj.Addelement(1,10);
    obj.Addelement(2,20);
    TestMoveConstrtor obj1(std::move(obj));
    obj1.Addelement(3,30);
    TestMoveConstrtor obj2;
    obj2 = std::move(obj1);
    obj2.Showelement();
    return 0;
}