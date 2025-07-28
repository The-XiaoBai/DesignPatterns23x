/*****
 * Decorator
 * Attach additional responsibilities to an object dynamically.
 * Decorators provide a flexible alternative to subclassing for extending functionality.
*****/


class Component { method() {} }

class Base extends Component {method() { console.log("Base"); } }

class Decorator extends Component {
    constructor(component) {
        super();
        this.component = component;
    }

    method() { this.component.method(); }
}

class ConcreteDecorator1 extends Decorator {
    method() {
        super.method();
        console.log("Concrete Decorator 1");
    }
}

class ConcreteDecorator2 extends Decorator {
    method() {
        super.method();
        console.log("Concrete Decorator 2");
    }
}


const b = new Base();
const d1 = new ConcreteDecorator1(b);
const d2 = new ConcreteDecorator2(d1);

d2.method();
