#include <memory>
#include <iostream>

// Base product interface class
class IProduct {
public:
    virtual void operation() const = 0;
    virtual ~IProduct() = default; // Virtual destructor for polymorphic behavior
};

// Concrete product classe A
class ConcreteProductA : public IProduct {
public:
    void operation() const override {
        std::cout << "Concrete Product A operation"<<std::endl;
    }
};

// Concrete product classe B
class ConcreteProductB : public IProduct {
public:
    void operation() const override {
        std::cout << "Concrete Product B operation"<<std::endl;
    }
};

// Factory interface
class IFactory {
public:
    virtual std::unique_ptr<IProduct> createProduct() const = 0;
    virtual ~IFactory() = default;
};

// Concrete factory A
class ConcreteFactoryA : public IFactory {
public:
    std::unique_ptr<IProduct> createProduct() const override {
        return std::make_unique<ConcreteProductA>();
    }
};

// Concrete factory B
class ConcreteFactoryB : public IFactory {
public:
    std::unique_ptr<IProduct> createProduct() const override {
        return std::make_unique<ConcreteProductB>();
    }
};

int main() {
    // Create a concrete factory A
    ConcreteFactoryA factoryA;
    std::cout<< " Created concrete FactoryA"<<std::endl;
    ConcreteFactoryB factoryB;
    std::cout<< " Created concrete FactoryB"<<std::endl;

    // Use the factory to create a product
    std::unique_ptr<IProduct> productA = factoryA.createProduct();
    productA->operation();
    std::unique_ptr<IProduct> productB = factoryB.createProduct();
    productB->operation();

    return 0;
}
