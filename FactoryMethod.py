"""
Factory Method
Define an interface for creating an object, but let subclasses decide which class to instantiate.
Factory Method lets a class defer instantiation to subclasses.
"""

from abc import ABC, abstractmethod


class Product(ABC):
    @abstractmethod
    def method(self):
        pass

class ConcreteProduct(Product):
    def method(self):
        print("Concrete Product")

class Factory(ABC):
    @abstractmethod
    def create(self) -> Product:
        pass

class ConcreteFactory(Factory):
    def create(self):
        return ConcreteProduct()


if __name__ == "__main__":
    f = ConcreteFactory()
    product = f.create()

    product.method()
