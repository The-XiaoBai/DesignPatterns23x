/*****
 * Composite
 * Represents objects as apart-whole tree structure
 * to ensure consistent use.
*****/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Component {
    public:
        virtual ~Component() = default;

        virtual void method() = 0;
        virtual void add(unique_ptr<Component>) { throw logic_error("Not allowed"); }
};

class Composite : public Component {
    vector<unique_ptr<Component>> children;

    public:
        void method() override {
            cout << "Composite" << endl;
            for (const auto& child : children) { child->method(); }
        }
        
        void add(unique_ptr<Component> child) override { children.push_back(move(child)); }
};

class Child : public Component { public: void method() override { cout << "Child" << endl; } };


int main() {
    auto child = make_unique<Child>();

    auto composite = make_unique<Composite>();
    composite->add(move(child));

    auto root = make_unique<Composite>();
    root->add(move(composite));

    root->method();

    return 0;
}
