"""
Strategy
Define a family of algorithms, encapsulate each one, and make them interchangeable.
"""

from abc import ABC, abstractmethod


class Strategy(ABC):
    @abstractmethod
    def method(self):
        pass

class Strategy1(Strategy):
    def method(self):
        print("Strategy 1")

class Strategy2(Strategy):
    def method(self):
        print("Strategy 2")

class Context:
    def __init__(self):
        self.strategy: None|Strategy = None

    def setStrategy(self, strategy):
        self.strategy = strategy

    def method(self):
        if self.strategy:
            self.strategy.method()


if __name__ == "__main__":
    c = Context()

    c.setStrategy(Strategy1())
    c.method()
    
    c.setStrategy(Strategy2())
    c.method()
