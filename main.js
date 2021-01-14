class Node {
    constructor(value) {
        this.value = value;
        this.next = null;
    }
}

class Stack {
    constructor() {
        this.head = null;
    }

    push(value) {
        if (this.head === null) {
            this.head = new Node(value);
        } else {
            const newNode = new Node(value);
            newNode.next = this.head;
            this.head = newNode;
        }
    }

    pop() {
        const value = this.head.value;
        let ref = this.head;
        this.head = this.head.next;
        ref = null;
        return value;
    }

    toArray() {
        const value = [];
        let ptr = this.head;
        while (ptr != null) {
            value.push(ptr.value);
            ptr = ptr.next;
        }
        return value;
    }
}

class Player {
    constructor(kind) {
        this.kind = kind;
        this.positions = new Stack();
    }

    play(store, row, col) {
        const status = store.putAt(row, col, this.kind);
        if (status) {
            this.positions.push([row, col]);
        }
    }

    isWin() {
        // A implementer
    }

    who() {
        return this.kind;
    }
}

class Scene {
    constructor() {
        this.scene = [[null, null, null], [null, null, null], [null, null, null]];
        this.white = new Player('white');
        this.black = new Player('black');
        console.log('On commence par le joueur blanc !');
        this.isTurn = this.white;
    }

    isEmpty(row, col) {
        return this.scene[row][col] === null;
    }

    putAt(row, col, who) {
        let status = false;
        if (this.isEmpty(row, col)) {
            this.scene[row][col] = who;
            status = true;
        }
        this.changeTurn();
        console.log(this.scene);
        this.render();
        return status;
    }

    isFinish() {
        return this.cellUsed === 6;
    }

    changeTurn() {
        this.isTurn = this.isTurn.who() === 'white' ? this.black : this.white;
    }

    render() {
        let tab = document.getElementById('tab');
        if (tab) {
            document.body.removeChild(tab);
        }
        tab = document.createElement('table');
        tab.id = 'tab';
        document.body.appendChild(tab);
        for (let row = 0; row < this.scene.length; ++row) {
            let tr = document.createElement('tr');
            for (let col = 0; col < this.scene[row].length; ++col) {
                let td = document.createElement('td');
                if (this.scene[row][col] === null) {
                    td.innerHTML = '';
                } else {
                    td.innerHTML = this.scene[row][col] === 'white' ? 'O' : 'X'
                }
                tr.appendChild(td);

                // Action du joueur lors du click dans la cellule
                td.addEventListener('click', () => {
                    const player = this.isTurn;
                    player.play(this, row, col);
                });
            }
            tab.appendChild(tr);
        }
    }
}

const s = new Scene();
s.render();
