/*****
 * Interpreter
 * Define an interpreter to interpret sentences in a
 * language based on grammatical representations.
*****/

import java.util.Map;
import java.util.HashMap;


interface Expression { int interpret(Map<String, Integer> context); }

class VariableExpression implements Expression {
    private final String variable;
    
    public VariableExpression(String variable) { this.variable = variable; }
    
    @Override
    public int interpret(Map<String, Integer> context) { return context.get(variable); }
}


public class Interpreter {
    public static void main(String[] args) {
        Expression v = new VariableExpression("x");
        Map<String, Integer> context = new HashMap<>();
        context.put("x", 10);
        context.put("y", 20);
        
        int result = v.interpret(context);
        System.out.println(result);
    }
}
