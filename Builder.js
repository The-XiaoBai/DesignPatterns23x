/*****
 * Builder
 * By separating the representation and construction of a complex class,
 * different representations can be obtained during the same construction process.
*****/


class Product {
    constructor() {
        this.value1 = '';
        this.value2 = '';
        this.value3 = '';
    }

    setValue1(newValue) { this.value1 = newValue; }
    setValue2(newValue) { this.value2 = newValue; }
    setValue3(newValue) { this.value3 = newValue; }

    method() { console.log(`${this.value1}, ${this.value2}, ${this.value3}`); }
}

class Builder {
    constructor() { this.product = null; }

    buildStep1() {}
    buildStep2() {}
    buildStep3() {}

    getProduct() { return this.product; }
}

class ConcreteBuilder extends Builder {
    buildStep1() {
        if (!this.product) this.product = new Product();
        this.product.setValue1("Value1");
    }

    buildStep2() {
        if (!this.product) this.product = new Product();
        this.product.setValue2("Value2");
    }

    buildStep3() {
        if (!this.product) this.product = new Product();
        this.product.setValue3("Value3");
    }
}

class Director {
    constructor() { this.builder = null; }

    setBuilder(builder) { this.builder = builder; }

    construct() {
        if (this.builder) {
            this.builder.buildStep1();
            this.builder.buildStep2();
            this.builder.buildStep3();
        }
        
        return this.builder.getProduct();
    }
}


const d = new Director();
d.setBuilder(new ConcreteBuilder());

const product = d.construct();
product.method();
