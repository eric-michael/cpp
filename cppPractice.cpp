// cpp practice.
//

#include <iostream>
#include <stdlib.h>
#include <vector>

#define vector std::vector

// Redundant but good for practice. The reason I am using a vector and not an array.
int getArrayLength(vector<int> a)
{
	return a.size();
}

// Counter solution
void printArray(vector<int> a)
{
	for (size_t i = 0;i < a.size();i++)
		std::cout << a[i] << ' ';
}

// Swap elements of the vector.
vector<int> swap(int i, int j, vector<int> a)
{
	int temp = a[j];
	a[j] = a[i];
	a[i] = temp;

	return a;
}

// Create a new sorted array with the two arrays passed.
vector<int> merge(vector<int> a, vector<int> b) 
{

	// Create a new array to sort the two passed arrays.
	vector<int> c(a.size() + b.size());

	size_t j = 0, i = 0;

	// Make sure there are still elements to be sorted.
	while(i + j < c.size())
	{
		// If there are still elements in both
		if (i < a.size() && j < b.size())
		{
			if (a[i] <= b[j])
			{
				c[i + j] = a[i];
				i++;
			}
			else
			{
				c[i + j] = b[j];
				j++;
			}
		}

		// If there are still elements in the first array but not the second.
		if (i < a.size() && j == b.size())
		{
			while (i < a.size())
			{
				c[i + j] = a[i];
				i++;
			}
		}

		// If there are still elements in the second array but not the first.
		if (i == a.size() && j < b.size())
		{
			while (j < b.size())
			{
				c[i + j] = b[j];
				j++;
			}
		}
		
	}

	return c;
}

// 1. Take the first element of the vector.
// 2. Compare it to every element in the vector.
// 3. While comparing, keep track of the smallest value.
// 4. After comparing every element, swap the first element with the smallest.
// 5. Repeat
void selectionSort(vector<int> a)
{

	int min;

	std::cout << "Insertion Sort:\n";

	for (size_t i = 0; i < a.size(); i++)
	{

		min = a[i];

		for (size_t j = i; j < a.size(); j++)
		{
			if (a[j] < a[i])
				a = swap(i, j, a);
		}

		printArray(a);

		std::cout << '\n';

	}

	return;

}

// 1. Assume the first element is in the sorted section.
// 2. Go to the next unsorted element. Place it in the correct order in the sorted section.
// 3. Repeat until all elements are sorted.
void insertionSort(vector<int> a) 
{

	size_t i, j;

	vector<int> sorted(a.size());

	std::cout << "Insertion Sort: \n";

	sorted[0] = a[0];

	for (i = 1; i < a.size(); i++)
	{
		sorted[i] = a[i];

		for (j = 0; j < i; j++)
		{

			if (sorted[j] > sorted[i]) 
			{
				sorted = swap(j, i, sorted);
			}

		}

		printArray(sorted);

		std::cout << '\n';

	}

	return;
}

// 1. Compare the first element (x) to the next (x + 1). If x > x + 1, swap them and increment x.
// 2. Do this until no elements have been swapped.
void bubbleSort(vector<int> a)
{

	size_t i;

	bool sorted = false;

	std::cout << "Bubble Sort:" << '\n';

	while (!sorted) {

		sorted = true;

		for (i = 0; i < a.size() - 1; i++)
		{

			if (a[i] > a[i + 1])
			{
				a = swap(i, i + 1, a);
				sorted = false;
			}

		}

		printArray(a);

		std::cout << '\n';

	}

	return;
}

vector<int> mergeSort(vector<int> a)
{

	// Base case
	if (a.size() == 1)
	{
		return a;
	}

	size_t splitb = 0, splitc = 0;

	// find the midpoint to split the array.
	if (a.size() % 2 == 0)
	{
		splitb = a.size() / 2;
		splitc = a.size() / 2;
	}

	if (a.size() % 2 == 1)
	{
		splitb = (a.size() + 1) / 2;
		splitc = (a.size() - 1) / 2;
	}

	// Create two new arrays to split a.
	vector<int> b(a.size() - splitc), c(a.size() - splitb), d(a.size());

	// Populate the new arrays.
	for (size_t i = 0; i < b.size(); i++)
	{
		b[i] = a[i];
	}
	for (size_t j = 0; j < c.size(); j++)
	{
		c[j] = a[j + b.size()];
	}

	// Recursively call the function.
	d = merge(mergeSort(b), mergeSort(c));

	printArray(d);

	std::cout << '\n';

	return d;
}

// Bootstrap void-type function to prevent returning anything.
void mergeSortBootStrapper(vector<int> a)
{
	std::cout << "Merge Sort: " << '\n';

	a = mergeSort(a);

	return;
}

int main()
{
	int len;

	std::cout << "Enter a length for the array: ";

	std::cin >> len;

	std::cout << '\n';

	// It is not possible to find the length of an array with a pointer to the array.
	// Although it is redundant to find the length since we have the value above, I am doing it for practice.
	// int* unsortedArray{ new int[len] {} };

	// You cannot dynamically allocate the size of an array without creating it dynamically.
	// int unsortedArray[len]

	vector<int> unsortedArray(len);

	for (int i = 0; i < len; i++) {
		unsortedArray[i] = rand() % 20;
	}

	std::cout << "Array length:" << getArrayLength(unsortedArray) << "\n\n";

	std::cout << "Unsorted array:";

	printArray(unsortedArray);

	std::cout << "\n\n";

	selectionSort(unsortedArray);

	insertionSort(unsortedArray);

	bubbleSort(unsortedArray);

	mergeSortBootStrapper(unsortedArray);

}
