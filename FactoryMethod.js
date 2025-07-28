/*****
 * Factory Method
 * Define an interface for creating an object, but let subclasses decide which class to instantiate.
 * Factory Method lets a class defer instantiation to subclasses.
*****/


class Product { method() {} }

class ConcreteProduct extends Product { method() { console.log("Concrete Product"); } }

class Factory { create() {} }

class ConcreteFactory extends Factory { create() { return new ConcreteProduct(); } }


const f = new ConcreteFactory();
const product = f.create();

product.method();
