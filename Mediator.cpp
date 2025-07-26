/*****
 * Mediator
 * Use a mediator object to encapsulate a series of object interactions.
*****/

#include <iostream>

using namespace std;


class Mediator { public: virtual void broadcast(const string& msg) = 0; };

class ConcreteMediator : public Mediator { public: void broadcast(const string& msg) override { cout << msg << endl; } };

class Colleague {
    protected:
        Mediator* mediator;
    
    public:
        explicit Colleague(Mediator* m) : mediator(m) {}
        virtual void send(const string& msg) = 0;
};

class ConcreteColleague : public Colleague {
    public:
        using Colleague::Colleague;
        void send(const string& msg) override { mediator->broadcast(msg); };
};


int main() {
    ConcreteMediator m;
    ConcreteColleague c(&m);

    c.send("Hello!");

    return 0;
}
