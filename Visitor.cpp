/*****
 * Visitor
 * Represent an operation to be performed on the elements of an object structure.
*****/

#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Element;

class Visitor { public: virtual void visit(Element* e) = 0; };

class Element { public: virtual void accept(Visitor* v) = 0; };

class Element1 : public Element { public: void accept(Visitor* v) override { v->visit(this); } };

class Element2 : public Element { public: void accept(Visitor* v) override { v->visit(this); } };

class ConcreteVisitor : public Visitor {
    public:
        void visit(Element* e) override {
            if (dynamic_cast<Element1*>(e)) cout << "Element 1" << endl;
            else if (dynamic_cast<Element2*>(e)) cout << "Element 2" << endl;
        }
};


int main() {
    vector<unique_ptr<Element>> elements;
    elements.push_back(make_unique<Element1>());
    elements.push_back(make_unique<Element2>());

    ConcreteVisitor visitor;
    for (auto& e : elements) e->accept(&visitor);
    
    return 0;
}
