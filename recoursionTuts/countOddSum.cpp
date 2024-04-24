#include <iostream>
using namespace std;

 void calculate_even_odd_Sum(int start, int end, int & evenSum, int & oddSum) {
   // Base case: If start becomes greater than end, stop the recursion
   if (start > end)
     return;

   // Recursive case: add the current number to the appropriate sum
   if (start % 2 == 0)
     evenSum += start;
   else
     oddSum += start;

   // Recursively call the function with the next number in the range
   calculate_even_odd_Sum(start + 1, end, evenSum, oddSum);
 }

 int main() {
   int start, end;
   std::cout << "Input the starting number: ";
   std::cin >> start;
   std::cout << "Input the ending number: ";
   std::cin >> end;

   int even_Sum = 0;
   int odd_Sum = 0;

   // Calculate the sum of even and odd numbers using recursion
   calculate_even_odd_Sum(start, end, even_Sum, odd_Sum);

   std::cout << "Sum of even numbers: " << even_Sum << std::endl;
   std::cout << "Sum of odd numbers: " << odd_Sum << std::endl;

   return 0;
 }