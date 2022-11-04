class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int,int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)>0)
            return 0;
        arr.push_back(val);
        mp[val]=arr.size()-1;
        return 1;    
    }
    
    bool remove(int val) {
        if(mp.count(val)==0)
            return 0;
        int last=arr.back();
        mp[last]=mp[val];
        arr[mp[val]]=last;
        arr.pop_back();
        mp.erase(val);
        return 1;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */