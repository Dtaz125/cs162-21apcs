#pragma once
#include"Node.h"
template<class T>
class Iterator {
private:
	Node<T>* curr;
public:
	Iterator() : curr(nullptr) {}

	Iterator(Node<T>*& node) : curr(node) {}

	Iterator(const Iterator<T>& iter) : curr(iter.curr) {}

	Iterator<T>& operator ++ () {
		curr = curr->next;
		return *this;
	}

	Iterator<T> operator ++ (int) {
		Iterator<T> startVersion(curr);
		curr = curr->next;
		return startVersion;
	}

	const T& operator * () { if (curr) return curr->data; }

	bool operator == (const Iterator<T>& obj) {
		if (this == &obj) return true;
		if (!curr || !obj.curr) return false;
		return curr->data == obj.curr->data;
	}

	bool operator != (const Iterator<T>& obj) {
		if (this == &obj) return false;
		return curr != obj.curr;
	}

	~Iterator() {
		curr = nullptr;
	}
};