#pragma once
#ifndef ITERATOR.H
#define ITERATOR.H

#include"Node.h"
using CourseRegistration::Node;
namespace CourseRegistration {
	template<typename T>
	class Iterator {
	private:
		Node<T>* curr;
	public:
		Iterator(): curr(nullptr){}
		Iterator(Node<T>*& node): curr(node){}
		Iterator(const Iterator<T>& iter): curr(iter.curr){}
		Iterator<T>& operator ++ (); //Prefix 
		Iterator<T> operator ++ (int); //Postfix
		bool operator == (const Iterator<T>& obj);
		bool operator != (const Iterator<T>& obj);
		bool operator = (const T& obj);
		T& remove();
		~Iterator();
	};
}

#endif // !ITERATOR.H
