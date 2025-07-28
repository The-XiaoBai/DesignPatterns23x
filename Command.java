/*****
 * Command
 * Encapsulate a request as an object,
 * thereby letting you parameterize clients with different requests,
 * queue or log requests, and support undoable operations.
*****/

import java.util.List;
import java.util.ArrayList;


interface Command_ { void execute(); }

class Receiver { public void method() { System.out.println("Receiver"); } }

class ConcreteCommand implements Command_ {
    private Receiver receiver;

    public ConcreteCommand(Receiver receiver) { this.receiver = receiver; }

    @Override
    public void execute() { receiver.method(); }
}

class Invoker {
    private List<Command_> commands = new ArrayList<>();

    public void add(Command_ command) { commands.add(command); }
    public void execute() { for (Command_ command : commands)  command.execute(); }
}


public class Command {
    public static void main(String[] args) {
        Receiver r = new Receiver();
        Invoker i = new Invoker();

        Command_ cmd = new ConcreteCommand(r);
        i.add(cmd);
        i.execute();
    }
}
