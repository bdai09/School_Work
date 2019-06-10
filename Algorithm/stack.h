//Student number : 132954173
//Seneca email : BDAI9@myseneca.ca
//Name : Bo Dai
//Lab 5 : June7, 2019

#include <iostream>


template <typename T>

class Stack {

	T data_[20];
	int top_; //trace location
public:

	Stack() {
		top_ =0;
	}
	void push(T data);
	void pop();
	T top() const;
	bool isEmpty() const;
	bool isFull() const;
};



template <typename T>

void Stack<T>::push( T data) {
	if (top_ != 20) {
		data_[top_++] = data;
	}
}

template <typename T>
void Stack<T>::pop() {
	if (top_ > 0) {
		top_--;
	}
}

template <typename T>
T Stack<T>::top() const {
	if (top_ != 0) {
		return data_[top_ - 1];
	}
             return '\0';
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return top_ == 0;
}

template <typename T>
bool Stack<T>::isFull() const {
	return top_ == 20;
}



