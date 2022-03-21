#ifndef LINKED_LIST
#define LINKED_LIST
#include"Node.h"
#include"Iterator.h"
template<class T>
class Linked_List {
private:
	Node<T>* head;
	Node<T>* tail;
	int size;
public:
	Linked_List() {
		head = tail = nullptr;
		size = 0;
	} 
	Linked_List(const T& data) {
		head = tail = new Node<T>{ data, nullptr };
		size = 1;
	}
	Linked_List(const Linked_List<T>& list) {
		Node<T>* curr_list = list.head;
		while (curr_list) {
			insert(curr_list->data);
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
		size = 0;
		if (list.head) {
			Node<T>* curr = list.head;
			while (curr) {
				insert(curr->data);
				curr = curr->next;
			}
		}
		return *this;
	}
	bool insert(const T& new_data) {
		if (contains(new_data)) return false;
		if (!head) {
			head = tail = new Node<T>{ new_data, nullptr };
		}
		else {
			tail->next = new Node<T>{ new_data, nullptr };
			tail = tail->next;
		}
		size++;
		return true;
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
		size--;
		delete curr;
		return true;
	}
	Node<T>* contains(const T& data) {
		Node<T>* curr = head;
		while (curr && curr->data != data)
			curr = curr->next;
		return curr;
	}
	int getSize() { return size; }
	Iterator<T> begin() { return Iterator<T>(head); }
	Iterator<T> end() { return Iterator<T>(); }
};
#endif // !LINKED_LIST
