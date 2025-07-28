/*****
 * Chain of Responsibility
 * Avoid coupling the sender of a request to its receiver
 * by giving more than one object a chance to handle the request.
*****/


abstract class Handler {
    protected Handler next;

    public void setNext(Handler next) { this.next = next; }
    public abstract void handle(int level);
}

class ConcreteHandler1 extends Handler {
    @Override
    public void handle(int level) {
        if (level < 10) System.out.println("Handler 1: " + level);
        else if (next != null) next.handle(level);
    }
}

class ConcreteHandler2 extends Handler {
    @Override
    public void handle(int level) {
        if (level >= 10) System.out.println("Handler 2: " + level);
        else if (next != null) next.handle(level);
    }
}


public class ChainOfResponsibility {
    public static void main(String[] args) {
        ConcreteHandler1 h1 = new ConcreteHandler1();
        ConcreteHandler2 h2 = new ConcreteHandler2();

        h1.setNext(h2);
        h1.handle(5);
        h1.handle(15);
    }
}
