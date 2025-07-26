/*****
 * Iterator
 * Provide a way to access the elements of an aggregate object
 * sequentially without exposing its underlying representation.
*****/

#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Iterator {
    public:
        virtual ~Iterator() = default;
        virtual bool hasNext() = 0;
        virtual int next() = 0;
};

class ConcreteIterator : public Iterator {
    vector<int>& items;
    size_t index = 0;

    public:
        explicit ConcreteIterator(vector<int>& items) : items(items) {}
        bool hasNext() override { return index < items.size(); }
        int next() override { return items[index++]; }
};

class Aggregate {
    vector<int> items;

    public:
        void add(int value) { items.push_back(value); }
        vector<int>& getItems() { return items; }
};


int main() {
    Aggregate a;
    a.add(1);
    a.add(2);
    a.add(3);

    ConcreteIterator i(a.getItems());
    while (i.hasNext()) cout << i.next() << endl;

    return 0;
}
