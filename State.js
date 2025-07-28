/*****
 * State
 * Allow an object to alter its behavior when its internal state changes.
*****/


class State { method(ctx) {} }

class State1 extends State { method(ctx) { console.log("State 1"); } }

class State2 extends State { method(ctx) { console.log("State 2"); } }

class Context {
    constructor(state) { this.state = state; }

    method() {
        this.state.method(this);
        
        if (this.state instanceof State1) this.state = new State2();
        else this.state = new State1();
    }
}


const c = new Context(new State1());

c.method();
c.method();
