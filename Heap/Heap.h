#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap {
public:
	/*helpers*/
	bool full();
	bool empty();
	int size();
	int parent (const int&);
	int left (const int&);
	int right (const int&);
	bool compare (const T&, const T&);
	/**/

	Heap (bool = true);
	void insert (const T&);
	void remove (const int&);
	T top();
	void pop();
	void heapify (const int&);
	~Heap();

private:
	T *heap;
	bool isMinHeap;
	int tail, capacity;
};

#endif
