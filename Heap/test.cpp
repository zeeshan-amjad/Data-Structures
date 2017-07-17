#include "Heap.h"
#include <iostream>
using namespace std;

int main() {
	Heap <int> H;
	H.insert (13);
	cout << H.top();
	H.insert (14);
	cout << H.top();
	H.insert (12);
	cout << H.top();
	H.remove (0);
	cout << H.top();
	return 0;
}