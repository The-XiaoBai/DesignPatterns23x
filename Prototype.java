/*****
 * Prototype
 * Create a new object by copying a prototype of an existing object.
*****/


interface Prototype_ {
    Prototype_ clone();
    void show();
}

class ConcretePrototypeA implements Prototype_ {
    private int value;
    
    public ConcretePrototypeA(int value) { this.value = value; }
    
    @Override
    public Prototype_ clone() { return new ConcretePrototypeA(this.value); }
    
    @Override
    public void show() { System.out.println(value); }
}


public class Prototype {
    public static void main(String[] args) {
        Prototype_ p = new ConcretePrototypeA(1);
        Prototype_ p_clone = p.clone();
        
        p_clone.show();
    }
}
