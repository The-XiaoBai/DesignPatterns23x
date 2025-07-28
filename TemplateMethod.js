/*****
 * Template Method
 * Define the skeleton of an algorithm in an operation,
 * deferring some steps to subclasses.
*****/


class AbstractClass {
    baseMethod1() { console.log("Base Method 1"); }

    baseMethod2() { console.log("Base Method 2"); }

    concreteMethod1() {}

    concreteMethod2() {}

    optionalMethod() {}

    method() {
        this.baseMethod1();
        this.concreteMethod1();
        this.baseMethod2();
        this.concreteMethod2();
        this.optionalMethod();
    }
}

class ConcreteClass extends AbstractClass {
    concreteMethod1() { console.log("Concrete Method 1"); }

    concreteMethod2() { console.log("Concrete Method 2"); }

    optionalMethod() { console.log("Optional Method"); }
}


const object = new ConcreteClass();
object.method();
