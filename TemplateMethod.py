"""
Template Method
Define the skeleton of an algorithm in an operation,
deferring some steps to subclasses.
"""

from abc import ABC, abstractmethod


class AbstractClass(ABC):
    def base_method1(self):
        print("Base Method 1")

    def base_method2(self):
        print("Base Method 2")

    @abstractmethod
    def concrete_method1(self):
        pass

    @abstractmethod
    def concrete_method2(self):
        pass

    def optional_method(self):
        """Optional hook method"""
        pass

    def method(self):
        """Template method defining the algorithm structure"""
        self.base_method1()
        self.concrete_method1()
        self.base_method2()
        self.concrete_method2()
        self.optional_method()

class ConcreteClass(AbstractClass):
    def concrete_method1(self):
        print("Concrete Method 1")

    def concrete_method2(self):
        print("Concrete Method 2")

    def optional_method(self):
        print("Optional Method")


if __name__ == "__main__":
    obj = ConcreteClass()
    obj.method()
