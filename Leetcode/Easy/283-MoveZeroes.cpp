class Solution {
public:
    void moveZeroes(vector<int>& v) {
    int n = v.size();
    int j = -1;
    for(int i = 0; i<n; i++){
        if(v[i] == 0){
            j = i;
            break;
        }
    }
    if(j==-1){
        return;
    }

    for(int i = j+1; i<n; i++){
        if(v[i]!=0){
            swap(v[i],v[j]);
            j++;
        }
    }
    }
};
