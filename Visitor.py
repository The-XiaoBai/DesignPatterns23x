"""
Visitor
Represent an operation to be performed on the elements of an object structure.
"""

from abc import ABC, abstractmethod


class Visitor(ABC):
    @abstractmethod
    def visit(self, element):
        pass

class Element(ABC):
    @abstractmethod
    def accept(self, visitor):
        pass

class Element1(Element):
    def accept(self, visitor: Visitor):
        visitor.visit(self)

class Element2(Element):
    def accept(self, visitor: Visitor):
        visitor.visit(self)

class ConcreteVisitor(Visitor):
    def visit(self, element):
        if isinstance(element, Element1):
            print("Element 1")
        elif isinstance(element, Element2):
            print("Element 2")


if __name__ == "__main__":
    elements = [Element1(), Element2()]
    visitor = ConcreteVisitor()
    for e in elements:
        e: Element
        e.accept(visitor)
