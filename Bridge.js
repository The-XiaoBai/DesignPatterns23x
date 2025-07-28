/*****
 * Bridge
 * Remove the abstract part of the classification
 * from the concrete implementation part
 * so that it can be changed flexibly.
*****/


class Implementor { method() {} }

class ConcreteImplementor extends Implementor { method() { console.log("Concrete Implementor"); } }

class Controller {
    constructor(implementor) { this.implementor = implementor; }

    method() { this.implementor.method(); }
}


const i = new ConcreteImplementor();
const c = new Controller(i);

c.method();
