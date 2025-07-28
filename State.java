/*****
 * State
 * Allow an object to alter its behavior when its internal State changes.
*****/


interface State_ { void method(Context ctx); }

class State1 implements State_ {
    @Override
    public void method(Context ctx) { System.out.println("State 1"); }
}

class State2 implements State_ {
    @Override
    public void method(Context ctx) { System.out.println("State 2"); }
}

class Context {
    private State_ state;

    public Context(State_ s) { this.state = s; }

    public void method() {
        state.method(this);
        
        if (state instanceof State1)  state = new State2();
        else state = new State1();
    }
}


public class State {
    public static void main(String[] args) {
        Context c = new Context(new State1());

        c.method();
        c.method();
    }
}
