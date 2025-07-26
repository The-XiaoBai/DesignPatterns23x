/*****
 * Prototype
 * Create a new object by copying a prototype of an existing object.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Prototype {
    public:
        virtual ~Prototype() = default;
        virtual unique_ptr<Prototype> clone() const = 0;
        virtual void show() const = 0;
};

class ConcretePrototypeA : public Prototype {
    int value;

    public:
        ConcretePrototypeA(int v) : value(v) {}
        unique_ptr<Prototype> clone() const override { return make_unique<ConcretePrototypeA>(value); }
        void show() const override { cout << value << endl; }
};


int main() {
    unique_ptr<Prototype> p = make_unique<ConcretePrototypeA>(1);
    auto p_clone = p->clone();
    
    p_clone->show();

    return 0;
}
