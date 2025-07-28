"""
Composite
Compose objects into tree structures to represent part-whole hierarchies.
Lets clients treat individual objects and compositions of objects uniformly.
"""

from abc import ABC, abstractmethod


class Component(ABC):
    @abstractmethod
    def method(self):
        pass

    def add(self, component):
        raise NotImplementedError("Not allowed")

class Composite(Component):
    def __init__(self):
        self.children: list[Component] = []

    def method(self):
        print("Composite")
        for child in self.children:
            child.method()

    def add(self, component):
        self.children.append(component)

class Child(Component):
    def method(self):
        print("Child")


if __name__ == "__main__":
    child = Child()

    composite = Composite()
    composite.add(child)

    root = Composite()
    root.add(composite)

    root.method()
