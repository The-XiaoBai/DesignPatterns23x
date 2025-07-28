/*****
 * Iterator
 * Provide a way to access the elements of an aggregate object
 * sequentially without exposing its underlying representation.
*****/

import java.util.ArrayList;
import java.util.List;


interface IteratorInterface<T> {
    boolean hasNext();
    T next();
}

class ConcreteIterator<T> implements IteratorInterface<T> {
    private final List<T> items;
    private int index = 0;
    
    public ConcreteIterator(List<T> items) { this.items = items; }
    
    @Override
    public boolean hasNext() { return index < items.size(); }
    
    @Override
    public T next() { return items.get(index++); }
}

class Aggregate<T> {
    private final List<T> items = new ArrayList<>();
    
    public void add(T value) { items.add(value); }
    public List<T> getItems() { return items; }
}


public class Iterator {
    public static void main(String[] args) {
        Aggregate<Integer> a = new Aggregate<>();
        a.add(1);
        a.add(2);
        a.add(3);
        
        IteratorInterface<Integer> i = new ConcreteIterator<>(a.getItems());
        while (i.hasNext()) System.out.println(i.next());
    }
}
