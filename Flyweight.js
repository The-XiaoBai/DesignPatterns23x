/*****
 * Flyweight
 * Enables a large number of fine-grained objects to be shared.
*****/


class Flyweight { method(name) {} }

class ConcreteFlyweight extends Flyweight {
    constructor(state) {
        super();
        this.key = state;
    }

    method(name) { console.log(`${this.key}-${name}`); }
}

class Factory {
    constructor() { this.flyweights = {}; }

    getFlyweight(key) {
        if (!this.flyweights[key]) this.flyweights[key] = new ConcreteFlyweight(key);
        return this.flyweights[key];
    }
}


const f = new Factory();

const f1 = f.getFlyweight("A");
const f2 = f.getFlyweight("A");
f1.method("1");
f2.method("2");

const f3 = f.getFlyweight("B");
f3.method("3");
