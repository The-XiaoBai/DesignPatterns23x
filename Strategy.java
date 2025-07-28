/*****
 * Strategy
 * Define a family of algorithms, encapsulate each one, and make them interchangeable.
*****/


interface Strategy_ { void method(); }

class Strategy1 implements Strategy_ {
    @Override
    public void method() { System.out.println("Strategy 1"); }
}

class Strategy2 implements Strategy_ {
    @Override
    public void method() { System.out.println("Strategy 2"); }
}

class Context {
    private Strategy_ strategy;

    public void setStrategy(Strategy_ strategy) { this.strategy = strategy; }
    public void method() { if (strategy != null) strategy.method(); }
}


public class Strategy {
    public static void main(String[] args) {
        Context c = new Context();

        c.setStrategy(new Strategy1());
        c.method();

        c.setStrategy(new Strategy2());
        c.method();
    }
}
