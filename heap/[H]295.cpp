// Problem: 295. Find Median from Data Stream - Hard
// Link: https://leetcode.com/problems/find-median-from-data-stream/

/* C1: Sử dụng set
- Sử dụng một multiset để lưu các phần tử theo thứ tự tăng dần. Khi đó thao tác tìm median cần phải duyệt qua n/2 phần tử vì multiset không phải là random access container.
- Time complexity:
  + addNum: O(log(n))
  + findMedian: O(n);
- Space complexity: O(n)
*/

class MedianFinder {
public:
    multiset<int> s;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        int count = 0;
        auto it = s.begin();
        int target = (s.size() - 1) / 2;
        // cout << "target = " << target << endl;
        while (count++ < target) {
            it++;
        }
        if (s.size() & 1) {
            return *it;
        } else {
            int first = *it;
            int second = *next(it);
            return ((double) first + second) / 2;
        }
    }
};

/* C2: Sử dụng sorted array
- Với cách 1, dù là lưu một dãy được sort nhưng có nhược điểm là thao tác findMedian có độ phức tạp quá lớn O(n) do không phải random access container. Ta có thể khắc phục
bằng việc sử dụng vector để có thể random access.
- Lưu một vector và đảm bảo vector này luôn có thứ tự tăng dần. Với thao tác add, thay vì ta add vào cuối và sort lại (độ phức tạp nlog(n)), ta có thể sử dụng binary search
để tìm vị trí phù hợp trước, sau đó add vào vị trí đó chỉ mất độ phức tạp O(n).
- Với thao tác findMedian, ta chỉ cần chọn các phần tử ở giữa và return.
- Time complexity:
  + addNum: O(n)
  + findMedian: O(1)
- Space complexity: O(n)
*/
class MedianFinder {
public:
    vector<int> _data;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = upper_bound(_data.begin(), _data.end(), num);
        _data.insert(it, num);
        // for (int i = 0; i < _data.size(); ++i) {
        //     cout << _data[i] << " ";
        // }
        // cout << endl;
    }
    
    double findMedian() {
        int n = _data.size();
        if (n & 1) {
            return _data[n / 2];
        } else {
            return ((double)_data[n/2-1] + _data[n/2]) / 2;
        }
    }
};

/* C3: Sử dụng heap
- Với phương pháp 2, thao tác addNum vẫn còn độ phức tạp khá lớn, O(n). 
- Ta có thể improve bằng cách sử dụng 2 heap, 1 min heap lưu nửa lớn hơn của dãy => top of heap là phần tử ở nằm giữa dãy khi được sort, 1 max heap lưu nửa nhỏ hơn của dãy
=> top of heap là phần tử nằm giữa khi dãy được sort.
- Ta thiết kế phù hợp để khi số phần tử lẻ, thì maxHeap luôn > minHeap 1 phần tử => top of maxHeap là median. Trường hợp số phần tử chẵn thì ta chia đều ra 2 heap
và lấy trung bình của top of mỗi heap.
- Time complexity:
  + addNum: O(log(n))
  + getMedian: O(1)
- Space complexity: O(n)
*/
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    int dataSize() {
        return maxHeap.size() + minHeap.size();
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (dataSize() & 1) {
            return maxHeap.top();
        } else {
            return ((double) maxHeap.top() + minHeap.top()) / 2;
        }
    }
};

/* C4: Distribution counting
- Với các câu hỏi follow up:
If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
- Ta có thể đếm số lần xuất hiện của các phần tử và khi lấy median, ta duyệt qua mảng 100 phần tử để chọn ra phần tử đứng giữa.
- Trường hợp 1% >= 101 => median sẽ không bao giờ rơi vào đoạn này => ta coi tất cả có giá trị là 101, điều này không làm ảnh hưởng đến median của dãy.
- Tuy nhiên cách này tôi chưa submit được vì input của problem có cả các trường hợp mà median nằm ngoài khoảng [0, 100]
- Time complexity:
  + addNum: O(1)
  + getMedian: O(100)
- Space complexity: O(100)
*/

class MedianFinder {
public:
    vector<int> freq;
    int n;
    /** initialize your data structure here. */
    MedianFinder() : freq(vector<int>(102, 0)), n(0) {
        
    }
    
    int getVal(int pos) {
        int count = 0;
        for (int i = 0; i < 102; ++i) {
            count += freq[i];
            if (count >= pos) {
                // cout << "val = " << max(0, i - 1) << endl;
                return i;
            }
        }
        return 0;
    }
    
    void addNum(int num) {
        int target = min(num, 101);
        target = max(num, 0);
        freq[target]++;
        n++;
    }
    
    double findMedian() {
        if (n & 1) {
            return getVal(n / 2 + 1);
        } else {
            return ((double)getVal(n/2) + getVal(n/2+1)) / 2;
        }
    }
};
