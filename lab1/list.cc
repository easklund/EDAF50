#include <iostream>
#include "list.h"

List::List() {
	first = nullptr;
}

List::~List() {
	if(first != nullptr){
		while(first!= nullptr){
			Node* temp = first;
			first = first->next;
			delete(temp);
		}
	}
}

bool List::exists(int d) const {
	if(first != nullptr){
		Node* n = first;
		while(n != nullptr){
			if (n->value == d){
				return true;
			}
			n = n->next;
		}
	}
	return false;
}

int List::size() const {
	if(first != nullptr){
		Node* n = first;
		int count = 0;
		while(n != nullptr){
			count ++;
			n = n->next;
		}
		return count;
	}
	return 0;
}

bool List::empty() const {
	if(first != nullptr){
		return false;
	}
	return true;
}

void List::insertFirst(int d) {
	if(first != nullptr){
		Node* n = new Node(d, first);
		first = n;
	} else{
		first = new Node(d, nullptr);
	}

}

void List::remove(int d, DeleteFlag df) {
	if(first != nullptr){
		Node* n = first->next;
		Node* pre = first;
		if(df == DeleteFlag::LESS){
			if(first->value < d){
				first = n;
				delete(pre);
				return;
			}
			while(n != nullptr){
				if(n->value < d){
					pre = n->next;
					delete(n);
					return;
				}
				n = n->next;
				pre = pre->next;
			}
		}else if(df == DeleteFlag::EQUAL){
			if(first->value == d){
				first = n;
				delete(pre);
				return;
			}
			while(n != nullptr){
				if(n->value == d){
					pre = n->next;
					delete(n);
					return;
				}
				n = n->next;
				pre = pre->next;
			}
		}else {
			if(first->value > d){
				first = n;
				delete(pre);
				return;
			}
			while(n != nullptr){
				if(n->value > d){
					pre->next = n->next;
					delete(n);
					return;
				}
				n = n->next;
				pre = pre->next;
			}
		}
	}
}

void List::print() const {
	if(first != nullptr){
		Node* n = first;
		std::cout << "[";
		while(n != nullptr){
			std::cout << n->value;
			std::cout << ", ";
			n = n->next;
		}
		std::cout << "]"<< std:: endl;
	}else{
		std::cout << "[]" << std::endl;
	}
}
