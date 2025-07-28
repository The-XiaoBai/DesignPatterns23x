/*****
 * Abstract Factory
 * Create a series of related objects without specifying a specific class
 * to produce a series of objects.
*****/

#include <iostream>
#include <memory>

using namespace std;


class ProductA { public: virtual void method() = 0; };

class ProductA1 : public ProductA { public: void method() override { cout << "Product A1" << endl; } };

class ProductA2 : public ProductA { public: void method() override { cout << "Product A2" << endl; } };

class ProductB { public: virtual void method() = 0; };

class ProductB1 : public ProductB { public: void method() override { cout << "Product B1" << endl; } };

class ProductB2 : public ProductB { public: void method() override { cout << "Product B2" << endl; } };

class AbstractFactory {
    public:
        virtual unique_ptr<ProductA> createA() = 0;
        virtual unique_ptr<ProductB> createB() = 0;
};

class Factory1 : public AbstractFactory {
    public:
        unique_ptr<ProductA> createA() override { return make_unique<ProductA1>(); }
        unique_ptr<ProductB> createB() override { return make_unique<ProductB1>(); }
};

class Factory2 : public AbstractFactory {
    public:
        unique_ptr<ProductA> createA() override { return make_unique<ProductA2>(); }
        unique_ptr<ProductB> createB() override { return make_unique<ProductB2>(); }
};


int main() {
    unique_ptr<AbstractFactory> f1 = make_unique<Factory1>();
    unique_ptr<AbstractFactory> f2 = make_unique<Factory2>();
    
    auto a1 = f1->createA();
    auto b1 = f1->createB();
    auto a2 = f2->createA();
    auto b2 = f2->createB();
    
    a1->method();
    b1->method();
    a2->method();
    b2->method();

    return 0;
}
