/*****
 * Facade
 * Provide a unified interface to a set of interfaces in a subsystem.
 * Facade defines a higher-level interface that makes the subsystem easier to use.
*****/

#include <iostream>
#include <memory>

using namespace std;


class System1 { public: void method() { cout << "System 1" << endl; } };

class System2 { public: void method() { cout << "System 2" << endl; } };

class Facade {
    private:
        unique_ptr<System1> system1;
        unique_ptr<System2> system2;

    public:
        Facade() : system1(make_unique<System1>()), 
            system2(make_unique<System2>()) {}
    
        void method() {
            system1->method();
            system2->method();
        }
};


int main() {
    auto f = make_unique<Facade>();
    f->method();

    return 0;
}
