/*****
 * Adapter
 * Transform interfaces so that otherwise incompatible interfaces work together.
*****/


class Adaptee { public String originalMethod() { return "old"; } }

interface Target { String adaptedMethod(); }

class Adapter_ implements Target {
    private final Adaptee adaptee;

    public Adapter_(Adaptee adaptee) { this.adaptee = adaptee; }

    @Override
    public String adaptedMethod() {
        String oldValue = adaptee.originalMethod();
        return oldValue + "=>" + "new";
    }
}


public class Adapter {
    public static void main(String[] args) {
        Adaptee adaptee = new Adaptee();
        Target target = new Adapter_(adaptee);

        String value = target.adaptedMethod();
        System.out.println(value);
    }
}
