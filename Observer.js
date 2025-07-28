/*****
 * Observer
 * Define a one-to-many dependency so that when one object changes state,
 * all its dependents are notified and updated automatically.
*****/


class Observer { update(state) {} }

class ConcreteObserver extends Observer { update(state) { console.log(state); } }

class Subject {
    constructor() {
        this.observers = [];
        this.state = 0;
    }

    attach(o) { this.observers.push(o); }
    setState(new_state) {
        this.state = new_state;
        for (const observer of this.observers) observer.update(this.state);
    }
}


const s = new Subject();
const o = new ConcreteObserver();

s.attach(o);
s.setState(10);
s.setState(20);
