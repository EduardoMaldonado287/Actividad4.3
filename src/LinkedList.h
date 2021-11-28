#include "Node.h"

template <class T>

class LinkedList
{
public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    void addFirst(T data)
    {
        Node<T> *aux = new Node<T>(data, head);
        head = aux;
        size++;
    }

    void addLast(T data)
    {
        if (size == 0)
        {
            addFirst(data);
        }
        else
        {
            Node<T> *current = head;

            while (current->getNext() != nullptr)
            {
                current = current->getNext();
            }

            Node<T> *newLast = new Node<T>(data);
            current->setNext(newLast);
        }
        size++;
    }

    int getSize()
    {
        Node<T> *curr = head;
        int contador = 0;
        while (curr != nullptr)
        {
            contador++;
            curr = curr->getNext();
        }
        return contador;
    }

    int getLinkedListSize()
    {
        return this->size;
    }

    void printLinkedList()
    {
        Node<T> *curr = head;
        cout << "El contenido de la LinkedList" << endl;
        while (curr != nullptr)
        {
            cout << curr->getData() << endl;
            curr = curr->getNext();
        }
    }

private:
    int size;
    Node<T> *head;
};