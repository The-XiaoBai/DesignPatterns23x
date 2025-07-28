/*****
 * State
 * Allow an object to alter its behavior when its internal state changes.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Context;

class State { public: virtual void method(Context* ctx) = 0; };

class State1 : public State { public: void method(Context* ctx) override { cout << "State 1" << endl; }; };

class State2 : public State { public: void method(Context* ctx) override { cout << "State 2" << endl; }; };

class Context {
    unique_ptr<State> state;

    public:
        Context(State* s) : state(s) {}
        void method() {
            state->method(this);
            
            if (dynamic_cast<State1*>(state.get())) state = make_unique<State2>();
            else state = make_unique<State1>();
        }
};


int main() {
    Context c(new State1);

    c.method();
    c.method();
    
    return 0;
}
