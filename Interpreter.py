"""
Interpreter
Define an interpreter to interpret sentences in a
language based on grammatical representations.
"""

from abc import ABC, abstractmethod


class Expression(ABC):
    @abstractmethod
    def interpret(self, context):
        pass

class VariableExpression(Expression):
    def __init__(self, variable):
        self.variable = variable
    
    def interpret(self, context):
        if self.variable not in context:
            raise ValueError(f"Variable {self.variable} not found in context")
        return context[self.variable]


if __name__ == "__main__":
    v = VariableExpression('x')
    context = {'x': 10, 'y': 20}
    result = v.interpret(context)
    
    print(result)
