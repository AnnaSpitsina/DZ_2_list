#ifndef LIST_FUNCTION_H
#define LIST_FUNCTION_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class List {
public:
    Node<T>* head;
    Node<T>* tail;

    List() : head(nullptr), tail(nullptr) {}

    //вставка в конец
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    //вставка после нужного узла
    void insertAfter(Node<T>* prevNode, T value) {

        Node<T>* newNode = new Node<T>(value);
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        if (prevNode->next) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        //всплыло при отладке, что нужно учитывать
        if (prevNode == tail) {
                tail = newNode;
            }
    }

    //удаление узла
    void deleteNode(Node<T>* delNode) {
        if (delNode->prev) {
            delNode->prev->next = delNode->next;
        } else {
            head = delNode->next;
        }

        if (delNode->next) {
            delNode->next->prev = delNode->prev;
        } else {
            tail = delNode->prev;
        }

        delete delNode;
    }

    //перестановка
    void swapNodes(Node<T>* node1, Node<T>* node2) {
        //частный случай при отладке 2
        if (node1 == node2) {
            return; // Ничего не делаем, если узлы одинаковые
        }

        T temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }

    //вывод спискк
    void printList() {
    Node<T>* current = head;
            while (current) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
       }

    //сортировка
    void mergeSort() {
        if (!head || head == tail) {
            cout << "not element for sort";
            return;
        }

        head = mergeSort(head);
    }

private:
    //поиск середины списка
    Node<T>* getMiddle(Node<T>* start) {
        if (!start) {
            return nullptr;
        }

        Node<T>* left_h = start;
        Node<T>* right_h = start->next;

        while (right_h && right_h->next) {
            left_h = left_h->next;
            right_h = right_h->next->next;
        }

        return left_h;
    }

    //слияние
    Node<T>* merge(Node<T>* left, Node<T>* right) {
        Node<T>* mergedList = nullptr;
        Node<T>* tail = nullptr;

        while (left && right) {
            if (left->data < right->data) {
                if (!mergedList) {
                    mergedList = tail = left;
                } else {
                    tail->next = left;
                    left->prev = tail;
                    tail = left;
                }
                left = left->next;
            } else {
                if (!mergedList) {
                    mergedList = tail = right;
                } else {
                    tail->next = right;
                    right->prev = tail;
                    tail = right;
                }
                right = right->next;
            }
        }

        //если в одном из спиков остались элементы, а в другом уже нет
        while (left) {
            tail->next = left;
            left->prev = tail;
            tail = left;
            left = left->next;
        }

        while (right) {
            tail->next = right;
            right->prev = tail;
            tail = right;
            right = right->next;
        }

        return mergedList;
    }

    //рекурсивная сортировка слиянием
    Node<T>* mergeSort(Node<T>* start) {
        if (!start || !start->next) {
            return start;
        }

        Node<T>* middle = getMiddle(start);
        Node<T>* nextToMiddle = middle->next;

        middle->next = nullptr;
        nextToMiddle->prev = nullptr;

        Node<T>* left = mergeSort(start);
        Node<T>* right = mergeSort(nextToMiddle);

        return merge(left, right);
    }
};


#endif // LIST_FUNCTION_H
