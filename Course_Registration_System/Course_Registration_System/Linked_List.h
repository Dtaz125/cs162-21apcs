#pragma once
#include"Node.h"
#include"Iterator.h"
#define travel(it, var) for(auto it = var.begin(); it != var.end(); it++)
template<class T>
class Iterator;
template<class T>
class Linked_List {
private:
	Node<T>* head;
	Node<T>* tail;
	int list_size = 0;
public:
	Linked_List() {
		head = tail = nullptr;
		list_size = 0;
	}
	Linked_List(const T& data) {
		head = tail = new Node<T>{ data, nullptr };
		list_size = 1;
	}
	Linked_List(const Linked_List<T>& list) {
		Node<T>* curr_list = list.head;
		while (curr_list) {
			add(curr_list->data);
			curr_list = curr_list->next;
		}
	}
	~Linked_List() {
		while (head) {
			remove(head->data);
		}
		head = tail = nullptr;
	}
	Linked_List<T>& operator = (const Linked_List& list) {
		if (this == &list) return *this;
		Node<T>* tmp = nullptr;
		while (head) {
			tmp = head;
			head = head->next;
			delete head;
		}
		tail = nullptr;
		list_size = 0;
		if (list.head) {
			Node<T>* curr = list.head;
			while (curr) {
				add(curr->data);
				curr = curr->next;
			}
		}
		return *this;
	}
	bool add(const T& new_data) {
		//if (contains(new_data)) return false;
		if (!head) {
			head = tail = new Node<T>{ new_data, nullptr };
		}
		else {
			tail->next = new Node<T>{ new_data, nullptr };
			tail = tail->next;
		}
		list_size++;
		return true;
	}
	void add(const Linked_List<T>& new_list) {
		Node<T>* curr = new_list.head;
		while (curr) {
			add(curr->data);
			curr = curr->next;
		}
	}
	bool remove(const T& data) {
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
		list_size--;
		delete curr;
		return true;
	}
	void remove(const Linked_List<T>& list) {
		if (this == &list) {
			empty_list();
			return;
		}
		Node<T>* curr = list.head;
		while (curr) {
			remove(curr->data);
			curr = curr->next;
		}
	}

	Node<T>* operator [](int k) {
		if (k >= list_size) return nullptr;
		int i = 0;
		Node<T>* curr = head;
		while (i < k) {
			curr = curr->next;
			i++;
		}
		return curr;
	}

	Node<T>* contains(const T& data) {
		Node<T>* curr = head;
		while (curr && curr->data != data)
			curr = curr->next;
		return curr;
	}

	void empty_list() {
		if (head) {
			Node<T>* curr;
			while (head) {
				curr = head;
				head = head->next;
				delete curr;
			}
			tail = nullptr;
		}
		list_size = 0;
	}

	int size() { return list_size; }

	const Iterator<T> begin() { return Iterator<T>(head); }

	const Iterator<T> end() { return Iterator<T>(); }
};