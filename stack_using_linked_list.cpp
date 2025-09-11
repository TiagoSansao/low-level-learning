#include <vector>
#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T value;
    Node<T>* previous;
};

template <typename T>
class Stack {
    private: 
        unsigned int capacity;
        unsigned int size;
        Node<T>* tail;

    public:
        Stack(unsigned int capacity) {
            this->capacity = capacity;
            this->size = 0;
            this->tail = new Node<T>();
            this->tail->previous = nullptr;
        }

        ~Stack() {
            Node<T>* pivot = this->tail;

            for (unsigned int i = 0; i < size; i += 1) {
                Node<T> *toDelete = this->tail;
                pivot = toDelete->previous;
                delete toDelete;
            }
        }   

        void push(T value) {
            if (size >= capacity) throw runtime_error("Stack is full.");
            
            Node<T> *newNode = new Node<T>();
            newNode->value = value;
            newNode->previous = this->tail;
            this->tail = newNode;

            this->size += 1;
        }

        T pop() {
            if (size == 0) return NULL;
            T value = this->tail->value;

            this->tail = this->tail->previous;

            size -= 1;
            return value;
        } 

        T peek() {
            if (size == 0) return NULL;
            return this->tail->value;
        }
};


int main() {
    try {
        cout << "Salve" << endl;
        Stack<char>* charStack = new Stack<char>(10);

        cout << charStack << endl;

        charStack->push('d');
        charStack->push('f');
        charStack->push('u');
        charStack->push('j');

        cout << (*charStack).peek() << endl;

        charStack->push('9');
        charStack->push('3');

        cout << (*charStack).peek() << endl;
        
        cout << (*charStack).pop() << endl;

        cout << (*charStack).peek() << endl;
        
        cout << (*charStack).pop() << endl;

        charStack->push('t');

        cout << (*charStack).pop() << endl;
    } catch (const runtime_error& e) {
        std:cerr << "Runtime error: " << e.what() << std::endl;
    }
    

    return 0;
}