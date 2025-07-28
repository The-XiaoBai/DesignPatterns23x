/*****
 * Command
 * Encapsulate a request as an object,
 * thereby letting you parameterize clients with different requests,
 * queue or log requests, and support undoable operations.
*****/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;


class Command { public: virtual void execute() = 0; };

class Receiver { public: void method() { cout << "Receiver" << endl; } };

class ConcreteCommand : public Command {
    Receiver* receiver;

    public:
        explicit ConcreteCommand(Receiver* r) : receiver(r) {}
        void execute() override { receiver->method(); }
};

class Invoker {
    vector<unique_ptr<Command>> commands;

    public:
        void add(unique_ptr<Command> command) { commands.push_back(move(command)); }
        void execute() { for (auto& command : commands) command->execute(); }
};


int main() {
    Receiver r;
    Invoker i;
    
    auto cmd = make_unique<ConcreteCommand>(&r);
    i.add(move(cmd));
    i.execute();

    return 0;
}
