/*****
 * Bridge
 * Remove the abstract part of the classification
 * from the concrete implementation part
 * so that it can be changed flexibly.
*****/


interface Implementor { void method(); }

class ConcreteImplementor implements Implementor {
    @Override
    public void method() { System.out.println("Concrete Implementor"); }
}

class Controller {
    private final Implementor implementor;

    public Controller(Implementor implementor) { this.implementor = implementor; }

    public void method() { implementor.method(); }
}


public class Bridge {
    public static void main(String[] args) {
        Implementor i = new ConcreteImplementor();
        Controller c = new Controller(i);

        c.method();
    }
}
