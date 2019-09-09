#include"EdgeWeight.h"
#include"Vertex.h"


template<class U>
EdgeWeight<U>::EdgeWeight()
{

}

template<class U>
EdgeWeight<U>::EdgeWeight(Vertex<U>*s, Vertex<U> *p, int weight)
{
	this->s = s;
	this->p = p;
	this->weight = weight;
}

template<class U>
EdgeWeight<U>::~EdgeWeight()
{

}

template<class U>
Vertex<U> EdgeWeight<U>::getS()
{
	return s;
}

template<class U>
void EdgeWeight<U>::setS(Vertex<U> *s)
{
	this->s = s;
}

template<class U>
Vertex<U>EdgeWeight<U>::getP()
{
	return p;
}

template<class U>
void EdgeWeight<U>::setP(Vertex<U>* p)
{
	this->p = p;
}

template<class U>
int EdgeWeight<U>::getWeight()
{
	return weight;
}

template<class U>
void EdgeWeight<U>::setWeight(int weight)
{
	this->weight = weight;
}
