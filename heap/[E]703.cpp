// Problem: 703. Kth Largest Element in a Stream - Easy
// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/

/* Nhận xét:
- Do ta phải chọn phần tử lớn thứ k, nên nếu ta maintain một min heap có k phần tử thì ta sẽ đẩy phần tử cần tìm lên vị trí số top of heap.
- Với thao tác constructor, ta phải duyệt qua toàn bộ dãy, cứ khi nào dãy có k + 1 phần tử thì ta lại pop ra khỏi heap, điều này đảm bảo ta sẽ luôn pop
một phần tử nào đó nhỏ hơn phần tử lớn thứ k. Sau khi hoàn thành constructor thì phần tử lớn thứ k sẽ trở nên nhỏ nhất và đẩy lên đầu heap.
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) : _k(k) {
        for (int val : nums) {
            heap.push(val);
            if (heap.size() > _k) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if (heap.size() > _k) {
            heap.pop();   
        }
        return heap.top();
    }
};
