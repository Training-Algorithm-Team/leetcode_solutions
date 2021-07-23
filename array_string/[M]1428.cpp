// https://leetcode.com/problems/leftmost-column-with-at-least-a-one/

/* Vi la tim leftmost '1', nen neu da tim den cot j roi, ta chuyen sang cac hang khac va chi tim tu cot j tro di.
- Neu ma vi tri do = '0', ta lap tuc chuyen xuong hang duoi.

*/

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dimensions = binaryMatrix.dimensions();
        int m = dimensions[0], n = dimensions[1];
        
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            while (j >= 0 && binaryMatrix.get(i, j) == 1) {
                j--;
            }
            i++;
        }
        return j + 1 < n? j + 1 : -1;
    }
};
