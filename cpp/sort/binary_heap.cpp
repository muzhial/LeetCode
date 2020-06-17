#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using std::vector;

// max priority queue
class BinaryHeap {
public:
    BinaryHeap(vector<int>pq) {
        pq_.push_back(0);
        pq_.insert(pq_.end(), pq.begin(), pq.end());
    }
    
    int size() {
        return pq_.size();
    }
    int max() {
        return pq_[1];
    }
    void exch(int i, int j) {
        std::swap(pq_[i], pq_[j]);
    }
    int parent(int chd) {
        return chd / 2;
    }
    int left(int root) {
        return root * 2;
    }
    int right(int root) {
        return root * 2 + 1;
    }
    
    void swim(int k) {
        while (k > 1 && pq_[parent(k)] < pq_[k]) {
            exch(parent(k), k);
            k = parent(k);
        }
    }
    void sink(int k) {
        while (k <= size() / 2) {
            int greater = pq_[left(k)] < pq_[right(k)] ? right(k) : left(k);
            if (pq_[greater] < pq_[k]) {
                break;
            }
            exch(greater, k);
            k = greater;
        }
    }
    void insert(int val) {
        pq_.push_back(val);
        swim(size());
    }
    int del() {
        int max_ = max();
        exch(1, size());
        pq_.pop_back();
        sink(1);
        return max_;
    }
    // 如果时删除某个指定 key 呢?

private:
    // 从索引 1 开始存储
    vector<int> pq_;
};

int main() {
    vector<int> vi{1, 2, 4, 5, 12, 56, 8, 10};
    BinaryHeap bp(vi);
    cout << bp.size() << endl;
}