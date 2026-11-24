
#include <iostream>
using namespace std;

struct Item {
    int value;
    int priority;
    int order;
};

class PriorityQueue {

private:

    Item* arr;
    int capacity;
    int size;
    int counter;

    // Parent Index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Left Child Index
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Right Child Index
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Check which item has higher priority
    bool higherPriority(Item a, Item b) {

        if (a.priority != b.priority)
            return a.priority > b.priority;

        return a.order < b.order;
    }

    // Swap two items
    void swapItem(Item& a, Item& b) {

        Item temp = a;
        a = b;
        b = temp;
    }

    // Heapify Up
    void heapifyUp(int i) {

        while (i > 0 &&
               higherPriority(arr[i], arr[parent(i)])) {

            swapItem(arr[i], arr[parent(i)]);

            i = parent(i);
        }
    }

    // Heapify Down
    void heapifyDown(int i) {

        while (true) {

            int largest = i;

            int l = leftChild(i);
            int r = rightChild(i);

            if (l < size &&
                higherPriority(arr[l], arr[largest])) {

                largest = l;
            }

            if (r < size &&
                higherPriority(arr[r], arr[largest])) {

                largest = r;
            }

            if (largest == i)
                break;

            swapItem(arr[i], arr[largest]);

            i = largest;
        }
    }

public:

    // Constructor
    PriorityQueue(int cap) {

        capacity = cap;
        size = 0;
        counter = 0;

        arr = new Item[capacity];
    }

    // Destructor
    ~PriorityQueue() {
        delete[] arr;
    }

    // Check Empty
    bool isEmpty() {
        return size == 0;
    }

    // Check Full
    bool isFull() {
        return size == capacity;
    }

    // INSERT
    void insert(int value, int priority) {

        if (isFull()) {
            cout << "Priority Queue is full!" << endl;
            return;
        }

        Item newItem;

        newItem.value = value;
        newItem.priority = priority;
        newItem.order = counter++;

        arr[size] = newItem;

        size++;

        heapifyUp(size - 1);
    }

    // PEEK
    Item peek() {

        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return {-1, -1, -1};
        }

        return arr[0];
    }

    // REMOVE
    Item remove() {

        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return {-1, -1, -1};
        }

        Item top = arr[0];

        arr[0] = arr[size - 1];

        size--;

        if (size > 0)
            heapifyDown(0);

        return top;
    }

    // DISPLAY
    void display() {

        if (isEmpty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {

            cout << "(" << arr[i].value
                 << ", " << arr[i].priority << ") ";
        }

        cout << endl;
    }
};

int main() {

    PriorityQueue pq(10);

    pq.insert(10, 2);
    pq.insert(20, 5);
    pq.insert(30, 1);
    pq.insert(40, 5);
    pq.insert(50, 3);

    cout << "Priority Queue: ";
    pq.display();

    Item top = pq.peek();

    cout << "Highest Priority: "
         << top.value << endl;

    Item deleted = pq.remove();

    cout << "Removed Element: "
         << deleted.value << endl;

    cout << "After Removal: ";
    pq.display();

    return 0;
}
