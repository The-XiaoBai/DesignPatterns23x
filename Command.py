"""
Command
Encapsulate a request as an object,
thereby letting you parameterize clients with different requests,
queue or log requests, and support undoable operations.
"""

from abc import ABC, abstractmethod


class Command(ABC):
    @abstractmethod
    def execute(self):
        pass

class Receiver:
    def method(self):
        print("Receiver")

class ConcreteCommand(Command):
    def __init__(self, receiver: Receiver):
        self.receiver = receiver

    def execute(self):
        self.receiver.method()

class Invoker:
    def __init__(self):
        self.commands: list[Command] = []

    def add(self, command: Command):
        self.commands.append(command)

    def execute(self):
        for command in self.commands:
            command.execute()


if __name__ == "__main__":
    r = Receiver()
    i = Invoker()

    cmd = ConcreteCommand(r)
    i.add(cmd)
    i.execute()
