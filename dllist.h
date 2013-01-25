#ifndef DLLIST_H_INCLUDED
#define DLLIST_H_INCLUDED

#include <assert.h>

template<class T>
class LinkedList {
public:

	class Node {
	private:
		friend class LinkedList<T>;	
		T data;
		Node* _next;
		Node* _prev;

		Node* ptr(){
			return _next->_prev;
		}

	public:
		Node():_prev(NULL), _next(NULL){		}
		T value(){return data;}
		Node next(){return *_next;}
		Node prev(){return *_prev;}
		bool isEnd(){return (_next == NULL);}
		bool isBack(){return (_next->_next == NULL);}
		bool isStart(){return (_prev == NULL);}
		virtual Node operator++(int){
			Node tmp = *this;
			*this = next();			
			return tmp;
		}
		virtual Node operator++(){
			*this = next();
			return *this;
		}
		virtual bool operator==(Node other){
			if(other.data == this->data
				&& other._next == this->_next
				&& other._prev == this->_prev){
				return true;
			}
			return false;
		}

	};

	Node* head;
	Node* tail;

	void _print(const Node* node){
		using namespace std;
		cout << node->data << endl;
		if(node->_next != NULL){
			_print(node->_next);
		}
	}

	void _empty(Node** node){
		if(*node == NULL){
			return;
		}
		_empty(&(*node)->_next);
		delete *node;
		*node = NULL;
	}

public:
	LinkedList(){
		head = tail = NULL;
	}

	void push_back(T val){
		if(head == NULL){
			tail = head = new Node;
			head->data = val;
			return;
		}
		Node* tmp = tail;
		tail->_next = new Node;
		tail = tail->_next;
		tail->data = val;
		tail->_prev = tmp;

	}

	void push_front(T val){
		if(head == NULL){
			tail = head = new Node;
			head->data = val;
			return;
		}
		assert(head->_prev == NULL);
		Node* tmp = head;
		head->_prev = new Node;
		head = head->_prev;
		head->data = val;
		head->_next = tmp;
	}

	T pop_back(){
		assert(tail->_next == NULL);
		T tmp = tail->data;
		tail = tail->_prev;
		delete tail->_next;
		tail->_next = NULL;
		return tmp;
	}

	T pop_front(){
		assert(head->_prev == NULL);
		T tmp = head->data;
		head = head->_next;
		delete head->_prev;
		head->_prev = NULL;
		return tmp;
	}

	T at(size_t i){
		Node* result = head;
		while(i-- > 0 && result->_next != NULL){
			result = result->_next;
		}
		return result->data;
	}

	T& operator[](size_t i){
		Node* result = head;
		while(i-- > 0 && result->_next != NULL){
			result = result->_next;
		}
		return *(&(result->data));	
	}

	Node begin(){
		return *head;
	}

	Node end(){
		return *tail;
	}

	void print(){
		_print(head);
	}

	void empty(){
		_empty(&head);
		tail = NULL;
	}

	bool isEmpty(){
		return (head == NULL && tail == NULL);
	}

	size_t size(){
		size_t ret = 0;
		Node* iter = head;
		while(iter != NULL){
			ret++;
			iter = iter->_next;
		}
		return ret;
	}

	Node insert(Node node, T val){

		Node* newNode = new Node();
		newNode->data = val;

		Node* after = node.ptr();
		Node* before = after->_prev;

		newNode->_next = after;
		if(before == NULL){
			head = newNode;
		} else {
			before->_next = newNode;
		}
		return *newNode;
		
	}

};

#endif