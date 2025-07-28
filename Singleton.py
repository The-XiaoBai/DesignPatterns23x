"""
Singleton
Ensure a class has only one instance, and provide a global point of access to it.
"""


class Singleton:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance

    def method(self):
        print("Singleton")


if __name__ == "__main__":
    s = Singleton()
    s.method()
