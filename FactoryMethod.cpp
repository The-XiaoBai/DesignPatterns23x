/*****
 * Factory Method
 * Define an interface for creating an object, but let subclasses decide which class to instantiate.
 * Factory Method lets a class defer instantiation to subclasses.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Product { public: virtual void method() = 0; };

class ConcreteProduct : public Product { public: void method() override { cout << "Concrete Product" << endl; } };

class Factory { public: virtual unique_ptr<Product> create() = 0; };

class ConcreteFactory : public Factory { public: unique_ptr<Product> create() override { return make_unique<ConcreteProduct>(); } };


int main() {
    auto f = make_unique<ConcreteFactory>();
    auto product = f->create();

    product->method();

    return 0;
}
