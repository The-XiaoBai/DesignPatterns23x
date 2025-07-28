/*****
 * Facade
 * Provide a unified interface to a set of interfaces in a subsystem.
 * Facade defines a higher-level interface that makes the subsystem easier to use.
*****/


class System1 { method() { console.log("System 1"); } }

class System2 { method() { console.log("System 2"); } }

class Facade {
    constructor() {
        this.system1 = new System1();
        this.system2 = new System2();
    }

    method() {
        this.system1.method();
        this.system2.method();
    }
}


const f = new Facade();
f.method();
