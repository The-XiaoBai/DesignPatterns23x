/*****
 * Singleton
 * Ensure a class has only one instance, and provide a global point of access to it.
*****/


class Singleton_ {
    private static volatile Singleton_ instance;

    public static Singleton_ getInstance() {
        if (instance == null) synchronized (Singleton_.class) {
            if (instance == null) instance = new Singleton_();
        }
        return instance;
    }

    public void method() { System.out.println("Singleton"); }
}


public class Singleton {
    public static void main(String[] args) {
        Singleton_ s = Singleton_.getInstance();
        s.method();
    }
}
