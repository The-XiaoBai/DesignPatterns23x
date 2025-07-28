/*****
 * Composite
 * Compose objects into tree structures to represent part-whole hierarchies.
 * Lets clients treat individual objects and compositions of objects uniformly.
*****/


class Component {
    method() {}

    add(component) { throw new Error("Not allowed"); }
}

class Composite extends Component {
    constructor() {
        super();
        this.children = [];
    }

    method() {
        console.log("Composite");
        for (const child of this.children) child.method();
    }

    add(component) { this.children.push(component); }
}

class Child extends Component { method() { console.log("Child"); } }


const child = new Child();

const composite = new Composite();
composite.add(child);

const root = new Composite();
root.add(composite);

root.method();
