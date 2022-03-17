#pragma once

namespace CourseRegistration {
	template<typename T>
	struct Node {
		T data;
		Node<T>* next;
	};
}