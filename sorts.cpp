#include <iostream>
using namespace std;

template <typename nums>
void show_arr(nums arr, int size) {
    for (int i = 0; i < size; i++) cout << arr[i] << '\t';
    cout << '\n';
}

template <typename nums>
void Bubble_Sort(nums arr, int size) {

    for  (int i = 0; i < (size-1); i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                arr[i] += arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
}

template <typename nums>
void Quick_Sort(nums a, int start, int end){
    if (start > end) return;
    auto pivot = a[(rand() % (end + 1)) + start];
    int i = start;
    int j = end;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            auto buffer = a[i];
            a[i] = a[j];
            a[j] = buffer;
            i++;
            j--;
        }
    }
    Quick_Sort(a, start, j);
    Quick_Sort(a, i, end);
}

template <typename nums>
void Insertion_Sort(nums arr, int size) {
    for (int i = 1; i < size; i++) {
        auto cursor = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > cursor) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cursor;
    }
}


int main()
{
    int integer_arr[] = {1, 9, 12, 6, 4, 2, 0, 31, 51, 3};

    float floating_arr[] = { 1.9, 1.2, 6.4, 2, 3.1, 5.5, 3 };
    
    show_arr(integer_arr, 10); // массив и размер
    Insertion_Sort(integer_arr, 10); // массив и размер
    //Quick_Sort(integer_arr, 0, 9); // массив, индекс начального элемента, индекс последнего элемента
    //Bubble_Sort(integer_arr, 10); // массив и размер
    show_arr(integer_arr, 10);
    
    show_arr(floating_arr, 7);
    Insertion_Sort(floating_arr, 7);
    //Quick_Sort(floating_arr, 0, 6);
    //Bubble_Sort(floating_arr, 7);
    show_arr(floating_arr, 7);
}