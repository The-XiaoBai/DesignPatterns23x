/*****
 * Proxy
 * Provides a proxy that allows other objects to control access to this object.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Subject { public: virtual void method() = 0; };

class ConcreteSubject : public Subject { public: void method() override { cout << "..." << endl; } };

class Proxy : public Subject {
    unique_ptr<ConcreteSubject> concreteSubject;

    bool validateAccess() { return true; }

public:
    Proxy() : concreteSubject(make_unique<ConcreteSubject>()) {}

    void method() override {
        if (validateAccess()) {
            cout << "Proxy: Start" << endl;
            concreteSubject->method();
            cout << "Proxy: End" << endl;
        }
    }
};


int main() {
    auto client = make_unique<Proxy>();
    client->method();
    
    return 0;
}
