#ifndef LINKED_LIST
#define LINKED_LIST
#include"Node.h"
using CourseRegistration::Node;
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
		bool insert(const T& new_data);
		bool remove(const T& data);
		bool contains(const T& data);
		int getSize() { return size; }
	};
}
#endif // !LINKED_LIST
