#include <exception>
#include <iostream>
#include <stdexcept>

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int data) {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }
};

class Deque {
public:
    Node* front = nullptr;
    Node* rear = nullptr;

    void push_back(int data) {
        Node* temp = new Node(data);
        if(isEmpty()) {
            front = temp;
            rear = front;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }


    void push_front(int data) {
        Node* temp = new Node(data);
        if(isEmpty()) {
            front = temp;
            rear = front;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }


    int pop_front() {
        int data;
        try {
            if(isEmpty()) {
                throw std::runtime_error("Deque is empty.");
            } else {
                Node* temp = front;
                data = temp->data;
                if(front == rear) {
                    front = nullptr;
                    rear = nullptr;
                } else {
                    front = temp->next;
                    front->prev = nullptr;
                }
                delete temp;
                return data;
            }

        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl; 
            return -1;
        }   
    }

    int pop_back() {
        int data;
        try {
            if(isEmpty()) {
                throw std::runtime_error("Deque is empty.");
            } else {
                Node* temp = rear;
                data = temp->data;
                if(front == rear) {
                    front = nullptr;
                    rear = nullptr;
                } else {
                    rear = temp->prev;
                    rear->next = nullptr;
                }
                delete temp;
                return data;
            }

        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl; 
            return -1;
        }   
    }

    int start() {
        try {
            if(isEmpty()) {
                throw std::runtime_error("Deque is empty.");
            } else {
                return front->data;
            }
        } catch(const std::exception& e) {
            std::cout << e.what() << std::endl; 
            return -1;
        }
    }

    int end() {
        try {
            if(isEmpty()) {
                throw std::runtime_error("Deque is empty.");
            } else {
                return rear->data;
            }
        } catch(const std::exception& e) {
            std::cout << e.what() << std::endl; 
            return -1;
        }
    }

    bool isEmpty() {
        if(front == nullptr && rear == nullptr) {
            return true;
        }
        return false;
    }

    void printDeque() {
        try {
            if(isEmpty()) {
                throw std::runtime_error("Deque is empty.");
            } else {
                Node* temp = front;
                while(temp) {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
            }
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl; 
        }   
    }

};

int main() {
    Deque dq;

    std::cout << "Is deque empty? " << (dq.isEmpty() ? "Yes" : "No") << std::endl;

    std::cout << "\nPushing elements at back: 10, 20" << std::endl;
    dq.push_back(10);
    dq.push_back(20);
    dq.printDeque();
    std::cout << std::endl;

    std::cout << "\nPushing elements at front: 5, 2" << std::endl;
    dq.push_front(5);
    dq.push_front(2);
    dq.printDeque();
    std::cout << std::endl;

    std::cout << "\nCurrent front element: " << dq.start() << std::endl;
    std::cout << "Current rear element: " << dq.end() << std::endl;

    std::cout << "\nPop from front: " << dq.pop_front() << std::endl;
    dq.printDeque();
    std::cout << std::endl;

    std::cout << "\nPop from back: " << dq.pop_back() << std::endl;
    dq.printDeque();
    std::cout << std::endl;

    std::cout << "\nFinal front element: " << dq.start() << std::endl;
    std::cout << "Final rear element: " << dq.end() << std::endl;

    std::cout << "\nClearing remaining..." << std::endl;
    while(!dq.isEmpty()) {
        std::cout << "Popped: " << dq.pop_front() << std::endl;
    }

    dq.printDeque();
    std::cout << "\nIs deque empty now? " << (dq.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}

