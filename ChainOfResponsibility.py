"""
Chain of Responsibility
Avoid coupling the sender of a request to its receiver
by giving more than one object a chance to handle the request.
"""

from abc import ABC, abstractmethod


class Handler(ABC):
    def __init__(self):
        self.next = None

    def set_next(self, next_handler):
        self.next = next_handler
        return self.next

    @abstractmethod
    def handle(self, level):
        pass

class ConcreteHandler1(Handler):
    def handle(self, level):
        if level < 10:
            print(f"Handler 1: {level}")
        elif self.next:
            self.next: Handler
            self.next.handle(level)

class ConcreteHandler2(Handler):
    def handle(self, level):
        if level >= 10:
            print(f"Handler 2: {level}")
        elif self.next:
            self.next: Handler
            self.next.handle(level)


if __name__ == "__main__":
    h1 = ConcreteHandler1()
    h2 = ConcreteHandler2()

    h1.set_next(h2)
    h1.handle(5)
    h1.handle(15)
