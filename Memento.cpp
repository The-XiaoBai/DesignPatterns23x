/*****
 * Memento
 * Capture and externalize an object's internal state
 * so that the object can be restored to this state later.
*****/

#include <iostream>
#include <string>
#include <memory>

using namespace std;


class Memento {
    string state;
    
    public:
        explicit Memento(string s) : state(move(s)) {}
        string getState() const { return state; }
};

class Originator {
    string state;

    public:
        void setState(const string& s) { state = s; }
        unique_ptr<Memento> save() { return make_unique<Memento>(state); }
        string getState() const { return state; }
        void restore(const Memento& m) { state = m.getState(); }
};

class Caretaker {
    unique_ptr<Memento> memento;

    public:
        void saveState(Originator& o) { memento = o.save(); }
        void restoreState(Originator& o) { if (memento) o.restore(*memento); }
};


int main() {
    Originator o;
    Caretaker c;
    
    o.setState("State 1");
    c.saveState(o);
    o.setState("State 2");
    cout << o.getState() << endl;
    c.restoreState(o);
    cout << o.getState() << endl;
    
    return 0;
}
