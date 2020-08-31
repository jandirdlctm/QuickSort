#include <iostream>
#include <vector>

void PrintItems(const std::vector<int>& A)
{
	for (int x : A) // for integer x in vector A
		std::cout << x << " ";
	std::cout << std::endl;
}

void QuickSortR(std::vector<int>& A, int low, int high)
{
	// Base Case:
	if (high - low <= 0)
	{
		return;
	}

	// One pass of the quick sort:
	int pivot = low;
	int lmgt = low + 1;
	for (int i = low + 1; i <= high; i++)
	{
		if (A[i] < A[pivot])
		{
			std::swap(A[i], A[lmgt]);
			lmgt++;
		}
	}
	std::swap(A[low], A[lmgt - 1]);

	// Recurse:
	QuickSortR(A, low, lmgt - 1);
	QuickSortR(A, lmgt + 1, high);
}

void QuickSort(std::vector<int>& A)
{
	QuickSortR(A, 0, A.size() - 1);
}

int main()
{
	std::vector<int> items{ 8, 3, 4, 6, 0, 9, 4, 7 };
	PrintItems(items);
	QuickSort(items);
	PrintItems(items);
	return 0;
}