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

    ~LinkedList()
    {
        deleteAll();
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

    bool add(T data, int pos)
    {
        // store in out of bounds position
        if (pos > size)
        {
            return false;
        }

        if (pos == 0)
        {
            addFirst(data);
        }
        else if (pos == size)
        {
            addLast(data);
        }
        else
        {
            Node<T> *current = head;
            for (int i = 1; i < pos; i++)
            {
                current = current->getNext();
            }
            Node<T> *newNode = new Node<T>(data, current->getNext());
            current->setNext(newNode);
            size++;
        }
        return true;
    }

    void deleteFirst()
    {
        if (head != nullptr)
        {
            Node<T> *current = head;
            head = head->getNext();
            delete current;
            size--;
        }
    }

    int deleteAll()
    {
        // Delete head while you have elements
        Node<T> *current = head;
        while (head != nullptr)
        {
            head = head->getNext();
            delete current;
            current = head;
        }
        int sizeTmp = size;
        size = 0;
        return sizeTmp;
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