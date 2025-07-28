/*****
 * Memento
 * Capture and externalize an object's internal state
 * so that the object can be restored to this state later.
*****/


class Memento_ {
    private final String state;
    
    public Memento_(String state) { this.state = state; }
    
    public String getState() { return state; }
}

class Originator {
    private String state;
    
    public void setState(String state) { this.state = state; }
    public String getState() { return state; }
    public Memento_ save() { return new Memento_(state); }
    public void restore(Memento_ memento) { state = memento.getState(); }
}

class Caretaker {
    private Memento_ memento;
    
    public void saveState(Originator originator) { memento = originator.save(); }
    
    public void restoreState(Originator originator) { if (memento != null) originator.restore(memento); }
}


public class Memento {
    public static void main(String[] args) {
        Originator o = new Originator();
        Caretaker c = new Caretaker();
        
        o.setState("State 1");
        c.saveState(o);
        
        o.setState("State 2");
        System.out.println(o.getState());
        
        c.restoreState(o);
        System.out.println(o.getState());
    }
}
