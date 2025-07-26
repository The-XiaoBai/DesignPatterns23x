/*****
 * Bridge
 * Remove the abstract part of the classification
 * from the concrete implementation part
 * so that it can be changed flexibly.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Implementor { public: virtual void method() = 0; };

class ConcreteImplementor : public Implementor {
    public:
        void method() override { cout << "Concrete Implementor" << endl; }
};

class Controller {
    protected:
        unique_ptr<Implementor> implementor;

    public:
        explicit Controller(unique_ptr<Implementor> i) : implementor(move(i)) {}
        virtual ~Controller() = default;

        void method() { implementor->method(); }
};


int main() {
    auto i = make_unique<ConcreteImplementor>();
    Controller c(move(i));

    c.method();

    return 0;
}
