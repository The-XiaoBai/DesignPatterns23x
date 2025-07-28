/*****
 * Template Method
 * Define the skeleton of an algorithm in an operation,
 * deferring some steps to subclasses.
*****/

#include <iostream>
#include <memory>

using namespace std;


class AbstractClass {
    protected:
        void baseMethod1() { cout << "Base Method 1" << endl; }
        void baseMethod2() { cout << "Base Method 2" << endl; }

        virtual void concreteMethod1() = 0;
        virtual void concreteMethod2() = 0;
    
        virtual void optionalMethod() { }

    public:
        virtual ~AbstractClass() = default;

        void method() {
            baseMethod1();
            concreteMethod1();
            baseMethod2();
            concreteMethod2();
            optionalMethod();
        }
};

class ConcreteClass : public AbstractClass {
    protected:
        void concreteMethod1() override { cout << "Concrete Method 1" << endl; }
        void concreteMethod2() override { cout << "Concrete Method 2" << endl; }
        void optionalMethod() override { cout << "Optional Method" << endl; }
};


int main() {
    unique_ptr<AbstractClass> object = make_unique<ConcreteClass>();
    object->method();

    return 0;
}
