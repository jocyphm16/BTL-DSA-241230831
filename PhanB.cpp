#include <iostream>
#include <algorithm> 
#include <limits>    

using namespace std;

class MaxHeap {
private:
    int *arr;     
    int maxSize;  
    int heapSize; 

public:
    MaxHeap(int m) : maxSize(m) {
        heapSize = 0;
        arr = new int[maxSize];
    }
    ~MaxHeap() {
        delete[] arr;
    }
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    int push(int x) {
        if (heapSize == maxSize) return -1; 
        heapSize++;
        int i = heapSize - 1;
        arr[i] = x;
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
        return 0; 
    }

    int pop() {
        if (heapSize <= 0) return -1; 
        arr[0] = arr[heapSize - 1];
        heapSize--;
        pushDown(0, heapSize);
        return 0; 
    }

    int top() {
        if (heapSize <= 0) {
            return -1; 
        }
        return arr[0];
    }

    void pushDown(int i, int n) {
        int j = i;
        int kt = 0;
        int max = j;
        while ((j <= (n - 1) / 2) && kt == 0) {
            int l = leftChild(j);
            int r = rightChild(j);
            
            if (r < n && arr[l] <= arr[r]) {
                max = r;
            } else if (l < n) {
                max = l;
            }
            
            if (arr[j] < arr[max]) {
                swap(arr[j], arr[max]);
                j = max; 
            } else {
                kt = 1; 
            }
        }
        return;
    }

    void heapSort() {
        for (int i = heapSize / 2 - 1; i >= 0; i--) pushDown(i, heapSize);
        for (int i = heapSize - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            pushDown(0, i);
        }
    }

    void print() {
        for (int i = 0; i < heapSize; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }

    int getHeapSize() {
        return heapSize;
    }

};


class HeapSorter {
private:
    MaxHeap heap; 
    int n;

public:
    HeapSorter(int numElements) : n(numElements), heap(numElements) {}

    void readData() {
        cout << "Nhap " << n << " so nguyen: ";
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            heap.push(x);
        }
    }

    void printSortedResult() {
        cout << "Day so sau khi sap xep giam dan: ";
        for (int i = 0; i < n; i++) {
            cout << heap.top() << ' '; 
            heap.pop();               
        }
        cout << "\n\n";
    }
};

class MinCostCalculator {
private:
    MaxHeap minHeapEmulator; 
    int n;

public:
    MinCostCalculator(int numElements) : n(numElements), minHeapEmulator(numElements) {}

    void readData() {
        cout << "Nhap do dai " << n << " thanh: ";
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            minHeapEmulator.push(-x); 
        }
    }

    long long calculateMinCost() {
        long long totalCost = 0; 

        while (minHeapEmulator.getHeapSize() > 1) {
            int first_neg = minHeapEmulator.top();
            minHeapEmulator.pop();
            int second_neg = minHeapEmulator.top();
            minHeapEmulator.pop();

            int first = -first_neg;
            int second = -second_neg;

            int currentCost = first + second;
            totalCost += currentCost;

            minHeapEmulator.push(-currentCost);
        }
        return totalCost;
    }
};


int main() {
    cout << "--- Bai toan 1: Sap xep giam dan ---\n";
    int n1;
    cout << "Nhap so phan tu n: ";
    cin >> n1;
    if (n1 <= 0) n1 = 1;

    HeapSorter sorter(n1);
    sorter.readData();
    sorter.printSortedResult();

    cout << "--- Bai toan 2: Noi thanh kim loai (Chi phi thap nhat) ---\n";
    int n2;
    cout << "Nhap so thanh kim loai n: ";
    cin >> n2;
    if (n2 <= 0) n2 = 1;

    MinCostCalculator calculator(n2);
    calculator.readData();
    
    long long finalCost = calculator.calculateMinCost();
    cout << "Tong chi phi it nhat: " << finalCost << '\n';

    return 0;
}