/*****
 * Memento
 * Capture and externalize an object's internal state
 * so that the object can be restored to this state later.
*****/


class Memento {
    constructor(state) { this.state = state; }
    getState() { return this.state; }
}

class Originator {
    constructor() { this.state = ''; }

    setState(state) { this.state = state; }
    getState() { return this.state; }
    save() { return new Memento(this.state); }
    restore(memento) { this.state = memento.getState(); }
}

class Caretaker {
    constructor() { this.memento = null; }
    
    saveState(originator) { this.memento = originator.save(); }
    restoreState(originator) { if (this.memento) originator.restore(this.memento); }
}


const o = new Originator();
const c = new Caretaker();
  
o.setState('State 1');
c.saveState(o);
  
o.setState('State 2');
console.log(o.getState());
  
c.restoreState(o);
console.log(o.getState());
