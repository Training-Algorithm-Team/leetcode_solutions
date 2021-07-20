// https://leetcode.com/problems/lru-cache/

/* Bai nay luc dau anh cung nghi den huong su dung hash table ket hop voi list.
- Co ma code lang nhang qua nen tuong sai, van phai tham khao qua discussion.

*/

class LRUCache {
private:
    typedef list<int>::iterator lit;
    typedef pair<int, lit> pilit;
    typedef unordered_map<int, pilit> hash_table;
    
    list<int> order;
    hash_table hash;
    int _capacity;
    
    void fixOrder(hash_table::iterator it) {
        order.erase(it->second.second);
        order.push_front(it->first);
        it->second.second = order.begin();
    }
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        auto it = hash.find(key);
        if (it == hash.end()) {
            return -1;
        }

        fixOrder(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = hash.find(key);
        if (it != hash.end()) {
            hash[key].first = value;
            fixOrder(it);
        } else {
            order.push_front(key);
            hash[key] = {value, order.begin()};
            if (order.size() > _capacity) {
                int toRemove = order.back();
                hash.erase(toRemove);
                order.pop_back();
            }
        }
    }
};
