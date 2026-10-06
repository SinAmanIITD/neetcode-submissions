class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){return false;}
        unordered_map<char, int> f1;
        unordered_map<char, int> f2;
        for(int i = 0; i<s1.size(); i++){
            f1[s1[i]]++;
            f2[s2[i]]++;
        }
        if(f1==f2){return true;}
        int i = 0;
        int j = s1.size();
        while(j<s2.size()){
            f2[s2[i]]--;
            if(f2[s2[i]]==0) f2.erase(s2[i]);
            f2[s2[j]]++;
            if(f1==f2){return true;}
            i++; j++;
        }
        return false;
    }
};
