#include <iostream>
#include <string>
#include <vector>

class Employee
{
    std::string Name;
    int age;

    public:
        Employee(const Employee& oth)
        {
            if(this != &oth)
            {
                this->Name = oth.Name;
                this->age = oth.age; 
            }
            else{
                std::cerr<< "Self reference Object" << std::endl; 
            }

        }
        Employee(std::string &empname, int old): Name(empname),age(old)
        {

        }
        void showempdetail() const
        {
            std::cout << "Name= " << Name << " age=" <<age << std::endl; 
        }
};

int main()
{
    std::string emp1="Madhab";
    std::string emp2="Sasmita";
    Employee obj(emp1, 40);
    Employee obj1(obj);
    Employee obj2(obj2); // print error when self reference obj for copy constructor
    std::vector<Employee> Employees;
    Employees.push_back(obj);
    Employees.push_back(obj1);
    Employees.push_back(Employee(emp2, 37));


    for(const auto& emp : Employees)
    {
        emp.showempdetail();
    }
    return 0;
}