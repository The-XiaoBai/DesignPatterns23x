/*****
 * Command
 * Encapsulate a request as an object,
 * thereby letting you parameterize clients with different requests,
 * queue or log requests, and support undoable operations.
*****/


class Command { execute() {} }

class Receiver { method() { console.log("Receiver"); } }

class ConcreteCommand extends Command {
    constructor(receiver) {
        super();
        this.receiver = receiver;
    }

    execute() { this.receiver.method(); }
}

class Invoker {
    constructor() { this.commands = []; }

    add(command) { this.commands.push(command); }
    execute() { for (const command of this.commands) command.execute(); }
}


const r = new Receiver();
const i = new Invoker();

const cmd = new ConcreteCommand(r);
i.add(cmd);
i.execute();
