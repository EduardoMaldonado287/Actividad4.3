#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;
#include "LinkedList.h"
#include "Grafo.h"

// This function gets only the ip part from a string of ip:port
string getOnlyIpPart(string ipAndPort)
{
    int portPosition = ipAndPort.find_first_of(':');
    string ip = ipAndPort.substr(0, portPosition);
    return ip;
}

void insertToListaAdyacencia(string sourceIp, string &destinationIp, vector<LinkedList<string>> &matrizDeAdyacencia, Grafo grafo1)
{
    Vertice *verticePrueba;
    verticePrueba = grafo1.findAndGetVertice(sourceIp);
    int verticeIndex = verticePrueba->getId();

    matrizDeAdyacencia.at(verticeIndex).addLast(destinationIp);
}

int main(){

    Grafo grafo1;
    vector<Vertice> vectorVertices;
    vector<LinkedList<string>> matrizDeAdyacencias;

    // Creamos las variables que son datos de entrada del archivo de texto
    string month, hour, con, ipAndPort, readLine, currentIpAddressString;
    string sourceIpAndPort, destinationIpAndPort, sourceIp, destinationIp;
    int day, accesses;
    int index = -1, howManyVertices, howManyAristas;

    ifstream logFile("bitacora-4_3_original.txt");

    if (logFile.is_open())
    {
        logFile >> howManyVertices >> howManyAristas;
        getline(logFile, readLine);
        howManyAristas++;
        howManyVertices++;

        cout << "La cantidad de vertices es: " << howManyVertices << endl;
        cout << "La cantidad de Aristas es: " << howManyAristas << endl;

        for (int i = 1; i <= howManyVertices; i++)
        {
            logFile >> ipAndPort;
            getline(logFile, readLine);
            currentIpAddressString = getOnlyIpPart(ipAndPort);
            grafo1.addVertice(currentIpAddressString);

            Vertice *verticePrueba;
            verticePrueba = grafo1.findAndGetVertice(currentIpAddressString);
            vectorVertices.push_back(*verticePrueba);

            LinkedList<string> listaInicial = LinkedList<string>();
            matrizDeAdyacencias.push_back(listaInicial);
        }

        for (int j = 1; j <= howManyAristas; j++)
        {
            logFile >> month >> day >> hour >> sourceIpAndPort >> destinationIpAndPort >> con;
            getline(logFile, con);
            sourceIp = getOnlyIpPart(sourceIpAndPort);
            destinationIp = getOnlyIpPart(destinationIpAndPort);
            grafo1.addArista(sourceIp, destinationIp);

            Arista *aristaPrueba;
            aristaPrueba = grafo1.findAndGetArista(j);

            string sourceIp = aristaPrueba->getViInfo();
            string destinationIp = aristaPrueba->getVjInfo();

            insertToListaAdyacencia(sourceIp, destinationIp, matrizDeAdyacencias, grafo1);
        }
    }

    cout << "ANTES DEL FOR DE SET GRADO DE SALIDA" << endl;
    for (int k = 1; k < howManyVertices-1; k++)
    {
        vectorVertices.at(k).setGradoDeSalida(matrizDeAdyacencias.at(k).getLinkedListSize());
        if (k <= 20)
        {
            cout << "getLinkedSize" << matrizDeAdyacencias.at(k).getLinkedListSize() << "getSize()" << matrizDeAdyacencias.at(k).getSize() << endl;
        }
    }

    cout << "Antes del print" << endl;
    for (int i = 1; i <= 100; i++)
    {
        cout << "Grado de salida: " << vectorVertices.at(i).getGradoDeSalida() << "  Vertice Id: " << 
            vectorVertices.at(i).getId() << "  Direccion Ip: " << vectorVertices.at(i).getData() << endl;
    }

    // cout << "Antes de ordenar burbuja" << endl;
    // for (int i = 0; i <= 100; i++)
    // {
    //     cout << "Grado de salida: " << vectorVertices.at(i).getGradoDeSalida() << "Vertice Id: " << 
    //         vectorVertices.at(i).getId() << "Direccion Ip: " << vectorVertices.at(i).getData() << endl;
    // }

    cout << "......................................." << endl;
    for (int j = 1; j <= 10; j++)
    {
        matrizDeAdyacencias.at(j).printLinkedList();
    }
    //grafo1.printVertices();

    cout << "---------------" << endl;

    // grafo1.printAristas();

    return 0;
}