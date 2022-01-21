#include <iostream>

using namespace std;

void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

class Search{
protected:
    int *arr;
    int arrSize;
    int num;
public:
    Search(){}
    Search(int *arr, int arrSize, int num){
        this->arr = arr;
        this->arrSize = arrSize;
        this->num = num;
    }

    virtual int getSearch() = 0;
};

class SequentialSearch:public Search{
public:
    SequentialSearch():Search(){};
    SequentialSearch(int *arr, int arrSize, int num):Search(arr, arrSize, num){};

    int getSearch(){
        int i = 0, found = 0;
        while ((!found) && (i < arrSize)) {
        if ( num == arr[i])
            found = 1;
        else
            i++;
        }
        if ( found)
            return i;
        else
            return -1;
    }
};

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
        for(int i = 0; i < arrSize; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class BinarySearch:public Search{


public:
    BinarySearch():Search(){};
    BinarySearch(int *arr, int arrSize, int num):Search(arr, arrSize, num){};


    int getSearch(){
        SelectionSort ss(arr, arrSize);
        ss.getSort();
        ss.printSorted();
        int found = 0;
        int high = arrSize ;
        int low = 0;
        int mid;
        while ((!found) && (low <= high )) {
            mid = (high + low) / 2;
            if (arr[mid] > num)
                high = mid - 1; // go right
            else if (arr[mid] < num)
                low = mid + 1; // go left
            else
                found = 1;
            }
            if (found)
                return mid;
            else
                return -1;
        }
};

int main(){
    int arr[3] = {3,1,2};
    SequentialSearch s(arr, 3, 3);
    BinarySearch bs(arr, 3, 3);
    cout << "Using Sequential Search: " << s.getSearch() << endl;
    cout << "Using Binary Search: " << bs.getSearch() << endl;
    return 0;
}
