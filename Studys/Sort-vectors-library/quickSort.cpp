#include <iostream>

using namespace std;


int partition(vector<int>& v, int low, int high) {
	int pivot = v[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (v[j] <= pivot) {
			i++;
			swap(v[i], v[j]);
		}
	}

	swap(v[i + 1], v[high]);
	return i + 1;
}

void quickSort(vector<int>& v, int low, int high) {
	if (low < high) {
		int p = partition(v, low, high);
		quickSort(v, low, p - 1);
		quickSort(v, p + 1, high);
	}
}

int main(void)
{
	int v = {4, 1, 5, 8, 2, 3, 7, 6};
	quickSort(v,0,8);
	return 0;
}