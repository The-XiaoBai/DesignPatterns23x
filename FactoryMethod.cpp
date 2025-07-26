/*****
 * Factory Method
 * Define the interface for creating objects,
 * and let the subclass decide the concrete class
 * to instantiate to achieve dynamic production of objects.
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
