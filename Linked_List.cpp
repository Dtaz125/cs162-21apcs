#include"Linked_List.h"

namespace CourseRegistration {
	template<typename T>
	Linked_List<T>::Linked_List(const T& data) {
		head = tail = new Node<T>{ data, nullptr };
		size++;
	}

	template<typename T>
	Linked_List<T>::Linked_List(const Linked_List& list) {
		Node<T>* curr_list = list.head;
		while (curr_list) {
			insert(curr_list->data);
			curr_list = curr_list->next;
		}
	}

	template<typename T>
	bool Linked_List<T>::insert(const T& new_data) {
		if (contains(new_data)) return false;
		if (!head) {
			head = tail = new Node<T>(new_data, nullptr);
		}
		else {
			tail->next = new Node{ new_data, nullptr };
			tail = tail->next;
		}
		size++;
	}

	template<typename T>
	bool Linked_List<T>::contains(const T& data) {
		if (!head) return false;
		Node<T>* curr = head;
		while (curr && curr->data != data)
			curr = curr->next;
		return curr != nullptr;
	}

	template<typename T>
	bool Linked_List<T>::remove(const T& data) {
		if (!head) return false;
		Node<T>* curr = head, * prev = nullptr;
		while (curr && curr->data != data) {
			prev = curr;
			curr = curr->next;
		}
		if (!curr) return false;
		if (!prev) {
			head = head->next;
		}
		else {
			prev->next = curr->next;
		}
		size--;
		delete curr;
		return true;
	}
}