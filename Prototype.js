/*****
 * Prototype
 * Create a new object by copying a prototype of an existing object.
*****/


class Prototype {
    clone() {}    
    show() {}
}

class ConcretePrototypeA extends Prototype {
    constructor(value) {
        super();
        this.value = value;
    }
    
    clone() { return new ConcretePrototypeA(this.value); }
    show() { console.log(this.value); }
}


const p = new ConcretePrototypeA(1);
const p_clone = p.clone();

p_clone.show();
