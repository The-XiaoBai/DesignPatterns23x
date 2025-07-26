/*****
 * Interpreter
 * Define an interpreter to interpret sentences in a
 * language based on grammatical representations.
*****/

#include <iostream>
#include <memory>
#include <map>

using namespace std;


class Expression { public: virtual int interpret(const map<string, int>& context) = 0; };

class VariableExpression : public Expression {
    string variable;

    public:
        explicit VariableExpression(string var) : variable(move(var)) {}
        int interpret(const map<string, int>& context) override { return context.at(variable); }
};


int main() {
    auto v = make_shared<VariableExpression>("x");
    map<string, int> context{{"x", 10}, {"y", 20}};
    auto result = v->interpret(context);
    
    cout << result << endl;

    return 0;
}
