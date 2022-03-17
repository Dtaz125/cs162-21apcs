#ifndef LINKED_LIST
#define LINKED_LIST
#include"Node.h"
#include"Iterator.h"
using CourseRegistration::Node;
using CourseRegistration::Iterator;
namespace CourseRegistration {
	template<typename T>
	class Linked_List {
	private:
		Node<T>* head = nullptr;
		Node<T>* tail = nullptr;
		int size = 0;
	public:
		Linked_List() {} //Deliberately empty
		Linked_List(const T& data);
		Linked_List(const Linked_List<T>& list); //Copy constructor
		~Linked_List(); //Destructor
		Linked_List<T>& operator = (const Linked_List& list);
		bool insert(const T& new_data);
		bool remove(const T& data);
		bool contains(const T& data);
		int getSize() { return size; }
		Iterator<T> begin() { return Iterator<T>(head); }
		Iterator<T> end() { return Iterator<T>(); }
	};
}
#endif // !LINKED_LIST
