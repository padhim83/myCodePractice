#include <iostream>
#include <memory>

class Singleton {
public:
    // Deleted copy constructor 
    Singleton(const Singleton&) = delete;
    // Delete copy assignment operator
    Singleton& operator=(const Singleton&) = delete;
    // Default move constructor 
    Singleton(Singleton&&) = default;
    // Default move assignment operator
    Singleton& operator=(Singleton&&) = default;

    // Accessor for the singleton instance
    static std::shared_ptr<Singleton> getInstance();
    // Example member function
    void showMessage() {
        std::cout << "Hello from Singleton"<<std::endl;
    }

private:
    // Private constructor to prevent direct instantiation
    Singleton() {}

    // Static shared_ptr to hold the instance
    static std::shared_ptr<Singleton> instance;
};

// Static initialization of the instancevto nullptr
std::shared_ptr<Singleton> Singleton::instance = nullptr;

// Define the function to return the instance of class
std::shared_ptr<Singleton> Singleton::getInstance() {
    // Create the instance if it doesn't exist
    if (!instance) {
        instance = std::shared_ptr<Singleton>(new Singleton);
    }
    return instance;
}


int main() {
    // Access the singleton instance
    std::shared_ptr<Singleton> singleton1 = Singleton::getInstance();
    std::shared_ptr<Singleton> singleton2 = Singleton::getInstance();

    if (singleton1.get() == singleton2.get())
    {
        // Use the singleton instance
        singleton1->showMessage();
    }

    return 0;
}
