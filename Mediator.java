/*****
 * Mediator
 * Use a mediator object to encapsulate a series of object interactions.
*****/


interface MediatorInterface { void broadcast(String msg); }

class ConcreteMediator implements MediatorInterface {
    @Override
    public void broadcast(String msg) { System.out.println(msg); }
}

abstract class Colleague {
    protected MediatorInterface mediator;
    
    public Colleague(MediatorInterface mediator) { this.mediator = mediator; }
    
    public abstract void send(String msg);
}

class ConcreteColleague extends Colleague {
    public ConcreteColleague(MediatorInterface mediator) { super(mediator); }
    
    @Override
    public void send(String msg) { mediator.broadcast(msg); }
}


public class Mediator {
    public static void main(String[] args) {
        ConcreteMediator m = new ConcreteMediator();
        ConcreteColleague c = new ConcreteColleague(m);
        
        c.send("Hello!");
    }
}
