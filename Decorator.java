/*****
 * Decorator
 * Attach additional responsibilities to an object dynamically.
 * Decorators provide a flexible alternative to subclassing for extending functionality.
*****/


interface Component { void method(); }

class Base implements Component {
    @Override
    public void method() { System.out.println("Base"); }
}

abstract class Decorator_ implements Component {
    protected Component component;

    public Decorator_(Component component) { this.component = component; }

    @Override
    public void method() { component.method(); }
}

class ConcreteDecorator1 extends Decorator_ {
    public ConcreteDecorator1(Component component) { super(component); }

    @Override
    public void method() {
        super.method();
        System.out.println("Concrete Decorator 1");
    }
}

class ConcreteDecorator2 extends Decorator_ {
    public ConcreteDecorator2(Component component) { super(component); }

    @Override
    public void method() {
        super.method();
        System.out.println("Concrete Decorator 2");
    }
}


public class Decorator {
    public static void main(String[] args) {
        Component b = new Base();
        Component d1 = new ConcreteDecorator1(b);
        Component d2 = new ConcreteDecorator2(d1);

        d2.method();
    }
}
