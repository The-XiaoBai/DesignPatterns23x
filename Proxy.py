"""
Proxy
Provides a proxy that allows other objects to control access to this object.
"""

from abc import ABC, abstractmethod


class Subject(ABC):
    @abstractmethod
    def method(self):
        pass

class ConcreteSubject(Subject):
    def method(self):
        print("...")

class Proxy(Subject):
    def __init__(self):
        self.concrete_subject = ConcreteSubject()

    def validate_access(self):
        return True

    def method(self):
        if self.validate_access():
            print("Proxy: Start")
            self.concrete_subject.method()
            print("Proxy: End")


if __name__ == "__main__":
    client = Proxy()
    client.method()
