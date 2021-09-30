#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> LL;
	for (int i = 1; i < 11; i++)
		LL.AddAtHead(i);
	LL.Print(); // (10,9,8,7,6,5,4,3,2,1)

	cout << LL.Get(2) << endl; // 8

	// LL.AddAtIndex(2,8);
	// LL.Print(); // (10,9,8,8,7,6,5,4,3,2,1)

	// LL.DeleteAtIndex(3);
	// LL.Print(); // (10,9,8,7,6,5,4,3,2,1)

	// LL.DeleteValue(9);
	// LL.Print(); // (10,8,7,6,5,4,3,2,1)

	// LL.MoveToHead(2);
	// LL.Print(); // (2,10,8,7,6,5,4,3,1)

	// LL.Rotate(2);
	// LL.Print(); // (3,1,2,10,8,7,6,5,4)

	// LL.AddAtHead(4);
	// LL.Print(); // (4,3,1,2,10,8,7,6,5,4)

	// LL.Reduce();
	// LL.Print(); // (4,3,1,2,10,8,7,6,5)

	// LL.AddAtIndex(7,10);
	// LL.Print(); // (4,3,1,2,10,8,7,10,6,5)

	// LL.K_Reverse(3);
	// LL.Print(); // (1,3,4,8,10,2,6,10,7,5)
	cout << LL.Size() << endl; // 10

	// LL.EvenOddSeparateSort();
	// LL.Print(); // (2,4,6,8,10,10,7,5,3,1)
	// cout<<LL.Size()<< endl; // 10

	LL.CleanUp();
	cout << LL.Size() << endl; // 0
}