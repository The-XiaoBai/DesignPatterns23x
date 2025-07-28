/*****
 * Mediator
 * Use a mediator object to encapsulate a series of object interactions.
*****/


class Mediator { broadcast(msg) {} }

class ConcreteMediator extends Mediator { broadcast(msg) { console.log(msg); } }

class Colleague {
    constructor(mediator) { this.mediator = mediator; }
    send(msg) {}
}

class ConcreteColleague extends Colleague {
    constructor(mediator) { super(mediator); }
    send(msg) { this.mediator.broadcast(msg); }
}


const m = new ConcreteMediator();
const c = new ConcreteColleague(m);
  
c.send("Hello!");
