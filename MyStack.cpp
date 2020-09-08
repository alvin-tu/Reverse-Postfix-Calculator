#include "MyStack.h"
#include <stdexcept>
#include <iostream>

MyStack::MyStack() {
    head = NULL;
}

MyStack::~MyStack() {
    clear();
}

void MyStack::push(double item) {
    Node *tmp = new Node;
    tmp->data = item;
    tmp->next = head;
    head = tmp;
}

double MyStack::pop() {
    if(is_empty()) {
        throw std::underflow_error("Empty!");
    }
    else {
        Node *tmp = head->next;
        double num = head->data;
        delete head;
        head = tmp;
        return num;
    }
}

void MyStack::clear() {
    Node *deleteNode = head;
    while(deleteNode != NULL) {
        Node *n = deleteNode->next;
        delete deleteNode;
        deleteNode = n;
    }
    head = NULL;
}

bool MyStack::is_empty() const {
    return head == NULL;
}

double MyStack::top() const {
    if(is_empty()) {
        throw std::underflow_error("Empty!");
    }
    return head->data;
}

void MyStack::print() const{
    for(Node *n = head; n != NULL; n = n->next) {
        std::cout << n->data << "->";
    }
    std::cout << std::endl;
}