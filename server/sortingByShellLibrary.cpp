#include "SortingByShellLibrary.h"

QList <int> SortingByShellLibrary::sortByShell(QList <int> &array) {
    for (size_t step = array.size() / 2; step > 0; step /= 2) {
        for (size_t i = step; i < array.size(); i++) {
            int temp = array[i];
            size_t j;
            for (j = i; j >= step && array[j - step] > temp; j -= step) {
                array[j] = array[j - step];
            }
            array[j] = temp;
        }
    }
    return array;
}
