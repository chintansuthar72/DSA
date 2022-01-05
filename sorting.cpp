#include <iostream>
using namespace std;

class sorting
{
private:
    int *arr;
    int n;
    void swap(int *a, int *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    void heapify(int i,int &swaps)
    {
        int largest = i;   
        int l = 2 * i + 1; 
        int r = 2 * i + 2; 
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            swaps++;
            heapify(largest,swaps);
        }
    }
    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;
        int a[n1];
        int b[n2];

        for (int i = 0; i < n1; i++)
        {
            a[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++)
        {
            b[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
        {
            if (a[i] > b[j])
            {
                arr[k] = b[j];
                k++;
                j++;
            }
            if (a[i] < b[j])
            {
                arr[k] = a[i];
                k++;
                i++;
            }
        }
        while (i < n1)
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        while (j < n2)
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    int partition(int arr[], int l, int r)
    {
        int pivot = arr[r];
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[r], &arr[i + 1]);
        return i + 1;
    }

public:
    sorting(int *arr)
    {
        n = 10;
        this->arr = arr;
    }
    ~sorting()
    {
        delete[] arr;
    }
    void bubbleSort() // In-place
    {
        int swaps = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swaps++;
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
        cout << "Number of swaps : "  << swaps << endl;
    }
    void insertionSort()
    {
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    void mergeSort(int arr[], int l, int r) // Not In-place
    {
        if (l < r)
        {
            int m = (l + r) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }else{
            cout << "Number of swaps : "  << 0 << endl;
        }
    }
    void quickSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            int pi = partition(arr, l, r);
            quickSort(arr, l, pi - 1);
            quickSort(arr, pi + 1, r);
        }
    }
    void heapSort(int arr[], int n)
    {
        int swaps = 0;
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(i,swaps);
        for (int i = n - 1; i > 0; i--)
        {
            swap(&arr[0], &arr[i]);
            swaps++;
            heapify(0,swaps);
        }
        cout << "Number of swaps : "  << swaps << endl;
    }
    void selectionSort() // In-place
    {
        int swaps = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            swap(&arr[min_idx], &arr[i]);
            swaps++;
        }
        cout << "Number of swaps : "  << swaps << endl;
    }
    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sorting c(a);
    c.insertionSort();
    c.display();
    return 0;
}