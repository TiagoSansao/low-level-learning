#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Stack {
    private: 
        unsigned int capacity;
        unsigned int size;
        T* stackptr;

    public:
        Stack(unsigned int capacity) {
            this->capacity = capacity;
            this->size = 0;
            this->stackptr = new T[capacity];
        }

        ~Stack() {
            delete []this->stackptr;
        }   

        void push(T value) {
            cout << "Size: " << size << endl;
            cout << "Capacity: " << capacity << endl;
            if (size >= capacity) throw runtime_error("Stack is full.");
            stackptr[this->size] = value;
            this->size += 1;
        }

        T pop() {
            if (size == 0) return NULL;
            T value = stackptr[size - 1];
            size -= 1;
            return value;
        }

        T peek() {
            if (size == 0) return NULL;
            return stackptr[size - 1];
        }
};


int main() {
    try {
        cout << "Salve" << endl;
        Stack<char>* charStack = new Stack<char>(3);

        cout << charStack << endl;

        charStack->push('d');
        charStack->push('f');
        charStack->push('u');
        charStack->push('j');

        cout << (*charStack).pop() << endl;

        charStack->push('9');
        charStack->push('3');

        cout << (*charStack).pop() << endl;
        cout << (*charStack).pop() << endl;
    } catch (const runtime_error& e) {
        std:cerr << "Runtime error: " << e.what() << std::endl;
    }
    

    return 0;
}


// {([])}
// {([)]}