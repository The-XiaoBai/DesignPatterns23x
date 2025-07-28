"""
Prototype
Create a new object by copying a prototype of an existing object.
"""

from abc import ABC, abstractmethod


class Prototype(ABC):
    @abstractmethod
    def clone(self) -> 'Prototype':
        pass

    @abstractmethod
    def show(self) -> None:
        pass


class ConcretePrototypeA(Prototype):
    def __init__(self, value):
        self.value = value
    
    def clone(self):
        return ConcretePrototypeA(self.value)
    
    def show(self):
        print(self.value)


if __name__ == "__main__":
    p = ConcretePrototypeA(1)
    p_clone = p.clone()
    
    p_clone.show()
