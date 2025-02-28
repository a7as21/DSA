#pragma once

#include <iostream>
#include <vector>

void displayTree(int arr[], int n, int index, int depth)  {
    if (index >= n) {
        return;
	}

    // Print right child first (for better tree structure visualization)
    displayTree(arr, n, 2 * index + 2, depth + 1);

    // Print current node with indentation
    for (int i = 0; i < depth; ++i) {
        std::cout << "       "; // Add spaces for indentation
    }
    std::cout << arr[index] << std::endl;

    // Print left child
    displayTree(arr, n, 2 * index + 1, depth + 1);
}

void displayTree(std::vector<int> arr, int index, int depth) {
    // Base case: if index is out of bounds
    if (index >= arr.size()) {
        return;
    }

    // Print right child first (for better tree structure visualization)
    displayTree(arr, 2 * index + 2, depth + 1);

    // Print current node with indentation
    for (int i = 0; i < depth; ++i) {
        std::cout << "       "; // Add spaces for indentation
    }
    std::cout << arr[index] << std::endl;

    // Print left child
    displayTree(arr, 2 * index + 1, depth + 1);
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
	}
    std::cout << "\n";
}