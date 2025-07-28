"""
Decorator
Attach additional responsibilities to an object dynamically.
Decorators provide a flexible alternative to subclassing for extending functionality.
"""

from abc import ABC, abstractmethod


class Component(ABC):
    @abstractmethod
    def method(self):
        pass

class Base(Component):
    def method(self):
        print("Base")

class Decorator(Component):
    def __init__(self, component):
        self.component:Component = component

    def method(self):
        self.component.method()

class ConcreteDecorator1(Decorator):
    def method(self):
        super().method()
        print("Concrete Decorator 1")

class ConcreteDecorator2(Decorator):
    def method(self):
        super().method()
        print("Concrete Decorator 2")


if __name__ == "__main__":
    b = Base()
    d1 = ConcreteDecorator1(b)
    d2 = ConcreteDecorator2(d1)

    d2.method()
