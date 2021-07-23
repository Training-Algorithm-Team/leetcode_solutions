// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

/* Noi chung ve y tuong thi chi la luu cac diem ma no khac khong, anh dung hash table theo thoi quen.
- Code xong thay bon no dung vector luu sorted index thoi cung duoc.

*/

class SparseVector {
    
public:
    unordered_map<int, int> hash;
    
    SparseVector(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                hash[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if (vec.hash.count(it->first)) {
                res += it->second * vec.hash[it->first];   
            }
        }
        return res;
    }
};
