//Problem: 1712. Ways to Split Array Into Three Subarrays - Medium
//Link: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/

/*
1. Nhận xét:
- Nếu sử dụng mảng prefix sum, có thể tính tổng left, mid, right với độ phức tạp O(1)
- Khi dãy left càng tăng, thì số lựa chọn cho dãy mid và dãy right càng giảm.
- Khi ta chốt dãy left cố định, thì ta có thể sử dụng một mốc để chia 2 dãy mid và right. Mốc này sẽ nằm trong 1 khoảng LIÊN TỤC. 
Mục tiêu của ta là phải đi tìm biên trái và biên phải của “khoảng mốc” này.
2. Phương án:
- Thử tất cả các vị trí có thể cho dãy left.
- Với mỗi vị trí này, ta sử dụng binary search để tìm biên trái và biên phải của “khoảng mốc”:
	+ Với biên trái: điều kiện tất cả những điểm ở bên phải của biên có total mid > total left
	+ Với biên phải: điều kiện tất cả những điểm ở bên trái của biên có total right > total mid
- Nếu đến một vị trí của left mà không thể tìm được biên phải và biên trái phù hợp 
=> ta có thể kết luận ngay, vì các vị trí left tiếp theo cũng đều không thỏa mãn
3. Thơi gian code và debug: ~ 2 tiếng
*/

class Solution {
public:
    int n;
    vector<int> pref;
    const int mod = 1e9 + 7;
    
    int findLeft(int l, int r, int low) {
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (pref[mid] - low >= low) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
    
    int findRight(int l, int r, int low) {
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            // cout << endl << "mid = " << mid;
            if (pref[n-1] - pref[mid] >= pref[mid] - low) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        // cout << endl;
        return l;
    }
    
    int waysToSplit(vector<int>& nums) {
        n = nums.size();
        pref.resize(n, 0);
        pref[0] = nums[0];
        
        // cout << pref[0] << " ";
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i-1] + nums[i];
            // cout << pref[i] << " ";
        }
        // cout << endl;
        
        
        int count = 0;
        for (int i = 0; i < n - 2; ++i) {
            int l = i, r = n - 2, low = pref[i];
            // cout << "l = " << l << " r = " << r << " low = " << low;
            int left = findLeft(l, r, low);
            if (pref[left] - low < low) break;
            
            // cout << " left = " << left;
            
            l = i + 1, r = n - 1;
            int right = findRight(l, r, low);
            if (pref[n-1] - pref[right] < pref[right] - low) break;
            // cout << " right = " << right << endl;
            count += max(0, right - left + 1);
            count %= mod;
        }
        return count;
    }
};
