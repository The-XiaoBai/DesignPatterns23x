/*****
 * Strategy
 * Define a family of algorithms, encapsulate each one, and make them interchangeable.
*****/


class Strategy { method() {} }

class Strategy1 extends Strategy { method() { console.log("Strategy 1"); } }

class Strategy2 extends Strategy { method() { console.log("Strategy 2"); } }

class Context {
    constructor() { this.strategy = null; }

    setStrategy(strategy) { this.strategy = strategy; }
    method() { if (this.strategy) this.strategy.method(); }
}


const c = new Context();

c.setStrategy(new Strategy1());
c.method();

c.setStrategy(new Strategy2());
c.method();
