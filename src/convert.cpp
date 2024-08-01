class Solution {
public:
    string convert(string s, int numRows)
    {
        if(numRows<2)
        return s;

    int arr[numRows][s.size()];
    memset(arr,-1,sizeof(arr));
    string ans;

    int changer=1;
    int row=0;

    for(int i=0;i<s.size();i++){
        arr[row][i]=s[i];
        if(row==numRows-1)
            changer=-1;
        if(row==0)
            changer=1;
        row=row+changer;
    }
    for(int i=0;i<numRows;i++){
        for(int j=0;j<s.size();j++){
            if(arr[i][j]!=-1)
                ans.push_back(arr[i][j]);
        }
    }
    return ans;
    }
};
