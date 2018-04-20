//============================================================================
// Name        : 0419.cpp
// Author      : SeongDeok Han
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Stack {

 public:
    Stack() {
        size = DEFAULT_SIZE;
        ptr = 0;
        array = new int[size];
    }
    ~Stack() {
        delete array;
    }
    bool isFull() {
        return ptr >= size;
    }
    bool empty() {
        return ptr == 0;
    }
    bool push(int v) {
        if (isFull()) {
            if (!resize()) {
                cerr << "No memory" << endl;
                return false;
            }
        }
        array[ptr++] = v;
        return true;
    }
    int top() {
        if (empty()) {
            cerr << "Empty()" << endl;
            return -1;
        }
        return array[ptr - 1];
    }
    bool pop() {
        if (empty()) {
            cerr << "Empty()" << endl;
            return false;
        }
        --ptr;
        return true;
    }
 private:
    static const int DEFAULT_SIZE = 10;
    int size;
    int ptr;
    int* array = NULL;
    bool resize() {
        if (size >= 160)
            return false;
        int* newArray = new int[size << 1];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete array;
        array = newArray;
        size = size << 1;
        cout << "resize to " << size << endl;
        return true;
    }
};

class Queue {
 public:
    Queue() {
        buffer_size = DEFAULT_SIZE;
        array = new int[buffer_size];
        base = size_num = 0;
    }
    ~Queue() {
        delete array;
    }
    bool push(int v) {
        if (size() == buffer_size) {
            if (!resize()) {
                cerr << "No memory" << endl;
                return false;
            }
        }
        array[(base + size_num) % buffer_size] = v;
        ++size_num;
        return true;
    }
    int front() {
        return array[base];
    }
    bool pop() {
        if (empty()) {
            cerr << "empty" << endl;
            return false;
        }
        int ret = array[base];
        base = increase(base);
        --size_num;
        return ret;
    }
    bool empty() {
        return size() == 0;
    }
    int size() {
        return size_num;
    }
 private:
    static const int DEFAULT_SIZE = 10;
    int* array;
    int buffer_size;
    int base;
    int size_num;
    bool resize() {
        if (buffer_size >= 160) {
            return false;
        }
        cout << "resizing" << endl;
        int* newArray = new int[buffer_size << 1];
        int idx = base;
        for (int i = 0; i < size_num; i++) {
            newArray[i] = array[idx];
            idx = increase(idx);
        }
        delete array;
        base = 0;
        array = newArray;
        buffer_size = buffer_size << 1;
        return true;
    }
    int increase(int ptr) {
        ++ptr;
        if (ptr >= buffer_size)
            ptr = 0;
        return ptr;
    }
};

int binarySearch(int arr[], int n, int val) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (arr[mid] < val) {
            l = mid + 1;
        } else if (arr[mid] > val) {
            r = mid - 1;
        } else
            return mid;
    }
    return -1;
}
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v)
            : val(v),
              left(NULL),
              right(NULL) {

    }
};
// Max heaps
class Heaps {
 public:

    Heaps() {
        array = new int[10];
        size = 0;
    }
    ~Heaps() {
        cout << "destroy Heaps" << endl;
        delete array;
    }
    bool empty() {
        return size == 0;
    }
    void insert(int val) {
        if (size >= 10)
            return;
        array[size++] = val;
        int cur = size - 1;
        int parent = (cur - 1) / 2;
        while (array[cur] > array[parent]) {
            int temp = array[cur];
            array[cur] = array[parent];
            array[parent] = temp;
            cur = parent;
            parent = (cur - 1) / 2;
        }
    }
    int pop() {
        if (size == 0)
            return -1;
        int ret = array[0];
        array[0] = array[--size];
        int cur = 0;
        while (true) {
            int bigger_child = cur * 2 + 1;
            if (bigger_child >= size)
                break;
            if (cur * 2 + 2 < size && array[bigger_child] < array[cur * 2 + 2])
                bigger_child++;
            if (array[bigger_child] > array[cur]) {
                int temp = array[bigger_child];
                array[bigger_child] = array[cur];
                array[cur] = temp;
                cur = bigger_child;
            } else
                break;
        }
        return ret;
    }
 private:
    int* array;
    int size;

};
int main() {
    int arr[] = { 0, 1, 2, 2, 2, 3, 6, 8, 10 };
    cout << binarySearch(arr, sizeof(arr) / sizeof(arr[0]), 2) << endl;

    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    st.pop();
    st.push(5);
    st.push(7);
    while (!st.empty()) {
        cout << st.top() << ",";
        st.pop();
    }
    cout << endl;
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);
    q.push(12);
    q.push(12);
    q.push(13);
    q.pop();
    q.push(14);
    q.pop();
    q.push(15);
    q.push(16);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(17);

    while (!q.empty()) {
        cout << q.front() << ",";
        q.pop();
    }
    cout << endl;
    Heaps hp;
    hp.insert(3);
    hp.insert(1);
    hp.insert(7);
    hp.insert(2);
    hp.insert(4);
    hp.insert(1);
    hp.insert(3);
    hp.insert(5);
    while (!hp.empty()) {
        cout << hp.pop() << ",";
    }
    return 0;
}
