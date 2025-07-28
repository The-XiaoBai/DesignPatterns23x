/*****
 * Observer
 * Define a one-to-many dependency so that when one object changes state,
 * all its dependents are notified and updated automatically.
*****/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Observer { public: virtual void update(int state) = 0; };

class ConcreteObserver : public Observer { public: void update(int state) override { cout << state << endl; } };

class Subject {
    vector<Observer*> observers;
    int state = 0;

    public:
        void attach(Observer* o) { observers.push_back(o); }
        void setState(int new_state) {
            state = new_state;
            for (auto observer : observers) observer->update(state);
        }
};


int main() {
    Subject s;
    ConcreteObserver o;

    s.attach(&o);
    s.setState(10);
    s.setState(20);

    return 0;
}
