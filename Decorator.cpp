/*****
 * Decorator
 * Attach additional responsibilities to an object dynamically.
 * Decorators provide a flexible alternative to subclassing for extending functionality.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Component { public: virtual void method() = 0; };

class Base : public Component { public: void method() override { cout << "Base" << endl; } };

class Decorator : public Component {
    protected:
        unique_ptr<Component> component;

    public:
        explicit Decorator(unique_ptr<Component> comp) : component(move(comp)) {}

        void method() override { component->method(); }
};

class ConcreteDecorator1 : public Decorator {
    public:
        using Decorator::Decorator;

        void method() override {
            Decorator::method();
            cout << "Concrete Decorator 1" << endl;
        }
};

class ConcreteDecorator2 : public Decorator {
    public:
        using Decorator::Decorator;

        void method() override {
            Decorator::method();
            cout << "Concrete Decorator 2" << endl;
        }
};


int main() {
    auto b = make_unique<Base>();
    auto d1 = make_unique<ConcreteDecorator1>(move(b));
    auto d2 = make_unique<ConcreteDecorator2>(move(d1));

    d2->method();

    return 0;
}
