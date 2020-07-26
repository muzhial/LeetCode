# 十大排序算法

* [参考](https://www.cxyxiaowu.com/2026.html)

![](imgs/sort/sort_1.png)

## 冒泡排序

时间复杂度为 O(n^2)，空间复杂为 O(1)，in-place，稳定。

```cpp
vector<int>& BubbleSort(vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++) {
        bool flag = true;
        for (int j = 0; j < arr.size() - i; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;

                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
    return arr;
}
```

## 选择排序

时间复杂度为 O(n^2)，空间复杂为 O(1)，in-place，不稳定。

```cpp
vector<int>& SelectionSort(vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            int tmp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = tmp;
        }
    }
    return arr;
}
```

## 插入排序

```cpp
vector<int> InsertionSort(vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++) {
        int index = i;
        int tmp = arr[i];
        while (index > 0 && arr[index-1] > tmp) {
            arr[index] = arr[index-1];
            index--;
        }
        arr[index] = tmp;
    }
    return arr;
}
```

## 归并排序

`python` 版本

```python
class Sort:

    def merge_sort(self, alist):
        if len(alist) <= 1:
            return alist
        
        mid = len(alist) / 2
        left = self.merge_sort(alist[:mid])
        right = self.merge_sort(alist[mid:])
        
        return self.merge(left, right)

    def merge(self, A, B):
        sorted_arr = []
        l = 0
        r = 0
        while l < len(A) and r < len(B):
            if A[l] < B[r]:
                sorted_arr.append(A[l])
                l += 1
            else:
                sorted_arr.append(B[r])
                r += 1
            
        sorted_arr += A[l:]
        sorted_arr += B[r:]

        return sorted_arr
```

`cpp` 版本
```cpp
void Merge(vector<int>& arr, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) {
            i++;
        } else {
            for (int k = j; k > i; k--) {
                std::swap(arr[k], arr[k - 1]);
            }
            i++;
            m++;
            j++;
        }
    }
}
// MergeSort(arr, 0, arr.size() - 1);
void MergeSort(vector<int>& arr, int l, int u) {
    if (l >= u) {
        return;
    }
    int m = l + (u - l) / 2;
    MergeSort(arr, l, m);
    MergeSort(arr, m + 1, u);
    Merge(arr, l, m, u);
}
```


## 快速排序

```python
# out-place 版本
def qsort_out(alist):
    if len(alist) <= 1:
        return alist
    else:
        pivot = alist[0]
        return qsort_in([x for x in alist[1:] if x < pivot]) + \
               [pivot] + \
               qsort_in([x for x in alist[1:] if x >= pivot])

# in-place 版本
# qsort_in(unsortedArray, 0, len(unsortedArray) - 1)
def qsort_in(alist, l, u):
    if l >= u:
        return
    
    m = l
    for i in range(l + 1, u + 1):
        if alist[i] < alist[l]:
            m += 1
            alist[m], alist[i] = alist[i], alist[m]
    alist[m], alist[l] = alist[l], alist[m]
    qsort_in(alist, l, m - 1)
    qsort_in(alist, m + 1, u)
```

`cpp` 版本

```cpp
void QsortOut(vector<int>& arr, vector<int>& ret) {
    if (arr.size() <= 0) {
        return;
    }
    vector<int> l_arr;
    vector<int> r_arr;
    int pivot = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < pivot) {
            l_arr.push_back(arr[i]);
        } else {
            r_arr.push_back(arr[i]);
        }
    }
    QsortOut(l_arr, ret);
    ret.push_back(pivot);
    QsortOut(r_arr, ret);
}

void QsortIn(vector<int>& arr, int low, int up) {
    if (low >= up) {
        return;
    }
    int m = low;
    for (int i = low + 1; i <= up; ++i) {
        if (arr[i] < arr[low]) {
            m++;
            if (m != i) {
                std::swap(arr[i], arr[m]);
            }
        }
    }
    std::swap(arr[low], arr[m]);
    QsortIn(arr, low, m - 1);
    QsortIn(arr, m + 1, up);
}
```


## 堆排序

```cpp
// max priority queue
class BinaryHeap {
public:
    BinaryHeap() {
        pq_.push_back(0);
    }
    BinaryHeap(vector<int>pq) {
        pq_.push_back(0);
        pq_.insert(pq_.end(), pq.begin(), pq.end());
    }
    
    int size() {
        return pq_.size();
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
        while (k < size() / 2) {
            int greater = pq_[left(k)] < pq_[right(k)] ? right(k) : left(k);
            if (pq_[greater] < pq_[k]) {
                break;
            }
            exch(greater, k);
            k = greater;
        }
    }

    //////////////////////
    void insert(int val) {
        pq_.push_back(val);
        swim(size() - 1);
    }

    // 如果是删除某个指定 key 呢?

    // 构建 maxheap
    void build() {
        for (int k = (size() - 1) / 2; k >= 1; --k) {
            sink(k);
        }
    }
    void print() {
        for (auto& v : pq_) {
            cout << v << " ";
        }
        cout << endl;
    }

private:
    // 从索引 1 开始存储
    vector<int> pq_;
};
```