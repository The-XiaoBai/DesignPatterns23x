/*****
 * Adapter
 * Transform interfaces so that otherwise incompatible interfaces work together.
*****/

#include <iostream>
#include <memory>

using namespace std;


class Adaptee { public: string originalMethod() const { return "old"; } };

class Target { public: virtual string adaptedMethod() const = 0; };

class Adapter : public Target {
    private:
        const Adaptee* adaptee;

    public:
        explicit Adapter(const Adaptee* adaptee) : adaptee(adaptee) {}

        string adaptedMethod() const override {
            string old_value = adaptee->originalMethod();
            return old_value+"=>"+"new";
        }
};


int main() {
    auto adaptee = make_unique<Adaptee>();
    auto target = make_unique<Adapter>(adaptee.get());

    string value = target->adaptedMethod();
    cout << value << endl;

    return 0;
}
