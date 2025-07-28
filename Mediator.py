"""
Mediator
Use a mediator object to encapsulate a series of object interactions.
"""

from abc import ABC, abstractmethod


class Mediator(ABC):
    @abstractmethod
    def broadcast(self, msg):
        pass

class ConcreteMediator(Mediator):
    def broadcast(self, msg):
        print(msg)

class Colleague(ABC):
    def __init__(self, mediator):
        self.mediator = mediator
    
    @abstractmethod
    def send(self, msg):
        pass

class ConcreteColleague(Colleague):
    def __init__(self, mediator):
        super().__init__(mediator)
    
    def send(self, msg):
        self.mediator: Mediator
        self.mediator.broadcast(msg)


if __name__ == "__main__":
    m = ConcreteMediator()
    c = ConcreteColleague(m)
    
    c.send("Hello!")
