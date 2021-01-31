// Problem: 641. Design Circular Deque - Medium
// Link: https://leetcode.com/problems/design-circular-deque/

/* Nhận xét:
- Để mô phỏng được deque vòng, ta sử dụng một mảng với 2 số đánh dấu khởi đầu (s) và kết thúc (e) của deque.
- Ở đây để không cần phải lưu thêm biến là số lượng hiện tại của deque, ta lưu s là vị trí phần tử đầu tiên, e là phần tử NẰM SAU phần tử cuối cùng. 
Tức là vị trí s đánh dấu kết thúc và ta không sử dụng vị trí s này. Trường hợp ta lưu e là vị trí phần tử cuối cùng, thì khi e = s - 1, 
ta sẽ không thể xác định được là khi đó mảng có n phần tử hay là mảng có 0 phần tử.
- Vì ta không sử dụng ví trị s, ta phải sử dụng mảng có n + 1 phần tử để mô phỏng, khi đó ta có thể xử lý các trường hợp như sau:
  + s == e => Mảng không phần tử 
  + Ví dụ: s = 0, e = n => Mảng có n phần tử. Hoặc: s - 1 == e.
- Các thao tác còn lại ta cần chỉnh lại vị trí s hoặc e và gán giá trị đơn thuần.
- Time complexity: O(1) cho tất cả các thao tác trừ thao tác constructor O(n)
- Space complexity: O(n)
*/

class MyCircularDeque {
private:
    vector<int> _deque;
    int s, e, _size;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    
    MyCircularDeque(int k) :s(0), e(0), _size(k+1) {
        _deque.resize(_size);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if ((s + _size - 1) % _size != e) {
            s = (s + _size - 1) % _size;
            _deque[s] = value;
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if ((e + 1) % _size != s) {
            _deque[e] = value;
            e = (e + 1) % _size;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (s != e) {
            s = (s + 1) % _size;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (s != e) {
            e = (e + _size - 1) % _size;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (s != e) {
            return _deque[s];
        }
        return -1;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (s != e) {
            return _deque[(e+_size-1) % _size];
        }
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return s == e;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (s + _size - 1) % _size == e;
    }
};
