/*****
 * Singleton
 * Ensure a class has only one instance, and provide a global point of access to it.
*****/

#include <iostream>

using namespace std;


class Singleton {
    private:
        Singleton() {}
        static Singleton* instance;
    
    public:
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

        static Singleton *getInstance() { return instance ? instance : (instance = new Singleton()); }
        void method() { cout << "Singleton" << endl; }
};
Singleton *Singleton::instance = nullptr;


int main() {
    Singleton* s=Singleton::getInstance();
    s->method();

    return 0;
}
