//Student number : 132954173
//Seneca email : BDAI9@myseneca.ca
//Name : Bo Dai
//Lab 4 : May31, 2019

#include <iostream>



template <typename T>

class DList {

	struct Node {

		T data_;

		Node* next_;

		Node* prev_;

		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {

			data_ = data;

			next_ = next;

			prev_ = prev;

		}

	};

	Node* front_;

	Node* back_;

public:

	DList() {

		front_ = nullptr;

		back_ = nullptr;

	}

	void push_front(const T& data);

	void push_back(const T& data);

	void pop_front();

	void pop_back();

	void print() const;

	void reversePrint() const;

	~DList();

};





template <typename T>

void DList<T>::push_front(const T& data) {
	Node* new_node = new Node(data, front_,nullptr);
	if (front_ == nullptr)
		back_ = new_node;
	else
		front_->prev_ = new_node;
	front_ = new_node;
}

template <typename T>

void DList<T>::push_back(const T& data) {
	Node* new_node = new Node(data, nullptr, nullptr);
	
	if (back_ == nullptr) {
		front_ = new_node;
	}
	else {
		new_node->prev_ = back_;
		back_->next_ = new_node;
	}
	
	back_ = new_node;

}

template <typename T>

void DList<T>::pop_front() {
	if (front_ != nullptr) { //if not empty
		Node* ptr;
		if (front_ == back_) { //there is only one node in the list
			ptr = front_;
			front_ = nullptr;
			back_ = nullptr;
			delete ptr;
		}
		else  {
			ptr = front_->next_;
			ptr->prev_ = nullptr;
			delete front_; // release the allocated memory
			front_ = ptr;
		}
	}

}

template <typename T>

void DList<T>::pop_back() {
	if (front_ != nullptr) { //if not empty
		if (front_ == back_) {//there is only one node in the list
			front_ = NULL;
			back_ = NULL;
		}
		else {
			Node* ptr=back_->prev_;
			ptr->next_ = nullptr;
			delete back_; //release the allocated memory
			back_ = ptr;
		}
	}

}

template <typename T>

void DList<T>::print() const {

	Node* curr = front_;

	while (curr != nullptr) {

		std::cout << curr->data_ << " ";

		curr = curr->next_;

	}

	std::cout << std::endl;

}

template <typename T>

void DList<T>::reversePrint() const {

	Node* curr = back_;

	while (curr != nullptr) {

		std::cout << curr->data_ << " ";

		curr = curr->prev_;

	}

	std::cout << std::endl;

}

template <typename T>

DList<T>::~DList() {

	Node* curr = front_;

	while (curr) {

		Node* rm = curr;

		curr = curr->next_;

		delete rm;

	}

}

template <typename T>

class Sentinel {

	struct Node {

		T data_;

		Node* next_;

		Node* prev_;

		Node(const T& data = T{}, Node* next = nullptr, Node* prev = nullptr) {

			data_ = data;

			next_ = next;

			prev_ = prev;

		}

	};

	Node* front_;

	Node* back_;

public:

	Sentinel() {

		front_ = new Node();

		back_ = new Node();

		front_->next_ = back_;

		back_->prev_ = front_;

	}

	void push_front(const T& data);

	void push_back(const T& data);

	void pop_front();

	void pop_back();

	void print() const;

	void reversePrint() const;

	~Sentinel();

};





template <typename T>

void Sentinel<T>::push_front(const T& data) {

	 Node* originFrontNext = front_->next_;
	 Node* new_node = new Node(data, originFrontNext, front_);
	 originFrontNext->prev_ = new_node;
	 front_->next_ = new_node;

}

template <typename T>

void Sentinel<T>::push_back(const T& data) {

	Node* originBackPrev = back_->prev_;
	Node* new_node = new Node(data, back_, originBackPrev);
	originBackPrev->next_ = new_node;
	back_->prev_ = new_node;

}

template <typename T>

void Sentinel<T>::pop_front() {

	if (front_->next_ != back_){ //if there are nodes between sentinel
		
		Node* originFrontNext = front_->next_;
		front_->next_ = originFrontNext->next_;
		originFrontNext->next_->prev_ = front_;
		delete originFrontNext;
	}
}

template <typename T>

void Sentinel<T>::pop_back() {
	if (front_->next_ != back_) { //if there are nodes between sentinel

		Node* originBackPrev = back_->prev_;
		back_->prev_ = originBackPrev->prev_;
		originBackPrev->prev_->next_ =back_;
		delete originBackPrev;
	}

}

template <typename T>

void Sentinel<T>::print() const {

	Node* curr = front_->next_;

	while (curr != back_) {

		std::cout << curr->data_ << " ";

		curr = curr->next_;

	}

	std::cout << std::endl;

}

template <typename T>

void Sentinel<T>::reversePrint() const {

	Node* curr = back_->prev_;

	while (curr != front_) {

		std::cout << curr->data_ << " ";

		curr = curr->prev_;

	}

	std::cout << std::endl;

}

template <typename T>

Sentinel<T>::~Sentinel() {

	Node* curr = front_;

	while (curr) {

		Node* rm = curr;

		curr = curr->next_;

		delete rm;

	}

}
