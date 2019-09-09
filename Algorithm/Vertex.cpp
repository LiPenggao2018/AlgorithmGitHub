#include"Vertex.h"
//#include"EdgeWeight.h"
template<class T>
Vertex<T>::Vertex()
{

}

template<class T>
Vertex<T>::~Vertex()
{

}

template<class T>
T Vertex<T>::getData()
{
	return data;
}

template<class T>
void Vertex<T>::setData(T data)
{
	this->data = data;
}

template<class T>
vector<Vertex<T>*>Vertex<T>::getNeighbors()
{
	return neighbors;
}

template<class T>
void Vertex<T>::setNeighbors(vector<Vertex*>neighbors)
{
	this->neighbors = neighbors;
}

template<class T>
int Vertex<T>::getIndegree()
{
	return indegree;
}

template<class T>
void Vertex<T>::setIndegree(int indegree)
{
	this->indegree = indegree;
}

template<class T>
int Vertex<T>::getDist()
{
	return dist;
}

template<class T>
void Vertex<T>::setDist(int dist)
{
	this->dist = dist;
}

template<class T>
Vertex<T>* Vertex<T>::getPath()
{
	return path;
}

template<class T>
void Vertex<T>::setPath(Vertex<T>* path)
{
	this->path = path;
}

template<class T>
bool Vertex<T>::getKnow()
{
	return know;
}

template<class T>
void Vertex<T>::setKnow(bool know)
{
	this->know = know;
}



template<class T>
vector<EdgeWeight<T>*>Vertex<T>::getNeighborEdgeWeights()
{
	return neighborEdgeWeights;
}

template<class T>
void Vertex<T>::setNeighborEdgeWeights(vector<EdgeWeight<T>*>neighborEdgeWeights)
{
	this->neighborEdgeWeights = neighborEdgeWeights;
}

template<class T>
int Vertex<T>::getEC()
{
	return EC;
}

template<class T>
void Vertex<T>::setEC(int EC)
{
	this->EC = EC;
}

template<class T>
int Vertex<T>::getLC()
{
	return LC;
}

template<class T>
void Vertex<T>::setLC(int LC)
{
	this->LC = LC;
}