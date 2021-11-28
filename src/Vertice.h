class Vertice;
//#include "Lista.h"

class Vertice 
{
public:
    Vertice(string data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
        this->id = id;
    }
    
    Vertice(string data, Vertice *next, Vertice *prev)
    { 
        this->data = data;
        this->next = next;
        this->prev = prev;
        this->id = id;
    }

    string getData()
    {
        return data;
    }

    int getId()
    {
        return this->id;
    }

    void setListaAdyacencia(LinkedList<string> newListaAdyacencia)
    {
        this->listaDeAdyacencia = newListaAdyacencia;
    }

    void setId(int newId)
    {
        this->id = newId;
    }

    void setGradoDeSalida(int gDeSalida)
    {
        this->gradoDeSalida = gDeSalida;
    }

    int getGradoDeSalida()
    {
        return this->gradoDeSalida;
    }

    Vertice *getNext()
    {
        return next;
    }

    Vertice *getPrev()
    {
        return prev;
    }

    void setData(string data)
    {
        this->data = data;
    }

    void setNext(Vertice *next)
    {
        this->next = next;
    }

    void setPrev(Vertice *prev)
    {
        this->prev = prev;
    }

private:
    string data;
    int id;
    Vertice *next;
    Vertice *prev;
    LinkedList<string> listaDeAdyacencia;
    int gradoDeSalida = 0;
};

