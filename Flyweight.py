"""
Flyweight
Enables a large number of fine-grained objects to be shared.
"""

from abc import ABC, abstractmethod


class Flyweight(ABC):
    @abstractmethod
    def method(self, name):
        pass

class ConcreteFlyweight(Flyweight):
    def __init__(self, state):
        self.key = state

    def method(self, name):
        print(f"{self.key}-{name}")

class Factory:
    def __init__(self):
        self.flyweights = {}

    def get_flyweight(self, key):
        if key not in self.flyweights:
            self.flyweights[key] = ConcreteFlyweight(key)
        return self.flyweights[key]


if __name__ == "__main__":
    f = Factory()

    f1:ConcreteFlyweight = f.get_flyweight("A")
    f2:ConcreteFlyweight = f.get_flyweight("A")
    f1.method("1")
    f2.method("2")

    f3:ConcreteFlyweight = f.get_flyweight("B")
    f3.method("3")
