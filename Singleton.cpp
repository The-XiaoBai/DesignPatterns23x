/*****
 * Singleton 单例模式
 * 保证类只有一个实例并提供此实例的唯一访问点
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
