#ifndef H_NODE
#define H_NODE

//Definition of the node
template <class T>
struct node
{
	T data;
	node<T> *link;
};

#endif
