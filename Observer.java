/*****
 * Observer
 * Define a one-to-many dependency so that when one object changes state,
 * all its dependents are notified and updated automatically.
*****/

import java.util.List;
import java.util.ArrayList;


interface Observer_ { void update(int state); }

class ConcreteObserver implements Observer_ { public void update(int state) { System.out.println(state); } }

class Subject {
    private List<Observer_> Observers = new ArrayList<>();
    private int state = 0;

    public void attach(Observer_ o) { Observers.add(o); }

    public void setState(int newState) {
        state = newState;
        for (Observer_ Observer_ : Observers) Observer_.update(state);
    }
}


public class Observer {
    public static void main(String[] args) {
        Subject s = new Subject();
        ConcreteObserver o = new ConcreteObserver();

        s.attach(o);
        s.setState(10);
        s.setState(20);
    }
}
