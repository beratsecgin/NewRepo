#include <iostream>
#include "LinkedList.h"
using namespace std
int main() {
    // You can test your implementations here
    LinkedList<int> list;
    list.append(1);
    list.append(5);
    list.append(9);
    list.append(11);
    Node<int> a(4);
    cout>>list.getIndex(&a);

    
    return 0;
} 
