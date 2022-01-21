#include <iostream>

using namespace std;

void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

class Sort{
protected:
    int *arr;
    int arrSize;
public:
    Sort(){}
    Sort(int *arr, int arrSize){
        this->arr = arr;
        this->arrSize = arrSize;
    }
    virtual void getSort() = 0;
    virtual void printSorted() = 0;
};


class SelectionSort:public Sort{
public:
    SelectionSort():Sort(){};
    SelectionSort(int arr[], int arrSize):Sort(arr, arrSize){};

    void getSort(){
        int i, j, min_idx;

        // One by one move boundary of unsorted subarray
        for (i = 0; i < arrSize - 1; i++){
            // Find the minimum element in unsorted array
            min_idx = i;
            for (j = i+1; j < arrSize; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Swap the found minimum element with the first element
            Swap(&arr[min_idx], &arr[i]);
        }
    }
    void printSorted(){
        cout << "Using Selection Sort >>" << endl;
        for(int i = 0; i < 7; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
class BubbleSort:public Sort{
public:
    BubbleSort():Sort(){};
    BubbleSort(int arr[], int arrSize):Sort(arr, arrSize){};

    void getSort(){
        int i, j;
        for (i = 0; i < arrSize-1; i++)

        // Last i elements are already in place
        for (j = 0; j < arrSize-i-1; j++)
            if (arr[j] > arr[j+1])
            Swap(&arr[j], &arr[j+1]);
    }
    void printSorted(){
        cout << "Using Bubble Sort >>" << endl;
        for(int i = 0; i < 7; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
class InsertionSort:public Sort{
public:
    InsertionSort():Sort(){};
    InsertionSort(int arr[], int arrSize):Sort(arr, arrSize){};

    void getSort(){
        int i, key, j;
        for (i = 1; i < arrSize; i++){
            key = arr[i];
            j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    void printSorted(){
        cout << "Using Insertion Sort >>" << endl;
        for(int i = 0; i < 7; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class MergeSort{
    // Merge two subarrays L and M into arr
    void merge(int arr[], int p, int q, int r) {

        // Create L ← A[p..q] and M ← A[q+1..r]
        int n1 = q - p + 1;
        int n2 = r - q;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[p + i];
        for (int j = 0; j < n2; j++)
            M[j] = arr[q + 1 + j];

        // Maintain current index of sub-arrays and main array
        int i, j, k;
        i = 0;
        j = 0;
        k = p;

        // Until we reach either end of either L or M, pick larger among
        // elements L and M and place them in the correct position at A[p..r]
        while (i < n1 && j < n2) {
            if (L[i] <= M[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = M[j];
                j++;
            }
            k++;
        }

        // When we run out of elements in either L or M,
        // pick up the remaining elements and put in A[p..r]
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = M[j];
            j++;
            k++;
        }
    }
};


int main(){
    int arr[] = {1,5,3,2,4,7,6};

    InsertionSort is(arr,7);
    is.getSort();
    is.printSorted();

    SelectionSort ss(arr, 7);
    ss.getSort();
    ss.printSorted();

    BubbleSort bs(arr, 7);
    bs.getSort();
    bs.printSorted();

    return 0;
}
