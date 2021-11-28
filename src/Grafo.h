#include "Vertice.h"
#include "Arista.h"
using namespace std;

class Grafo
{
public:
    Grafo()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->verticeSize = 0;
        this->aristaSize = 0;
        headArista = nullptr;
    }

    // Adds the specified data in the last position of the list
    void addVertice(string data)
    {
        if (verticeSize==0){
            addFirstVertice(data);
        }
        else if (verticeSize >= 0)
        {
            Vertice *aux = new Vertice(data, nullptr, tail);
            aux->setId(verticeSize + 1);
            tail->setNext(aux);
            tail = aux;
            verticeSize ++;
        }
    }

    Vertice *findAndGetVertice(string ipAddress)
    {
        Vertice *searchVertice = head;
        int verticeCounter;

        while(searchVertice->getData() != ipAddress)
        {
            verticeCounter++;
            searchVertice = searchVertice->getNext();
        }
        return searchVertice;
    }

    // int getVerticePosition(string ipAddress)
    // {
    //     Vertice *searchVertice = head;
    //     int verticeCounter = 0;

    //     while(searchVertice->getData() != ipAddress)
    //     {
    //         verticeCounter++;
    //         searchVertice = searchVertice->getNext();
    //     }
    //     return verticeCounter;
    // }

    Arista *findAndGetAristaByString(string sourceIp, string destinationIp)
    {
        Arista *searchArista = headArista;

        while (searchArista->getViInfo() != sourceIp && searchArista->getVjInfo() != destinationIp)
        {
            searchArista = searchArista->getNext();
        }
        return searchArista;
    }


    Arista *findAndGetArista(int ip)
    {
        Arista *searchArista = headArista;

        while (searchArista->getAristaId() != ip)
        {
            searchArista = searchArista->getNext();
        }
        return searchArista;
    }

    void addArista(string sourceIpAddress, string destinationIpAddress)
    {
        if (aristaSize == 0)
        {
            addFirstArista(sourceIpAddress, destinationIpAddress);
        } 
        else 
        {
            Vertice *sourceVertice = findAndGetVertice(sourceIpAddress);
            Vertice *destinationVertice = findAndGetVertice(destinationIpAddress);


            Arista *currentArista = headArista;
            while (currentArista -> getNext() != nullptr){
                currentArista = currentArista->getNext();
            }
            
            Arista *newArista = new Arista(sourceVertice, destinationVertice);
            newArista->setAristaId(aristaSize+1);
            currentArista->setNext(newArista);
            aristaSize++;
        }
    }

    void printVertices()
    {
        Vertice *aux = head;
        while (aux != nullptr)
        {
            cout << "Vertice " << aux->getId() << ": " << aux->getData()  <<  endl;
            aux = aux -> getNext();
        }
    }

    void printAristas()
    {
        Arista *auxArista = headArista;

        while (auxArista != nullptr)
        {
            cout << "Arista " << auxArista->getAristaId() << ": (" << auxArista->getViInfo() << ", " << auxArista->getVjInfo() << ")" << endl;
            auxArista = auxArista->getNext();
        }
    }

    int getSize(){
        return verticeSize;
    }
    
    private:
        Vertice *head;
        Vertice *tail;
        Arista *headArista;
        int verticeSize;
        int aristaSize;

        // Adds the specified data in the first position of the list
        void addFirstVertice(string data)
        {
            Vertice *aux = new Vertice(data, head, nullptr);
            aux->setId(1);
            if (verticeSize==0)
            {
                head = aux;
                tail = aux;
            }
            else
            {
                head->setPrev(aux);
                head = aux;
            }
            verticeSize++;
        }

        void addFirstArista(string sourceIpAddress, string destinationIpAddress)
        {
            Vertice *sourceVertice = findAndGetVertice(sourceIpAddress);
            Vertice *destinationVertice = findAndGetVertice(destinationIpAddress);
            
            Arista *newArista= new Arista(sourceVertice, destinationVertice, headArista);
            headArista = newArista;
            headArista->setAristaId(1);
            aristaSize++;
        }
    };
