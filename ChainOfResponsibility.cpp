/*****
 * Chain of Responsibility
 * Avoid coupling the sender of a request to its receiver
 * by giving more than one object a chance to handle the request.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Handler {
    protected:
        unique_ptr<Handler> next;

    public:
        virtual ~Handler() = default;
        
        void setNext(unique_ptr<Handler> n) { next = move(n); }
        virtual void handle(int level) { if (next) next->handle(level); }
};

class ConcreteHandler1 : public Handler {
    public:
        void handle(int level) override {
            if (level < 10) cout << "Handler 1: " << level << endl;
            else if (next) next->handle(level);
        }
};

class ConcreteHandler2 : public Handler {
    public:
        void handle(int level) override {
            if (level >= 10) cout << "Handler 2: " << level << endl;
            else if (next) next->handle(level);
        }
};


int main() {
    auto h1 = make_unique<ConcreteHandler1>();
    auto h2 = make_unique<ConcreteHandler2>();

    h1->setNext(move(h2));
    h1->handle(5);
    h1->handle(15);

    return 0;
}