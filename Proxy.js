/*****
 * Proxy
 * Provides a proxy that allows other objects to control access to this object.
*****/


class Subject { method() {} }

class ConcreteSubject extends Subject { method() { console.log("..."); } }

class Proxy extends Subject {
    constructor() {
        super();
        this.concreteSubject = new ConcreteSubject();
    }

    validateAccess() { return true; }

    method() {
        if (this.validateAccess()) {
            console.log("Proxy: Start");
            this.concreteSubject.method();
            console.log("Proxy: End");
        }
    }
}


const client = new Proxy();
client.method();
