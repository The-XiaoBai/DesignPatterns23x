/*****
 * Visitor
 * Represent an operation to be performed on the elements of an object structure.
*****/

import java.util.List;
import java.util.ArrayList;


interface Visitor_ { void visit(Element element); }

interface Element { void accept(Visitor_ v); }

class Element1 implements Element {
    @Override
    public void accept(Visitor_ v) { v.visit(this); }
}

class Element2 implements Element {
    @Override
    public void accept(Visitor_ v) { v.visit(this); }
}

class ConcreteVisitor implements Visitor_ {
    @Override
    public void visit(Element element) {
        if (element instanceof Element1) System.out.println("Element 1");
        else if (element instanceof Element2) System.out.println("Element 2");
    }
}


public class Visitor {
    public static void main(String[] args) {
        List<Element> elements = new ArrayList<>();
        elements.add(new Element1());
        elements.add(new Element2());

        ConcreteVisitor visitor = new ConcreteVisitor();
        for (Element e : elements) e.accept(visitor);
    }
}
