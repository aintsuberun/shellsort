#include "ShellaSort.h"
#include "functions.h"

void ShellaSort::sort(vector<double>& arr) {
	for (int step = arr.size() / 2; step > 0; step /= 2) {
		for (int i = step; i < arr.size(); i++) {
			double temp = arr[i];
			int j;
			for (j = i; j >= step && arr[j - step] > temp; j -= step) {
				arr[j] = arr[j - step];
			}
			arr[j] = temp;
		}
	}
}
