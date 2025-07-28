/*****
 * Composite
 * Compose objects into tree structures to represent part-whole hierarchies.
 * Lets clients treat individual objects and compositions of objects uniformly.
*****/

import java.util.ArrayList;
import java.util.List;


abstract class Component {
    public abstract void method();
    public void add(Component component) {
        throw new UnsupportedOperationException("Not allowed");
    }
}

class Composite_ extends Component {
    private List<Component> children = new ArrayList<>();

    @Override
    public void method() {
        System.out.println("Composite");
        for (Component child : children) { child.method(); }
    }

    @Override
    public void add(Component component) { children.add(component); }
}

class Child extends Component {
    @Override
    public void method() { System.out.println("Child"); }
}


public class Composite {
    public static void main(String[] args) {
        Child child = new Child();

        Composite_ composite = new Composite_();
        composite.add(child);

        Composite_ root = new Composite_();
        root.add(composite);

        root.method();
    }
}
