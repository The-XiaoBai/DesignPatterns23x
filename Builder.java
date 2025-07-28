/*****
 * Builder
 * By separating the representation and construction of a complex class,
 * different representations can be obtained during the same construction process.
*****/


class Product {
    private String value1;
    private String value2;
    private String value3;

    public void setValue1(String newValue) { this.value1 = newValue; }
    public void setValue2(String newValue) { this.value2 = newValue; }
    public void setValue3(String newValue) { this.value3 = newValue; }

    public void method() { System.out.println(value1 + ", " + value2 + ", " + value3); }
}

abstract class Builder_ {
    protected Product product;

    public abstract void buildStep1();
    public abstract void buildStep2();
    public abstract void buildStep3();
    
    public Product getProduct() { return product; }
}

class ConcreteBuilder extends Builder_ {
    @Override
    public void buildStep1() {
        if (product == null) product = new Product();
        product.setValue1("Value1");
    }

    @Override
    public void buildStep2() {
        if (product == null) product = new Product();
        product.setValue2("Value2");
    }

    @Override
    public void buildStep3() {
        if (product == null) product = new Product();
        product.setValue3("Value3");
    }
}

class Director {
    private Builder_ builder;

    public void setBuilder(Builder_ builder) { this.builder = builder; }

    public Product construct() {
        if (builder != null) {
            builder.buildStep1();
            builder.buildStep2();
            builder.buildStep3();
        }
        
        return builder.getProduct();
    }
}


public class Builder {
    public static void main(String[] args) {
        Director d = new Director();
        d.setBuilder(new ConcreteBuilder());

        Product product = d.construct();
        product.method();
    }
}
