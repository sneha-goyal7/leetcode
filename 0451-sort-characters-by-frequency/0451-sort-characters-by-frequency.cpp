class Solution {
public:
    string frequencySort(string s) {
        map<char, int> count;
            for(int i = 0; i < s.size(); i++){
                count[s[i]]++;
            }
            string result="";
            while(!count.empty()){
                int maxCount = 0;
                char maxChar;
                for(auto &p : count){
                    if(p.second > maxCount){
                        maxCount = p.second;
                        maxChar = p.first;
                    }
                }
                  for(int i = 0; i < maxCount; i++){  
                result.push_back(maxChar);
            }
                count.erase(maxChar);
            }
            return result;
    }
};