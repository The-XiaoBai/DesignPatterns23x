"""
Memento
Capture and externalize an object's internal state
so that the object can be restored to this state later.
"""


class Memento:
    def __init__(self, state):
        self._state = state
    
    def get_state(self):
        return self._state

class Originator:
    def __init__(self):
        self._state = ""
    
    def set_state(self, state):
        self._state = state
    
    def get_state(self):
        return self._state
    
    def save(self):
        return Memento(self._state)
    
    def restore(self, memento: Memento):
        self._state = memento.get_state()

class Caretaker:
    def __init__(self):
        self._memento = None
    
    def save_state(self, originator: Originator):
        self._memento = originator.save()
    
    def restore_state(self, originator: Originator):
        if self._memento:
            originator.restore(self._memento)


if __name__ == "__main__":
    o = Originator()
    c = Caretaker()
    
    o.set_state("State 1")
    c.save_state(o)
    
    o.set_state("State 2")
    print(o.get_state())
    
    c.restore_state(o)
    print(o.get_state())
