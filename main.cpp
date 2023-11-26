#include <iostream>
#include "list_function.h"

using namespace std;

int main()
{
    List<int> myList;

    myList.append(1);
    myList.append(2);
    myList.append(385);
    myList.append(4);
    myList.append(1024);
    myList.append(47);

    Node<int>* nodeToInsertAfter = myList.tail;
    myList.insertAfter(nodeToInsertAfter, 99);
    myList.printList();

    Node<int>* nodeToDelete = myList.head->next;
    myList.deleteNode(nodeToDelete);
    myList.printList();

    Node<int>* node1 = myList.head->next;
    Node<int>* node2 = myList.tail;
    myList.swapNodes(node1, node2);
    myList.printList();

    myList.mergeSort();
    myList.printList();

//    List<std::string> myList;
//    myList.append("Spitsina");
//    myList.append("Chernushova");
//    myList.append("Tsvetkov");
//    myList.append("Kulikov");
//    myList.append("Gartsev");
//    myList.printList();
//    myList.mergeSort();
//    myList.printList();

    return 0;
}



