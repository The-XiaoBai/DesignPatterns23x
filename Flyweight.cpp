/*****
 * Flyweight
 * Enables a large number of fine-grained objects to be shared.
*****/

#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

using namespace std;


class Flyweight { public: virtual void method(const string& name) = 0; };

class ConcreteFlyweight : public Flyweight {
    string key;

    public:
        explicit ConcreteFlyweight(string state) : key(move(state)) {}
        void method(const string& name) override { cout << key << "-" << name << endl; }
};

class Factory {
    unordered_map<string, unique_ptr<Flyweight>> flyweights;

    public:
        Flyweight* getFlyweight(const string& key) {
            auto it = flyweights.find(key);
            if (it == flyweights.end()) {
                it = flyweights.emplace(key, make_unique<ConcreteFlyweight>(key)).first;
            }
            return it->second.get();
        }
};


int main() {
    Factory f;
    
    Flyweight* f1 = f.getFlyweight("A");
    Flyweight* f2 = f.getFlyweight("A");
    f1->method("1");
    f2->method("2");
    
    Flyweight* f3 = f.getFlyweight("B");
    f3->method("3");
    
    return 0;
}
