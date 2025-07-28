/*****
 * Proxy
 * Provides a proxy that allows other objects to control access to this object.
*****/

interface Subject { void method(); }

class ConcreteSubject implements Subject {
    @Override
    public void method() { System.out.println("..."); }
}

class Proxy_ implements Subject {
    private ConcreteSubject concreteSubject;

    public Proxy_() { this.concreteSubject = new ConcreteSubject(); }

    private boolean validateAccess() { return true; }

    @Override
    public void method() {
        if (validateAccess()) {
            System.out.println("Proxy: Start");
            concreteSubject.method();
            System.out.println("Proxy: End");
        }
    }
}


public class Proxy {
    public static void main(String[] args) {
        Subject client = new Proxy_();
        client.method();
    }
}
