#include <iostream>


#define CHECK_RESULT(result) \
    if(result!=0) \
    { \
        std::cout<<" Password is not same exit application "<<std::endl; \
        exit -1; \
    }

int main()
{
    std::string var1 = "Hello";
    std::string var2 = "Hillo";
    int status =  (var1== var2 ? 0 : -1) ;
    CHECK_RESULT(status);
    return 0;

}