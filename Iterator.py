"""
Iterator
Provide a way to access the elements of an aggregate object
sequentially without exposing its underlying representation.
"""

from abc import ABC, abstractmethod


class Iterator(ABC):
    @abstractmethod
    def has_next(self) -> bool:
        pass
    
    @abstractmethod
    def next(self):
        pass

class ConcreteIterator(Iterator):
    def __init__(self, items):
        self.items = items
        self.index = 0
    
    def has_next(self):
        return self.index < len(self.items)
    
    def next(self):
        item = self.items[self.index]
        self.index += 1
        return item

class Aggregate:
    def __init__(self):
        self.items = []
    
    def add(self, value):
        self.items.append(value)
    
    def get_items(self):
        return self.items


if __name__ == "__main__":
    a = Aggregate()
    a.add(1)
    a.add(2)
    a.add(3)
    
    i = ConcreteIterator(a.get_items())
    while i.has_next():
        print(i.next())
