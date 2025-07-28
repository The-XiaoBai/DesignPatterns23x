"""
Builder
By separating the representation and construction of a complex class,
different representations can be obtained during the same construction process.
"""

from abc import ABC, abstractmethod
from typing import Optional


class Product:
    def __init__(self):
        self.value1:str = ''
        self.value2:str = ''
        self.value3:str = ''

    def set_value1(self, new_value):
        self.value1 = new_value

    def set_value2(self, new_value):
        self.value2 = new_value

    def set_value3(self, new_value):
        self.value3 = new_value

    def method(self):
        print(f"{self.value1}, {self.value2}, {self.value3}")

class Builder(ABC):
    def __init__(self):
        self.product = None

    @abstractmethod
    def build_step1(self):
        pass

    @abstractmethod
    def build_step2(self):
        pass

    @abstractmethod
    def build_step3(self):
        pass

    def get_product(self):
        return self.product

class ConcreteBuilder(Builder):
    def build_step1(self):
        if self.product is None:
            self.product = Product()
        self.product.set_value1("Value1")

    def build_step2(self):
        if self.product is None:
            self.product = Product()
        self.product.set_value2("Value2")

    def build_step3(self):
        if self.product is None:
            self.product = Product()
        self.product.set_value3("Value3")

class Director:
    def __init__(self):
        self.builder: Optional[Builder] = None

    def set_builder(self, builder):
        self.builder = builder

    def construct(self):
        if self.builder:
            self.builder.build_step1()
            self.builder.build_step2()
            self.builder.build_step3()
            return self.builder.get_product()
        return None


if __name__ == "__main__":
    d = Director()
    d.set_builder(ConcreteBuilder())
    product = d.construct()
    if product is not None:
        product.method()
