//
// Created by omer on 1.6.24.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename T>
void print(T collection, int size) {
	for (int i=0;i<size;i++) {
		cout << collection[i] << endl;
	}
}

template<typename T>
void print(T collection) {
	print(collection, collection.size());
}

// int main() {
// 	cout << "What did you eat?: ";
// 	string food;
// 	cin >> food;
//
// 	// open file
// 	ofstream file("foods.txt");
// 	file << food; // instead of outputting to terminal, we "output" to the file
// 	file.close();
// }
