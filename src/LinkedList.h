#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T>& rhs);
    ~LinkedList();

    LinkedList<T>& operator=(const LinkedList<T>& rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T>* node) const;
    int getIndex(Node<T>* node) const;

    Node<T>* getFirstNode() const;
    Node<T>* getLastNode() const;
    Node<T>* getNode(const T& data) const;
    Node<T>* getNodeAtIndex(int index) const;

    void append(const T& data);
    void prepend(const T& data);
    void insertAfterNode(const T& data, Node<T>* node);
    void insertAtIndex(const T& data, int index);
    void moveToIndex(int currentIndex, int newIndex);
    void mergeNodes(int sourceIndex, int destIndex);

    void removeNode(Node<T>* node);
    void removeNode(const T& data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.


private: // DO NOT CHANGE THIS PART.
    Node<T>* head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = new Node<T>(T());
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
    head = new Node<T>(T());
    size = 0;
    Node<T>* temp1 = head;
    Node<T>* temp2 = rhs.head->next;
    int i;
    for (i = 0; i < rhs.getSize(); i++) {
        temp1->next = new Node<T>(T());
        temp1->next->data = temp2->data;
        temp1->next->prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
        size++;
    }


}

template<class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* temp = this->head->next;


    while (getSize()) {
        head->next = temp->next;
        if (head->next != NULL) {
            head->next->prev = head;
        }
        delete temp;
        size--;
        temp = head->next;
    }

    delete head;

}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    this->removeAllNodes();
    Node<T>* temp = rhs.head->next;
    while (temp != NULL) {
        this->append(temp->data);
        temp = temp->next;
    }
    return *this;
}

template<class T>
int LinkedList<T>::getSize() const
{
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    if (this->getSize() == 0) {
        return true;
    }
    else {
        return false;
    }

}

template<class T>
bool LinkedList<T>::containsNode(Node<T>* node) const
{
    Node<T>* temp = head->next;
    while (temp != NULL) {
        if (temp == node) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class T>
Node<T>* LinkedList<T>::getFirstNode() const
{
    if (head->next == NULL) {
        return NULL;
    }
    else {
        return head->next;
    }
}

template<class T>
Node<T>* LinkedList<T>::getLastNode() const
{
    Node<T>* temp = head->next;
    if (head->next == NULL) {
        return NULL;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp;
    }
}

template<class T>
Node<T>* LinkedList<T>::getNode(const T& data) const
{
    Node<T>* temp = head->next;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template<class T>
Node<T>* LinkedList<T>::getNodeAtIndex(int index) const
{
    Node<T>* temp = head->next;
    int i = 0;
    if (index > size - 1) {
        return NULL;
    }
    else {
        while (temp != NULL) {
            if (index == i) {
                return temp;
            }
            temp = temp->next;
            i++;
        }
    }
}

template<class T>
void LinkedList<T>::append(const T& data)
{
    Node<T>* curr;
    curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    Node<T>* newnode = new Node<T>(T(data), curr, NULL);
    curr->next = newnode;
    size++;
}


template<class T>
void LinkedList<T>::prepend(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    newNode->prev = head;
    newNode->next = head->next;
    if (head->next != NULL) {
        head->next->prev = newNode;
    }
    head->next = newNode;
    size++;

}

template<class T>
void LinkedList<T>::insertAfterNode(const T& data, Node<T>* node)
{
    if (containsNode(node)) {
        Node<T>* newNode = new Node<T>(data);
        if (node->next == NULL) {
            node->next = newNode;
            newNode->prev = node;
        }
        else {
            node->next->prev = newNode;
            newNode->next = node->next;
            node->next = newNode;
            newNode->prev = node;
        }
        size++;

    }
}

template<class T>
void LinkedList<T>::insertAtIndex(const T& data, int index)
{
    if (index < size) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = this->getNodeAtIndex(index);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        size++;
    }
}

template<class T>
int LinkedList<T>::getIndex(Node<T>* node) const
{
    Node<T>* temp = head->next;
    int i = 0;
    while (temp != NULL) {
        if (this->containsNode(node)) {
            return -1;
        }
        if (temp == node) {
            return i;
        }
        temp = temp->next;
        i++;
    }
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    if (0 <= currentIndex && currentIndex < size)
    {
        if (newIndex > size - 1) {
            newIndex = size - 1;
        }

        Node<T>* temp1 = this->getNodeAtIndex(currentIndex);
        Node<T>* temp2 = this->getNodeAtIndex(newIndex);
        if (currentIndex < newIndex) {
            temp1->prev->next = temp1->next;
            temp1->next->prev = temp1->prev;
            temp1->next = temp2->next;
            temp2->next = temp1;
            temp1->prev = temp2;
        }
        else {
            temp1->prev->next = temp1->next;
            if (temp1->next != NULL) {
                temp1->next->prev = temp1->prev;
            }
            temp2->prev->next = temp1;
            temp1->prev = temp2->prev;
            temp2->prev = temp1;
            temp1->next = temp2;
        }
    }

}

template<class T>
void LinkedList<T>::mergeNodes(int sourceIndex, int destIndex)
{
    Node<T>* temp1 = this->getNodeAtIndex(sourceIndex);
    Node<T>* temp2 = this->getNodeAtIndex(destIndex);
    if (this->containsNode(temp1) && this->containsNode(temp2)) {
        temp2->data = temp2->data + temp1->data;
        removeNode(temp1);
    }

}

template<class T>
void LinkedList<T>::removeNode(Node<T>* node)
{
    if (this->containsNode(node)) {
        node->prev->next = node->next;
        if (node->next) {

            node->next->prev = node->prev;

        }
        delete node;
        size--;
    }


}

template<class T>
void LinkedList<T>::removeNode(const T& data)
{
    Node<T>* temp = this->getNode(data);
    if (containsNode(temp)) {
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;

        delete temp;
        size = size - 1;
        this->removeNode(data);

    }

}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    Node<T>* temp = this->getNodeAtIndex(index);
    if (this->containsNode(temp)) {
        temp->prev->next = temp->next;
        if (temp->next) {
            temp->next->prev = temp->prev;
        }
        delete temp;
        size--;

    }

}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    Node<T>* temp = head->next;
    Node<T>* temp2;
    while (temp != NULL) {
        temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
    size = 0;
}

template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T>* node = this->getFirstNode();

    while (node)
    {
        std::cout << *node << std::endl;
        node = node->next;
    }

}

#endif //LINKEDLIST_H