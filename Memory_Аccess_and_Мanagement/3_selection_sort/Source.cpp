#include <limits>
#include <iostream>

void swap_func(int& from, int& to)
{
	int temp = from;
	from = to;
	to = temp;
}

void selectionSort(int a[], int start, int end)
{
	int min_value = 0;
	int index = 0;

	for (size_t i = start; i < end; i++)
	{
		min_value = a[i];
		index = i;
		for (size_t j = i; j < end; j++)
		{
			if (min_value > a[j])
			{
				min_value = a[j];
				index = j;
			}
		}

		swap_func(a[i], a[index]);
	}
}

int main()
{
	// условието е само да се напише фунцията, не е споменано от къде удва входа, така че не ще е хардкоднат.
	int arr[10] = { 5,3,2,1,8,4,2,9,1,2 };
	selectionSort(arr, 2 ,9);

	return 0;
}