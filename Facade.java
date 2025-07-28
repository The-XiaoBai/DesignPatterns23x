/*****
 * Facade
 * Provide a unified interface to a set of interfaces in a subsystem.
 * Facade defines a higher-level interface that makes the subsystem easier to use.
*****/


class System1 { public void method() { System.out.println("System 1"); } }

class System2 { public void method() { System.out.println("System 2"); } }

class Facade_ {
    private System1 system1;
    private System2 system2;

    public Facade_() {
        system1 = new System1();
        system2 = new System2();
    }

    public void method() {
        system1.method();
        system2.method();
    }
}


public class Facade {
    public static void main(String[] args) {
        Facade_ f = new Facade_();
        f.method();
    }
}
