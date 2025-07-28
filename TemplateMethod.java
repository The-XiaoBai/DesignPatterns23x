/*****
 * Template Method
 * Define the skeleton of an algorithm in an operation,
 * deferring some steps to subclasses.
*****/


abstract class AbstractClass {
    protected void baseMethod1() { System.out.println("Base Method 1"); }

    protected void baseMethod2() { System.out.println("Base Method 2"); }

    protected abstract void concreteMethod1();
    protected abstract void concreteMethod2();

    protected void optionalMethod() {}

    public final void method() {
        baseMethod1();
        concreteMethod1();
        baseMethod2();
        concreteMethod2();
        optionalMethod();
    }
}

class ConcreteClass extends AbstractClass {
    @Override
    protected void concreteMethod1() { System.out.println("Concrete Method 1"); }

    @Override
    protected void concreteMethod2() { System.out.println("Concrete Method 2"); }

    @Override
    protected void optionalMethod() { System.out.println("Optional Method"); }
}


public class TemplateMethod {
    public static void main(String[] args) {
        AbstractClass object = new ConcreteClass();
        object.method();
    }
}
