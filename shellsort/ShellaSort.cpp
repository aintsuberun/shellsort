/*
Назначение:
	Функция сортировки sort реализует алгоритм сортировки методом Шелла для упорядочивания элементов массива.
Авторы:
	Студенты Агеева Вероника и Карташов Артём.
Алгоритм:
	1. Инициализация шага, начиная с половины длины массива.
	2. Вложенный цикл для прохождения по элементам массива с текущим шагом.
	3. Сохранение текущего элемента.
	4. Внутренний цикл для перемещения элементов, больших текущего, на шаг вперед.
	5. Вставка сохраненного элемента на корректную позицию в отсортированной части массива.
*/

#include "ShellaSort.h"
#include "functions.h"

void ShellaSort::sort(vector<double>& arr) {
	for (size_t step = arr.size() / 2; step > 0; step /= 2) { // Используем size_t
		for (size_t i = step; i < arr.size(); i++) { // Используем size_t
			double temp = arr[i];
			size_t j; // Используем size_t
			for (j = i; j >= step && arr[j - step] > temp; j -= step) {
				arr[j] = arr[j - step];
			}
			arr[j] = temp;
		}
	}
}

/*void ShellaSort::sort(vector<double>& arr) {
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
*/
