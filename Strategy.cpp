/*****
 * Strategy
 * Define a family of algorithms, encapsulate each one, and make them interchangeable.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Strategy { public: virtual void method() = 0; };

class Strategy1 : public Strategy { public: void method() override { cout << "Strategy 1" << endl; } };

class Strategy2 : public Strategy { public: void method() override { cout << "Strategy 2" << endl; } };

class Context {
    unique_ptr<Strategy> strategy;
    
    public:
        void setStrategy(unique_ptr<Strategy> s) { strategy = move(s); }
        void method() { if (strategy) strategy->method(); }
};


int main() {
    Context c;

    c.setStrategy(make_unique<Strategy1>());
    c.method();
    
    c.setStrategy(make_unique<Strategy2>());
    c.method();
    
    return 0;
}
