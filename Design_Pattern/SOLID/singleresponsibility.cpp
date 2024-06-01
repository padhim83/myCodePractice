#include <iostream>
#include <string>
#include <fstream>

/* Demonstrating Single Responsibility with segregating class
- User class manage user data
- UserValidator validate user data
- UserFileManager Saves user data to fileif valid
*/

class User
{
    private:
        std::string userName;
        std::string userEmail;
    public:
        User(const std::string& user, const std::string& email) : userName(user), userEmail(email) {}
        std::string getName() const {return userName;}
        std::string getEmail() const {return userEmail;}
};

class UserValidator
{
    public:
        bool isValid(const User& userObj)
        {
            return  !userObj.getName().empty() &&
                    !userObj.getEmail().empty() &&
                    userObj.getEmail().find('@') != std::string::npos;
        }

};
class UserSaveToFile
{
    public:
        void saveUserToFile(const User& userObj, const std::string& filename)
        {
            // Use std::filesystem to get the absolute path
            std::fstream outFile(filename, std::fstream::out | std::fstream::app);
            if (outFile.is_open())
            {
                outFile << "User Name:" << userObj.getName() << std::endl;
                outFile << "user Email:" << userObj.getEmail() << std::endl;
                outFile.close();
            }
            else
            {
                std::cerr << "Unable to Open File " << std::endl;
            }
        }
};
int main()
{
    User obj1(std::string("Madhab Padhi"), std::string("madhab.padhi@gmail.com"));
    User obj2(std::string("Sasmita Sabat"), std::string("Sasmita.Sabat@gmail.com"));
    UserValidator validator;
    UserSaveToFile fileHandler;
    if(validator.isValid(obj1))
    {
        fileHandler.saveUserToFile(obj1, "OutFile.txt");
    }
    if(validator.isValid(obj2))
    {
        fileHandler.saveUserToFile(obj2, "OutFile.txt");
    }
    return 0;
}