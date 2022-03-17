#include"Iterator.h"

namespace CourseRegistration {
	template<typename T>
	Iterator<T>& Iterator<T>::operator ++() {
		curr = curr->next;
		return *this;
	}

	template<typename T>
	Iterator<T> Iterator<T>::operator ++(int) {
		Iterator startVersion(curr);
		curr = curr->next;
		return startVersion;
	}

	template<typename T>
	bool Iterator<T>::operator == (const Iterator<T>& obj) {
		if (this == &obj) return true;
		if (!curr || !obj.curr) return false;
		return curr->data == obj.curr->data;
	}

	template<typename T>
	bool Iterator<T>::operator !=(const Iterator<T>& obj) {
		if (this == &obj) return true;
		if (!curr || !obj.curr) return false;
		return !curr->data == obj.curr->data;
	}

	template<typename T>
	bool Iterator<T>::operator = (const T& obj) {
		if (!curr) return false;
		curr->data = obj;
		return true;
	}

	template<typename T>
	T& Iterator<T>::remove() {
		if (curr) {
			T results = curr->data;
			Node<T>* tmp = curr;
			curr = curr->next;
			delete tmp;
			return results;
		}
	}
}