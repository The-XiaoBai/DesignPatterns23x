/*****
 * Builder
 * By separating the representation and construction of a complex class,
 * different representations can be obtained during the same construction process.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Product {
    string value1;
    string value2;
    string value3;

    public:
        void setValue1(const string& new_value) { value1 = new_value; }
        void setValue2(const string& new_value) { value2 = new_value; }
        void setValue3(const string& new_value) { value3 = new_value; }

        void method() const { cout << value1 << ", " << value2 << ", " << value3 << endl; }
};

class Builder {
    protected:
        unique_ptr<Product> product;

    public:
        Builder() = default;
        Builder(const Builder&) = delete;
        Builder& operator=(const Builder&) = delete;
        ~Builder() = default;

        virtual void buildStep1() = 0;
        virtual void buildStep2() = 0;
        virtual void buildStep3() = 0;
    
        unique_ptr<Product> getProduct() { return move(product); }
};

class ConcreteBuilder : public Builder {
    public:
        void buildStep1() override {
            if (!product) product = make_unique<Product>();
            product->setValue1("Value1");
        }

        void buildStep2() override {
            if (!product) product = make_unique<Product>();
            product->setValue2("Value2");
        }

        void buildStep3() override {
            if (!product) product = make_unique<Product>();
            product->setValue3("Value3");
        }
};

class Director {
    unique_ptr<Builder> builder;

    public:
        void setBuilder(unique_ptr<Builder> new_builder) { builder = move(new_builder); }

        unique_ptr<Product> construct() {
            if (builder) {
                builder->buildStep1();
                builder->buildStep2();
                builder->buildStep3();
            }
            
            return builder->getProduct();
        }
};


int main() {
    Director d;

    d.setBuilder(make_unique<ConcreteBuilder>());
    auto product = d.construct();
    product->method();

    return 0;
}
