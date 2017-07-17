#include "Heap.h"
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

template <class T>
extern void re_size (T *&array, int &capacity) {
	int c = capacity;
	capacity = c ? capacity * 2 : 1;
	T *temp = new T[capacity];
	for (int i = 0; i < c; ++i)
		temp[i] = array[i];
	delete []array;
	array = temp;
}

template <class T>
Heap<T>::Heap (bool isMinHeap) {
	this->tail = this->capacity = 0;
	this->heap = new int[0];
	this->isMinHeap = isMinHeap;
}

template <class T>
bool Heap<T>::full() {
	return this->tail == this->capacity;
}

template <class T>
bool Heap<T>::empty() {
	return this->tail == 0;
}

template <class T>
int Heap<T>::size() {
	return this->tail;
}

template <class T>
int Heap<T>::parent (const int &i) {
	return (i - 1) / 2;
}

template <class T>
int Heap<T>::left (const int &i) {
	return i * 2 + 1;
}

template <class T>
int Heap<T>::right (const int &i) {
	return i * 2 + 2;
}

template <class T>
bool Heap<T>::compare (const T &a, const T &b) {
	if (isMinHeap)
		return a < b;
	return a > b;
}

template <class T>
void Heap<T>::insert (const T &n) {
	if (this->full() or this->empty())
		re_size (this->heap, this->capacity);
	int i = this->tail;
	this->heap[i] = n;
	this->tail += 1;
	while (i and compare (this->heap[i], this->heap[parent (i)])) {
		swap (this->heap[i], this->heap[parent(i)]);
		i = parent (i);
	}
}

template <class T>
T Heap<T>::top() {
	return this->size() ? this->heap[0] : (this->isMinHeap ? INT_MAX : INT_MIN);
}

template <class T>
void Heap<T>::pop() {
	this->remove (0);
}

template <class T>
void Heap<T>::heapify (const int &i) {
	int l = this->left (i), 
		r = this->right (i),
		small = i;
	if (l < this->size() and compare (this->heap[l], this->heap[small]))
		small = l;
	if (r < this->size() and compare (this->heap[r], this->heap[small]))
		small = r;
	if (small != i) {
		swap (this->heap[i], this->heap[small]);
		heapify (small);
	}
}

template <class T>
void Heap<T>::remove (const int &index) {
	if (index == this->size() - 1) {
		this->tail--;
		return;
	}

	this->heap[index] = this->isMinHeap ? INT_MIN : INT_MAX;
	int i = index;
	while (i) {
		swap (heap[i], heap[parent (i)]);
		i = parent (i);
	}

	swap (this->heap[this->tail - 1], this->heap[0]);
	this->tail--;
	this->heapify (0);
}

template <class T>
Heap<T>::~Heap() {
	delete [](this->heap);
}

//to avoid link errors
void TemporaryFunction () {
    Heap <int> TempObj;
    TempObj.insert (0);
    TempObj.top();
    TempObj.remove (0);
    TempObj.pop();
}