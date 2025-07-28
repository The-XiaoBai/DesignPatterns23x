/*****
 * Chain of Responsibility
 * Avoid coupling the sender of a request to its receiver
 * by giving more than one object a chance to handle the request.
*****/


class Handler {
    constructor() { this.next = null; }

    setNext(nextHandler) { this.next = nextHandler; }
    handle(level) { if (this.next) this.next.handle(level); }
}

class ConcreteHandler1 extends Handler {
    handle(level) {
        if (level < 10) console.log(`Handler 1: ${level}`);
        else if (this.next) this.next.handle(level);
    }
}

class ConcreteHandler2 extends Handler {
    handle(level) {
        if (level >= 10) console.log(`Handler 2: ${level}`);
        else if (this.next) this.next.handle(level);
    }
}


const h1 = new ConcreteHandler1();
const h2 = new ConcreteHandler2();

h1.setNext(h2);
h1.handle(5);
h1.handle(15);
