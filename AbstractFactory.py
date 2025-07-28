"""
Abstract Factory
Create a series of related objects without specifying a specific class
to produce a series of objects.
"""

from abc import ABC, abstractmethod


class ProductA(ABC):
    @abstractmethod
    def method(self):
        pass

class ProductA1(ProductA):
    def method(self):
        print("Product A1")

class ProductA2(ProductA):
    def method(self):
        print("Product A2")

class ProductB(ABC):
    @abstractmethod
    def method(self):
        pass

class ProductB1(ProductB):
    def method(self):
        print("Product B1")

class ProductB2(ProductB):
    def method(self):
        print("Product B2")

class AbstractFactory(ABC):
    @abstractmethod
    def createA(self) -> ProductA:
        pass
    
    @abstractmethod
    def createB(self) -> ProductB:
        pass

class Factory1(AbstractFactory):
    def createA(self):
        return ProductA1()
    
    def createB(self):
        return ProductB1()

class Factory2(AbstractFactory):
    def createA(self):
        return ProductA2()
    
    def createB(self):
        return ProductB2()


if __name__ == "__main__":
    f1 = Factory1()
    f2 = Factory2()

    a1 = f1.createA()
    b1 = f1.createB()
    a2 = f2.createA()
    b2 = f2.createB()

    a1.method()
    b1.method()
    a2.method()
    b2.method()
