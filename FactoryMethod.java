/*****
 * Factory Method
 * Define an interface for creating an object, but let subclasses decide which class to instantiate.
 * Factory Method lets a class defer instantiation to subclasses.
*****/


interface Product { void method(); }

class ConcreteProduct implements Product {
    @Override
    public void method() { System.out.println("Concrete Product"); }
}

abstract class Factory { public abstract Product create(); }

class ConcreteFactory extends Factory {
    @Override
    public Product create() { return new ConcreteProduct(); }
}


public class FactoryMethod {
    public static void main(String[] args) {
        Factory f = new ConcreteFactory();
        Product product = f.create();

        product.method();
    }
}
