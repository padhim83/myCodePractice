#include <memory>
#include <iostream>

// Abstract product classes
class AbstractProduct {
public:
    virtual void operation() const = 0;
    virtual ~AbstractProduct() = default; // Virtual destructor for polymorphic behavior
};


// Concrete product classes
class ConcreteProductA1 : public AbstractProduct {
public:
    void operation() const override {
        std::cout << "ConcreteProductA1 operation\n";
    }
};
class ConcreteProductA2 : public AbstractProduct {
public:
    void operation() const override {
        std::cout << "ConcreteProductA2 operation\n";
    }
};

class ConcreteProductB1 : public AbstractProduct {
public:
    void operation() const override {
        std::cout << "ConcreteProductB1 operation"<<std::endl;
    }
};
class ConcreteProductB2 : public AbstractProduct {
public:
    void operation() const override {
        std::cout << "ConcreteProductB2 operation"<<std::endl;
    }
};

// Abstract factory interface
class AbstractFactoryA {
public:
    virtual std::unique_ptr<AbstractProduct> createProductA1() const = 0;
    virtual std::unique_ptr<AbstractProduct> createProductA2() const = 0;
    virtual ~AbstractFactoryA() = default;
};

class AbstractFactoryB {
public:
    virtual std::unique_ptr<AbstractProduct> createProductB1() const = 0;
    virtual std::unique_ptr<AbstractProduct> createProductB2() const = 0;
    virtual ~AbstractFactoryB() = default;
};

// Concrete factory implementing AbstractFactory
class ConcreteFactoryA : public AbstractFactoryA {
public:
    std::unique_ptr<AbstractProduct> createProductA1() const override {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProduct> createProductA2() const override {
        return std::make_unique<ConcreteProductA2>();
    }
};

class ConcreteFactoryB : public AbstractFactoryB {
public:
    std::unique_ptr<AbstractProduct> createProductB1() const override {
        return std::make_unique<ConcreteProductB1>();
    }

    std::unique_ptr<AbstractProduct> createProductB2() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};

int main() {
    // Create a concrete factory
    ConcreteFactoryA factoryA;
    ConcreteFactoryB factoryB;

    // Use the factory to create products
    std::unique_ptr<AbstractProduct> productA1 = factoryA.createProductA1();
    std::unique_ptr<AbstractProduct> productA2 = factoryA.createProductA2();
    productA1->operation();
    productA2->operation();
    std::unique_ptr<AbstractProduct> productB1 = factoryB.createProductB1();
    std::unique_ptr<AbstractProduct> productB2 = factoryB.createProductB2();
    productB1->operation();
    productB2->operation();

    return 0;
}
