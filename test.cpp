// C++ program to demonstrate the 
// use of rand() to get value 
// in a range of 0 to N-1 
#include <cstdlib> 
#include <iostream> 
using namespace std; 

int main() 
{ 
	int N = 300; 
	// This program will create some sequence of random 
	// numbers on every program run within range 0 to N-1 
	for (int i = 0; i < 5; i++) 
		cout << rand() % N << " "; 

	return 0; 
} 

// This code is contributed by Susobhan Akhuli
