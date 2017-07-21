#pragma once

void InsertionSort(int* a,size_t size)
{
	if (a == NULL)
		return ;

	int end = 0;
	int tmp = 0;
	
	for (size_t i = 1; i < size; i++)
	{
		tmp = a[i];
		end = i - 1;
		for (; end >= 0; end--)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, size_t size)
{

}
void QuickSort(int*a, int lenth, int start, int end)
{
	if (a == NULL)
		return;

	int index = end;

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (a[index] < a[end])
		{
			++small;
			if (small != index)
				swap(a[index], a[small]);
		}
	}

	++small;
	swap(a[small], a[end]);
	return;
}

void AdjustDown(int* a,size_t n,int i)
{
	int child = i * 2 + 1;
	int parent = i;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a,size_t n)
{
	assert(a);
	//建一个大堆
	for (int i = (n/2 -1); i >= 0; i--)
	{
		AdjustDown(a,n,i);
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(a[end], a[0]);
		//Printa(a, n);
		AdjustDown(a, end, 0);
		end--;
	}
}
void Print(int* a, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void QuickSort(int* a,size_t n)
{
	
	//_QuickSort(a,0,n-1);
}
void _QuickSort(int* a,int left,int right)
{
	if (left >= right)
		return ;
	int div = 0;//PartSort(a,left,right);

	_QuickSort(a, left, div - 1);
	_QuickSort(a, div + 1, right);

}
int PartSort(int* a,int left,int right)
{
	int rev = a[right];

	while (left < right)
	{
		while (left < right && a[left] < rev)
		{
			left++;
		}
		a[right] = a[left];

		while (left < right && a[right] > rev)
		{
			right--;
		}

		a[left] = a[right];
	}
}
