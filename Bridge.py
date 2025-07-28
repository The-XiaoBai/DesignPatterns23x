"""
Bridge
Remove the abstract part of the classification
from the concrete implementation part
so that it can be changed flexibly.
"""

from abc import ABC, abstractmethod


class Implementor(ABC):
    @abstractmethod
    def method(self):
        pass

class ConcreteImplementor(Implementor):
    def method(self):
        print("Concrete Implementor")

class Controller:
    def __init__(self, implementor):
        self.implementor:Implementor = implementor

    def method(self):
        self.implementor.method()


if __name__ == "__main__":
    i = ConcreteImplementor()
    c = Controller(i)

    c.method()
