// Act 4.3 - Actividad Integral de Grafos (Evidencia Competencia)
// Equpo 2: Eduardo Maldonado Guzman A00832361 
// Sebastian Portes A00830155 & Ignacio Hernandez A00829933

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

// Funcion creada para ordenar el vector de los vertices en base al grado de salida - O(n^2) complejidad
void ordenaBurbuja(vector<Vertice> &vectorVertices)
{
    bool continuar = true;
    Vertice aux = vectorVertices.at(0);

    for (int pasada = 0; pasada < vectorVertices.size() - 1 && continuar; pasada++)
    {
        continuar = false;
        for (int j = 0; j < vectorVertices.size() - 1 - pasada; j++)
        {

            if (vectorVertices[j + 1].getGradoDeSalida() > vectorVertices[j].getGradoDeSalida())
            {
                aux = vectorVertices[j];
                vectorVertices[j] = vectorVertices[j + 1];
                vectorVertices[j + 1] = aux;
                continuar = true;
            }
        }
    }
}

// This function gets only the ip part from a string of ip:port
string getOnlyIpPart(string ipAndPort)
{
    int portPosition = ipAndPort.find_first_of(':');
    string ip = ipAndPort.substr(0, portPosition);
    return ip;
}

// Se crean las listas de adyacencia en esta función
void insertToListaAdyacencia(string sourceIp, string &destinationIp, vector<LinkedList<string>> &matrizDeAdyacencia, Grafo grafo1)
{
    Vertice *verticePrueba;
    verticePrueba = grafo1.findAndGetVertice(sourceIp);
    // Se quita uno por el index inicial
    int verticeIndex = verticePrueba->getId();
    matrizDeAdyacencia.at(verticeIndex).addLast(destinationIp);
}

int main(){

    Grafo grafo1;
    // Creación del vector que contiene los vertices
    vector<Vertice> vectorVertices;
    // Creación de la matriz de adyacencia, es un vector que almacena listas
    vector<LinkedList<string>> matrizDeAdyacencias;

    // Creamos las variables que necesarias
    string month, hour, con, ipAndPort, readLine, currentIpAddressString;
    string sourceIpAndPort, destinationIpAndPort, sourceIp, destinationIp;
    int day, howManyVertices, howManyAristas;

    ifstream logFile("bitacora-4_3.txt");

    if (logFile.is_open())
    {
        logFile >> howManyVertices >> howManyAristas;
        getline(logFile, readLine);
        howManyAristas++;
        howManyVertices++;

        // Iteramos la cantiddad de vertices señalados por la primera línea del archivo txt
        for (int i = 1; i <= howManyVertices; i++)
        {
            logFile >> ipAndPort;
            getline(logFile, readLine);
            currentIpAddressString = getOnlyIpPart(ipAndPort);
            grafo1.addVertice(currentIpAddressString);

            // Se obtiene el vertice que justo se acaba de meter al grafo
            Vertice *verticePrueba;
            verticePrueba = grafo1.findAndGetVertice(currentIpAddressString);
            vectorVertices.push_back(*verticePrueba);

            // Añadimos listas vacías a la matriz de adyacencia
            LinkedList<string> listaInicial = LinkedList<string>();
            matrizDeAdyacencias.push_back(listaInicial);
        }

        // Iteramos la cantiddad de Aristas señalados por la primera línea del archivo txt
        for (int j = 1; j <= howManyAristas; j++)
        {
            logFile >> month >> day >> hour >> sourceIpAndPort >> destinationIpAndPort >> con;
            getline(logFile, con);
            sourceIp = getOnlyIpPart(sourceIpAndPort);
            destinationIp = getOnlyIpPart(destinationIpAndPort);
            grafo1.addArista(sourceIp, destinationIp);
            
            // Empezamos a llamar a la función para crear las listas de adyacencia
            insertToListaAdyacencia(sourceIp, destinationIp, matrizDeAdyacencias, grafo1);
        }
    }

    // Agregar el grado de salida a cada vertice
    for (int k = 1; k < howManyVertices; k++)
    {
        vectorVertices.at(k).setGradoDeSalida(matrizDeAdyacencias.at(k).getSize());
    }

    // Ordenar el vector para encontrar los nodos con mayor grado de salida
    ordenaBurbuja(vectorVertices);

    // Imprimimos los 10 vertices con mayor grado de salida
    cout << "Estos son los 10 vertices(direcciones ip de origen) que mayor grado de salida tuvieron " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Grado de salida: " << vectorVertices.at(i).getGradoDeSalida() << " Vertice Id: " << 
            vectorVertices.at(i).getId() << " Direccion Ip: " << vectorVertices.at(i).getData() << endl;
    }
    return 0;
}