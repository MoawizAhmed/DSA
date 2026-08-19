#include <iostream>
using namespace std;


/*
class Buffer {
private:
int* data;
int length;

public:
Buffer(int len) {
length = len;
data = new int[length];
for (int i = 0; i < length; i++) data[i] = 0;
               }
void setValue(int index, int value) {
data[index] = value;
}
void display() const {
for (int i = 0; i < length; i++)
cout <<data[i]<<" ";
cout<<endl;
}
~Buffer() {
delete[] data;
}
};
int main() {
Buffer b1(5);
b1.setValue(0, 10);
Buffer b2 = b1; // uses the compiler-generated copy constructor
b2.setValue(1, 20);
b1.display();
b2.display();
return 0; 
}     
*/   // both b1 and b2 are destroyed here



/*
The class has a shallow-copy bug because it does not define a copy constructor
or copy assignment operator. The compiler-generated copy constructor copies
the data pointer itself, so b1 and b2 point to the same dynamically allocated
array. Therefore, modifying b2 also modifies b1. When both objects are
destroyed, their destructors attempt to delete the same array, causing
double deletion and undefined behavior.

The corruption is visible before the program ends. After b2.setValue(1, 20),
both b1 and b2 display "10 20 0 0 0" because they share the same array.*/

class Buffer {
private:
    int* data;
    int length;

public:

    Buffer(int len) {
        length = len;
        data = new int[length];

        for (int i = 0; i < length; i++)
            data[i] = 0;

        cout << "Constructor called" << endl;
    }
    Buffer(const Buffer& other) {
        length = other.length;
        data = new int[length];

        for (int i = 0; i < length; i++)
            data[i] = other.data[i];

        cout << "Copy constructor called" << endl;
    }
    Buffer& operator=(const Buffer& other) {

        if (this == &other)
            return *this;

        delete[] data;

        length = other.length;
        data = new int[length];

        for (int i = 0; i < length; i++)
            data[i] = other.data[i];

        cout << "Copy assignment operator called" << endl;

        return *this;
    }

    void setValue(int index, int value) {
        data[index] = value;
    }

    void display() const {
        for (int i = 0; i < length; i++)
            cout << data[i] << " ";

        cout << endl;
    }

    ~Buffer() {
        delete[] data;
        cout << "Destructor called" << endl;
    }
};
int main() {

    Buffer b1(5);
    b1.setValue(0, 10);
    Buffer b2 = b1;
    b2.setValue(1, 20);
    cout << "b1: ";
    b1.display();
    cout << "b2: ";
    b2.display();
    Buffer b3(3);

    b3 = b1;
    cout << "b3: ";
    b3.display();

    return 0;
}