
#include <iostream>
using namespace std;

class MaxHeap {

private:

    int* arr;
    int capacity;
    int size;

    // Get Parent Index
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Get Left Child Index
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Get Right Child Index
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Swap two values without STL
    void swapVal(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Heapify Up
    void heapifyUp(int i) {

        while (i > 0 &&
               arr[parent(i)] < arr[i]) {

            swapVal(arr[parent(i)], arr[i]);

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
                arr[l] > arr[largest]) {

                largest = l;
            }

            if (r < size &&
                arr[r] > arr[largest]) {

                largest = r;
            }

            if (largest == i)
                break;

            swapVal(arr[i], arr[largest]);

            i = largest;
        }
    }

public:

    // Constructor
    MaxHeap(int cap) {

        capacity = cap;
        size = 0;

        arr = new int[capacity];
    }

    // Destructor
    ~MaxHeap() {
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

    // Insert
    void insert(int value) {

        if (isFull()) {
            cout << "Heap is full!" << endl;
            return;
        }

        arr[size] = value;

        size++;

        heapifyUp(size - 1);
    }

    // Peek
    int peek() {

        if (isEmpty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        return arr[0];
    }

    // Delete Maximum
    int deleteMax() {

        if (isEmpty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int top = arr[0];

        arr[0] = arr[size - 1];

        size--;

        if (size > 0)
            heapifyDown(0);

        return top;
    }

    // Build Heap
    void buildHeap(int a[], int n) {

        if (n > capacity) {
            cout << "Array too large!" << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
        }

        size = n;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Display
    void display() {

        if (isEmpty()) {
            cout << "Heap is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    MaxHeap h(10);

    // Insertion
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(10);
    h.insert(40);

    cout << "Max Heap: ";
    h.display();

    // Peek
    cout << "Maximum: " << h.peek() << endl;

    // Deletion
    cout << "Deleted: " << h.deleteMax() << endl;

    cout << "After Deletion: ";
    h.display();

    // Build Heap
    int a[] = {4, 10, 3, 5, 1};

    MaxHeap h2(10);

    h2.buildHeap(a, 5);

    cout << "Build Heap: ";
    h2.display();

    return 0;
}
