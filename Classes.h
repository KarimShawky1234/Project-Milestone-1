#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <ctime>


using namespace std;

class RPA
{
protected:
    int Size;
    int* arr = new int[Size];
    RPA(int n)
    {
        srand(time(NULL));
        Size = n;
        for(int i = 1; i < Size; i++)
        {
            arr[i] = i;
        }
        
        for(int i = 2; i < Size - 1; i++)
        {
            int m = (rand() % Size) + 1;
            swap(arr[i], arr[m]);
        }
    }
public:
    void GetArr()
    {
        for(int i = 1; i <= Size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int RandInt(int i, int j)
    {
        srand(time(NULL));
        int rand_int;

        rand_int = (rand() % j) + i;

        return rand_int;
    }


};

class SelectionSort : public RPA
{
    int expCount;
    public:
    SelectionSort(int n) : RPA(n)
    {
        expCount = 0;
    }

    void sort()
    {
        expCount = 0;

        for(int i = 0; i <= Size - 1; i++)
        {
            for(int j = i + 1; j <= Size; j++)
            {
                if(arr[i] > arr[j])
                {
                    swap(arr[j], arr[i]);
                }
                expCount++;
            }
        }
    }

    int GetExpCount()
    {
        return expCount;
    }

};

class InsertionSort : public RPA
{
    int expCount;
public:
    InsertionSort(int n) : RPA(n)
    {
        expCount = 0;
    }

    void sort()
    {
        int key, j;

        for(int i = 1; i <= Size; i++)
        {
            key = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j -= 1;
                expCount++;
            }
            arr[j + 1] = key;
        }
    }

    int GetExpCount()
    {
        return expCount;
    }
};

class MergeSort : public RPA
{
    int expCount;
public:
    MergeSort(int n) : RPA(n)
    {
        expCount = 0;
    }
private:
    void mergeSort(int arr[], int l, int r)
    {
        if(l < r)
        {
            int m = (l + r)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }

    void merge(int arr[], int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int *tempL = new int[n1];
        int *tempR = new int[n2];

        for(int i = 0; i < n1; i++)
        {
            tempL[i] = arr[l + i];
        } 

        for(int j = 0; j < n2; j++)
        {
            tempR[j] = arr[m + 1 + j];
        }

        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2)
        {
            if(tempL[i] <= tempR[j])
            {
                arr[k] = tempL[i];
                i++;
            }
            else
            {
                arr[k] = tempR[j];
                j++;
            }
            k++;
            expCount++;
        }
        while (i < n1)
        {
            arr[k] = tempL[i];
            i++;
            k++;
        }
        while(j < n2)
        {
            arr[k] = tempR[j];
            j++;
            k++;
        }
    }
public:
    void sort()
    {
        mergeSort(arr, 0, Size);
    }

    int GetExpCount()
    {
        return expCount;
    }
};

class QuickSort1 : public RPA
{
    int expCount;
public:
    QuickSort1(int n) : RPA(n)
    {
        expCount = 0;
    }
private:
    int partition(int arr[], int start, int end)
    {
        int temp = arr[end];
        int i = (start - 1);

        for(int j = start; j <= end - 1; j++)
        {
            if(arr[j] < temp)
            {
                i++;
                swap(arr[i], arr[j]);
                expCount++;
            }
        }
        swap(arr[i + 1], arr[end]);
        return i+1;
    }

    void quickSort(int arr[], int start, int end)
    {
        if(start < end)
        {
            int i = partition(arr, start, end);
            quickSort(arr, start, i - 1);
            quickSort(arr, i + 1, end);
        }
    }
public:
    void sort()
    {
        quickSort(arr, 0, Size);
    }

    int GetExpCount()
    {
        return expCount;
    }

};

class QuickSort2 : public RPA
{
    int expCount;
public:
    QuickSort2(int n) : RPA(n)
    {
        expCount = 0;
    }
private:
    int partition(int arr[], int start, int end)
    {
        srand(time(NULL));
        int pivot = start + rand() % (end - start + 1);
        int temp = arr[pivot];
        int i = (start - 1);

        swap(arr[pivot], arr[end]);

        for(int j = start; j <= end - 1; j++)
        {
            if(arr[j] < temp)
            {
                i++;
                swap(arr[i], arr[j]);
                expCount++;
            }
        }
        swap(arr[i + 1], arr[end]);
        return i+1;
    }

    void quickSort(int arr[], int start, int end)
    {
        if(start < end)
        {
            int i = partition(arr, start, end);
            quickSort(arr, start, i - 1);
            quickSort(arr, i + 1, end);
        }
    }
public:
    void sort()
    {
        quickSort(arr, 0, Size);
    }

    int GetExpCount()
    {
        return expCount;
    }

};

#endif
