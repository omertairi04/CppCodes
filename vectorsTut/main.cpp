#include <iostream>
#include <vector>

using namespace std;

int main() {

	// vector<string> foods = {"grapes", "carrots", "lemons"};
	// vector<string> foods;
	// foods = {"grapes", "carrots", "lemons"};
	// foods.push_back("New food"); // add to the foods
	// foods.pop_back(); // remove item from the end
	// foods.shrink_to_fit(); // shrinks the memory allocation (capacity == size)
	// cout << foods.capacity() << endl; // get the allocated size
	// cout << foods.size() << endl; // get the number of items

	/*
	 Loop
		for (auto food : foods) {
			cout << food << endl;
		}
	*/

	vector<int> v1 = {1 , 2 , 3 , 4};
	// v1.insert(v1.begin(), 5); // insert at beginning of vector
	// v1.insert(v1.begin() + 2, 7); // add to the second position
	// v1.erase(v1.begin()); // remove an element
	return 0;
}
