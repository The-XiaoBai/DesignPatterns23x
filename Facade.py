"""
Facade
Provide a unified interface to a set of interfaces in a subsystem.
Facade defines a higher-level interface that makes the subsystem easier to use.
"""


class System1:
    def method(self):
        print("System 1")

class System2:
    def method(self):
        print("System 2")

class Facade:
    def __init__(self):
        self.system1 = System1()
        self.system2 = System2()

    def method(self):
        self.system1.method()
        self.system2.method()


if __name__ == "__main__":
    f = Facade()
    f.method()
