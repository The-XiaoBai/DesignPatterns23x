/*****
 * Abstract Factory
 * Create a series of related objects without specifying a specific class
 * to produce a series of objects.
*****/


class ProductA { method() {} }

class ProductA1 extends ProductA { method() { console.log("Product A1"); } }

class ProductA2 extends ProductA { method() { console.log("Product A2"); } }

class ProductB { method() {} }

class ProductB1 extends ProductB { method() { console.log("Product B1"); } }

class ProductB2 extends ProductB { method() { console.log("Product B2"); } }

class AbstractFactory {
    createA() {}
    createB() {}
}

class Factory1 extends AbstractFactory {
    createA() { return new ProductA1(); }
    createB() { return new ProductB1(); }
}

class Factory2 extends AbstractFactory {
    createA() { return new ProductA2(); }
    createB() { return new ProductB2(); }
}


const f1 = new Factory1();
const f2 = new Factory2();

const a1 = f1.createA();
const b1 = f1.createB();
const a2 = f2.createA();
const b2 = f2.createB();

a1.method();
b1.method();
a2.method();
b2.method();
