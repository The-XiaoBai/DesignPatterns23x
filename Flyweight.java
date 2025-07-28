/*****
 * Flyweight
 * Enables a large number of fine-grained objects to be shared.
*****/

import java.util.HashMap;
import java.util.Map;


interface Flyweight_ { void method(String name); }

class ConcreteFlyweight implements Flyweight_ {
    private String key;

    public ConcreteFlyweight(String state) { this.key = state; }

    @Override
    public void method(String name) { System.out.println(key + "-" + name); }
}

class Factory {
    private Map<String, Flyweight_> flyweights = new HashMap<>();

    public Flyweight_ getFlyweight(String key) {
        if (!flyweights.containsKey(key)) {
            flyweights.put(key, new ConcreteFlyweight(key));
        }
        return flyweights.get(key);
    }
}


public class Flyweight {
    public static void main(String[] args) {
        Factory f = new Factory();

        Flyweight_ f1 = f.getFlyweight("A");
        Flyweight_ f2 = f.getFlyweight("A");
        f1.method("1");
        f2.method("2");

        Flyweight_ f3 = f.getFlyweight("B");
        f3.method("3");
    }
}
