#include <bits/stdc++.h>
using namespace std;

template <typename E>
class Heap {
private:
    vector<E> heap;

    bool isLeaf(int pos) const
        { return (pos >= heap.size()/2) && (pos < heap.size()); }
    int parent(int pos)     const { return (pos-1) / 2; }
    int leftChild(int pos)  const { return 2 * pos + 1; }
    int rightChild(int pos) const { return 2 * pos + 2; }

    void siftdown(int pos) {
        while (!isLeaf(pos)) {
            int _p = leftChild(pos);
            int rc = rightChild(pos);
            if (rc < heap.size() && heap[rc] > heap[_p])
                _p = rc;
            if (heap[pos] > heap[_p]) break;
            swap(heap[pos], heap[_p]);
            pos = _p;
        }
    }

public:
    Heap() { heap.clear(); }
    int size() const { return heap.size(); }
    bool empty() const { return heap.empty(); }

    void buildHeap() {
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
            siftdown(i);
    }

    void insert(const E &it) {
        heap.push_back(it);
        int curr = heap.size() - 1;
        while (curr && heap[curr] > heap[parent(curr)]) {
            swap(heap[curr], heap[parent(curr)]);
            curr = parent(curr);
        }
    }

    E removeFirst() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return 0;
        }
        swap(heap[0], heap[heap.size()-1]);
        E temp = heap[heap.size()-1];
        heap.pop_back();
        if (!heap.empty()) siftdown(0);
        return temp;
    }

    void Show() {
        for (int i = 0; i < heap.size(); ++i)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    Heap<int> heap;

    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        heap.insert(t);
    }
    heap.buildHeap();
    heap.Show();

    while (!heap.empty()) {
        cout << heap.removeFirst() << " ";
    }

    return 0;
}
