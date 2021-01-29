// Problem: 380. Insert Delete GetRandom O(1)
// Link: https://leetcode.com/problems/insert-delete-getrandom-o1/

/* Nhận xét:
- Để mô tả set này, ta có thể dùng một hash table để có độ phức tạp cho các thao tác là O(1).
- Tuy nhiên, để có thể làm được thao tác random, ta cần sử dụng hàm rand của C++. Hàm rand này chỉ cho ra một số xác định và ta có thể đưa giá trị này về
nằm trong 1 range nào đó dựa vào thao tác modulo.
- Tuy nhiên, set của chúng ta lại là các thứ tự rời rạc và không có 1 range xác định nào, do đó để dùng giá trị random và chọn ra được một value tương ứng,
ta cần đưa các key của ta vào một mảng arr. Khi random ra 1 key nào đó, ta lấy value tương ứng với giá trị arr[key].
- Do đó, mảng của chúng ta cần chứa các value nào trong set. Tuy nhiên, để thao tác remove có thể thực hiện với O(1) ta còn cần phải xoá phần tử trong arr đi với 
độ phức tạp O(1). Khi đó, với một value trong set, ta cần lưu tương ứng idx của nó nằm trong arr. Trường hợp, idx nằm ở giữa mảng, ta có thể đổi vị trí của nó
với phần tử cuối mảng, để có thể remove với độ phức tạp O(1).
*/

class RandomizedSet {
private:
  unordered_map<int, int> m;
  vector<int> arr;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
      
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
      if (m.find(val) != m.end()) {
        return false; 
      }
      arr.push_back(val);
      m[val] = arr.size() - 1;
      return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      if (m.find(val) == m.end()) {
        return false;
      }
      int idx = m[val];
      int target = arr.size() - 1;
      m[arr[target]] = idx;
      arr[idx] = arr[target];
      m.erase(val);
      arr.pop_back();
      return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
      int idx = rand() % arr.size();
      return arr[idx];
    }
};
