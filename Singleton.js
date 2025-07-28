/*****
 * Singleton
 * Ensure a class has only one instance, and provide a global point of access to it.
*****/


const Singleton = (() => {
    let instance;
    
    class Singleton {
        constructor() {}

        static getInstance() {
            if (!instance) instance = new Singleton();
            return instance;
        }

        method() { console.log("Singleton"); }
    }

    return Singleton;
})();


const s = Singleton.getInstance();
s.method();
