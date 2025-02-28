#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

void heapify(std::vector<int>& arr, int n, int i)	{
	
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if(l < n && arr[l] > arr[largest])
		largest = l;
	
	if(r < n && arr[r] > arr[largest])
		largest = r;

	if(largest != i) {
		std::swap(arr[i], largest);
		heapify(arr, n, largest);
	}

}

void heapsort(std::vector<int>& arr) {

	int n = arr.size();

	for(int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}
	
	for(int i = n - 1; i > 0; i--)	{
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

}

void deleteRoot(std::vector<int> arr, int& n) {
    int last = arr[n - 1];

    arr[0] = last;
    n = n - 1;

    heapify(arr, n, 0);
}