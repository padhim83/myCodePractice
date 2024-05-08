
#include <memory>
#include <iostream>

class Shape {
public:
    virtual std::shared_ptr<Shape> clone() const = 0; // Clone method for creating copies.
    virtual void draw() const = 0;   // Draw method for rendering the shape.
    virtual ~Shape() {}              // Virtual destructor for proper cleanup.
};


class Circle : public Shape {
private:
    double radius;
 
public:
    Circle(double r) : radius(r) {}
 
    std::shared_ptr<Shape> clone() const override {
        return std::make_shared<Circle>(*this);
    }
 
    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
 
public:
    Rectangle(double w, double h) : width(w), height(h) {}
 
    std::shared_ptr<Shape> clone() const override {
        return std::make_shared<Rectangle>(*this);
    }
 
    void draw() const override {
        std::cout << "Drawing a rectangle with width " << width << " and height " << height << std::endl;
    }
};

int main() {
    std::shared_ptr<Shape> shape1 = std::make_shared<Circle>(7.0);
    std::shared_ptr<Shape> shape2 = std::make_shared<Rectangle>(2.0, 4.0);
    // Clone the prototype
    std::shared_ptr<Shape> Cir = shape1->clone();
    Cir->draw();
    std::shared_ptr<Shape> Rect = shape2->clone();
    Rect->draw();
};