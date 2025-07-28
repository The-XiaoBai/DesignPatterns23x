/*****
 * Interpreter
 * Define an interpreter to interpret sentences in a
 * language based on grammatical representations.
*****/


class Expression { interpret(context) {} }

class VariableExpression extends Expression {
    constructor(variable) {
        super();
        this.variable = variable;
    }

    interpret(context) { return context[this.variable]; }
}


const v = new VariableExpression('x');
const context = { 'x': 10, 'y': 20 };
const result = v.interpret(context);

console.log(result);
