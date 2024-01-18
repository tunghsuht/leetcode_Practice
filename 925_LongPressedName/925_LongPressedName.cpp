class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;

        if((name[name.size()-1] != typed[typed.size()-1]) || (name[0] != typed[0]))return false;

        while(i < name.size() && j < typed.size()){
            if(name[i] == typed[j]){
                i++;
                j++;
            }else if(typed[j] == name[i-1]){
                j++;
            }else{
                return false;
            }
        }

        if(i < name.size())return false;
        
        while(j < typed.size()){
            if(typed[j] != name[name.size()-1])return false;
            j++;
        }

        return true;
    }
        
};
