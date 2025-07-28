/*****
 * Iterator
 * Provide a way to access the elements of an aggregate object
 * sequentially without exposing its underlying representation.
*****/


class Iterator {
    hasNext() {}
    next() {}
}

class ConcreteIterator extends Iterator {
    constructor(items) {
        super();
        this.items = items;
        this.index = 0;
    }
  
    hasNext() { return this.index < this.items.length; }
    next() { return this.items[this.index++]; }
}

class Aggregate {
    constructor() { this.items = []; }
  
    getItems() { return this.items; }
    add(value) { this.items.push(value); }
}


const a = new Aggregate();
a.add(1);
a.add(2);
a.add(3);
  
const i = new ConcreteIterator(a.getItems());
while (i.hasNext()) console.log(i.next());
