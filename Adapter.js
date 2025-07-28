/*****
 * Adapter
 * Transform interfaces so that otherwise incompatible interfaces work together.
*****/


class Adaptee { originalMethod() { return "old"; } }

class Target { adaptedMethod() {} }

class Adapter extends Target {
    constructor(adaptee) {
        super();
        this.adaptee = adaptee;
    }

    adaptedMethod() {
        const oldValue = this.adaptee.originalMethod();
        return `${oldValue}=>new`;
    }
}


const adaptee = new Adaptee();
const target = new Adapter(adaptee);

const value = target.adaptedMethod();
console.log(value);
