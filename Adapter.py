"""
Adapter
Transform interfaces so that otherwise incompatible interfaces work together.
"""

from abc import ABC, abstractmethod


class Adaptee:
    def original_method(self):
        return "old"

class Target(ABC):
    @abstractmethod
    def adapted_method(self) -> str:
        pass

class Adapter(Target):
    def __init__(self, adaptee):
        self.adaptee:Adaptee = adaptee

    def adapted_method(self):
        old_value = self.adaptee.original_method()
        return f"{old_value}=>new"


if __name__ == "__main__":
    adaptee = Adaptee()
    target = Adapter(adaptee)

    value = target.adapted_method()
    print(value)
