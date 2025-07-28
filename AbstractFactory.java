/*****
 * Abstract Factory
 * Create a series of related objects without specifying a specific class
 * to produce a series of objects.
*****/


interface ProductA { void method(); }

class ProductA1 implements ProductA {
    @Override
    public void method() { System.out.println("Product A1"); }
}

class ProductA2 implements ProductA {
    @Override
    public void method() { System.out.println("Product A2"); }
}

interface ProductB { void method(); }

class ProductB1 implements ProductB {
    @Override
    public void method() { System.out.println("Product B1"); }
}

class ProductB2 implements ProductB {
    @Override
    public void method() { System.out.println("Product B2"); }
}

abstract class AbstractFactory_ {
    public abstract ProductA createA();
    public abstract ProductB createB();
}

class Factory1 extends AbstractFactory_ {
    @Override
    public ProductA createA() { return new ProductA1(); }

    @Override
    public ProductB createB() { return new ProductB1(); }
}

class Factory2 extends AbstractFactory_ {
    @Override
    public ProductA createA() { return new ProductA2(); }

    @Override
    public ProductB createB() { return new ProductB2(); }
}


public class AbstractFactory {
    public static void main(String[] args) {
        AbstractFactory_ f1 = new Factory1();
        AbstractFactory_ f2 = new Factory2();

        ProductA a1 = f1.createA();
        ProductB b1 = f1.createB();
        ProductA a2 = f2.createA();
        ProductB b2 = f2.createB();

        a1.method();
        b1.method();
        a2.method();
        b2.method();
    }
}
