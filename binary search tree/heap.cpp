#include <iostream>
#include <vector>
using namespace std;
class Heap{
  private:
  vector <int> heap;

  int left(int index) {
    int l = 2 * index + 1;
    if (l < heap.size())
      return l;
   else
      return -1;
  }

  int right(int index) {
    int r = 2 * index + 2;
    if (r < heap.size())
      return r;
   else
      return -1;
  }

  int parent(int index) {
    if (!index) {
      return 0;
    }
    return (index - 1) / 2;
  }

  void heapifyup(int index) {
    if (index >= 0 && parent(index) >= 0 && heap[parent(index)] > heap[index]) {
      int temp = heap[index];
      heap[index] = heap[parent(index)];
      heap[parent(index)] = temp;
      heapifyup(parent(index));
   }
    return;
  }

  void heapifydown(int index) {
    int child = left(index);
    int child_temp = right(index);
    if (child >= 0 && child >= 0 && heap[child] > heap[child_temp]) {
      heap[child] = heap[child_temp];
    }
    if (child >= 0 && index >= 0 && heap[index] > heap[child]) {
      int temp = heap[index];
      heap[index] = heap[child];
      heap[child] = temp;
      heapifydown(child);
    }
    return;
  }

  public:

  void Insert(int value) {
    heap.push_back(value);
    heapifyup(heap.size() - 1);
    return;
  }

  void Delete(int index) {
    if (index < 0 || index >= heap.size()) {
       return;
    }
    heap[index] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(index);
    return;
  }

  void ShowHeap() {
    if (!heap.size()) {
      cout << "there is no element in the heap.";
  
    } else {
      for (int i = 0; i < heap.size(); i++) {
        cout << heap[i];
        cout << " ";
      }
    }
    return;
  }
  
};

int main() {
  int test_data[10] = {4, 5, 7, 11, 13, 25, 1, 8, 41, 19};
  Heap* minheap = new Heap;
  for (int i = 0; i < (sizeof(test_data) / sizeof(int)); i++) {
    cout << test_data[i] << endl;
    minheap->Insert(test_data[i]);
  }
  minheap->ShowHeap();
  minheap->Delete(9);
  cout << endl;
  minheap->ShowHeap();
  return 0;
}