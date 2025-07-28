/*****
 * Visitor
 * Represent an operation to be performed on the elements of an object structure.
*****/


class Visitor { visit(element) {} }

class Element { accept(visitor) {} }

class Element1 extends Element { accept(visitor) { visitor.visit(this); } }

class Element2 extends Element { accept(visitor) { visitor.visit(this); } }

class ConcreteVisitor extends Visitor {
    visit(element) {
        if (element instanceof Element1) console.log("Element 1");
        else if (element instanceof Element2) console.log("Element 2");
    }
}


const elements = [new Element1(), new Element2()];
const visitor = new ConcreteVisitor();
elements.forEach(e => e.accept(visitor));
