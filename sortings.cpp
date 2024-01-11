
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void selectionSort(vector<int>& arr) //O(n^2) / in-place
{
    for (int i = 0; i < arr.size(); i++)
    {
        int minElement = i;
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[minElement] > arr[j])
            {
                minElement = j;
            }
        }
        swap(arr[i], arr[minElement]);
    }
}


void bubbleSort(vector<int>& arr)//O(n^2) / in-place
{
    for (int i = 0; i < arr.size(); i++)
    {
        bool isChanged = false;
        for (int j = 1; j < arr.size() - i; j++)
        {
            if (arr[j-1] > arr[j])
            {
                swap(arr[j-1], arr[j]);
                bool isChanged = true;
            }
        }
        if (isChanged)
        {
            return;
        }
    }
}


void insertionSort(vector<int>& arr) //O(n^2) / in-place
{
    for (int i = 1; i < arr.size(); i++)
    {
        int currentPositionOfMovingNum = i;
        while (currentPositionOfMovingNum > 0 && arr[currentPositionOfMovingNum - 1] > arr[currentPositionOfMovingNum])
        {
            swap(arr[currentPositionOfMovingNum - 1], arr[currentPositionOfMovingNum]);
            currentPositionOfMovingNum--;
        }
    }
}


void countingSort(vector<int>& arr)
{
    int minNumber = arr[0];
    int maxNumber = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (maxNumber < arr[i])
        {
            maxNumber = arr[i];
        }
        if (minNumber > arr[i])
        {
            minNumber = arr[i];
        }
    }
    vector<int> numbersCount(maxNumber - minNumber + 1);
    for (int i = 0; i < arr.size(); i++)
    {
        numbersCount[arr[i] - minNumber]++;
    }
    arr.clear();
    for (int i = 0; i < numbersCount.size(); i++)
    {
        while (numbersCount[i] != 0)
        {
            arr.push_back(i + minNumber);
            numbersCount[i]--;
        }
    }
}


vector<int> merge(vector<int>right, vector<int> left)
{
    vector<int> result;
    int rIndex = 0;
    int lIndex = 0;
    while (rIndex != right.size() && lIndex != left.size())
    {
        if (left[lIndex] <= right[rIndex])
        {
            result.push_back(left[lIndex]);
            lIndex++;
        }
        else
        {
            result.push_back(right[rIndex]);
            rIndex++;
        }
    }
    while (rIndex != right.size())
    {
        result.push_back(right[rIndex]);
        rIndex++;
    }
    while (lIndex != left.size())
    {
        result.push_back(left[lIndex]);
        lIndex++;
    }
    return result;
}
void mergeSort(vector<int>& arr)
{
    if (arr.size() == 1)
    {
        return;
    }
    int arrayCenter = arr.size() / 2;
    vector<int> rHalf;
    vector<int> lHalf;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i >= arrayCenter)
        {
            lHalf.push_back(arr[i]);
            continue;
        }
        rHalf.push_back(arr[i]);
    }
    mergeSort(lHalf);
    mergeSort(rHalf);

    arr = merge(lHalf, rHalf);
    return;
}


void quickSortContext(vector<int>& arr, int startIndex, int finishIndex)
{
    if (finishIndex - startIndex <= 1)
    {
        return;
    }
    int pivot = (startIndex + finishIndex) / 2;
    swap(arr[startIndex], arr[pivot]);
    int loverHalfIndex = startIndex;
    int higherHalfIndex = startIndex;
    for (int i = startIndex+1; i < finishIndex; i++)
    {
        if (pivot <= arr[i])
        {
            higherHalfIndex++;
        }
        else
        {
            swap(arr[loverHalfIndex + 1], arr[i]);
            higherHalfIndex++;
            loverHalfIndex++;
        }
    }
    swap(arr[startIndex], arr[loverHalfIndex]);
    quickSortContext(arr, startIndex, loverHalfIndex);
    quickSortContext(arr, loverHalfIndex+1, finishIndex);
    return;
}
void quickSort(vector<int>& arr)
{
    quickSortContext(arr, 0, arr.size());
}

void radixConquer(vector<int>& arr, vector<vector<int>>& buckets)
{
    arr.clear();
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr.push_back(buckets[i][j]);
        }
        buckets[i].clear();
    }
}
void radixSort(vector<int>& arr)
{
    vector<vector<int>> buckets(10);
    bool moreDigitsInNumsAvalible = true;
    int currDigitCount = 0;
    while (moreDigitsInNumsAvalible)
    {
        moreDigitsInNumsAvalible = false;
        for (int i = 0; i < arr.size(); i++)
        {
            int index = arr[i];
            if (currDigitCount)
            {
                index = arr[i] / (10 * currDigitCount);
            }
            if (index != 0)
            {
                moreDigitsInNumsAvalible = true;
            }
            buckets[index % 10].push_back(arr[i]);
        }
        radixConquer(arr, buckets);
        currDigitCount++;
    }
}
int main()
{
    int lengthOfArray = 1000;
    int maxElemInArray = 1000;
    vector<int> unsorted;

    for (int i = 0; i < lengthOfArray; i++)
    {
        unsorted.push_back(rand() % maxElemInArray);
    }
    
    vector<int> sorted = unsorted;
    sort(sorted.begin(), sorted.end());
    
    //selectionSort(unsorted);
    //bubbleSort(unsorted);
    //insertionSort(unsorted);
    //countingSort(unsorted);
    //mergeSort(unsorted);
    //quickSort(unsorted);
    //radixSort(unsorted);

    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << unsorted[i] << " ";
    }
    cout << (unsorted == sorted);
}

