"""
Observer
Define a one-to-many dependency so that when one object changes state,
all its dependents are notified and updated automatically.
"""

from abc import ABC, abstractmethod


class Observer(ABC):
    @abstractmethod
    def update(self, state):
        pass

class ConcreteObserver(Observer):
    def update(self, state):
        print(state)

class Subject:
    def __init__(self):
        self.observers = []
        self.state = 0

    def attach(self, o):
        self.observers.append(o)

    def set_state(self, new_state):
        self.state = new_state
        for observer in self.observers:
            observer: Observer
            observer.update(self.state)


if __name__ == "__main__":
    s = Subject()
    o = ConcreteObserver()

    s.attach(o)
    s.set_state(10)
    s.set_state(20)
