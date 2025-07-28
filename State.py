"""
State
Allow an object to alter its behavior when its internal state changes.
"""


class State1:
    def method(self, ctx):
        print("State 1")

class State2:
    def method(self, ctx):
        print("State 2")

class Context:
    def __init__(self, state):
        self.state = state

    def method(self):
        self.state.method(self)
        
        if isinstance(self.state, State1):
            self.state = State2()
        else:
            self.state = State1()


if __name__ == "__main__":
    c = Context(State1())
    c.method()
    c.method()
