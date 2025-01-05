class Solution {
public:
    int compress(vector<char>& chars)
    {
        int modify_index = 0;

        for (int i = 0; i < chars.size(); i++) {
            char c = chars[i];
            int consec_len = 0;
            while (i < chars.size() && c == chars[i]) {
                consec_len++;                          
                i++;
            }
            if (consec_len == 1) {
                chars[modify_index++] = c;
            } else {
                chars[modify_index++] = c;   
                string s = to_string(consec_len);             
                for (char d : s)
                    chars[modify_index++] = d;
            }
            i--;
        }
        chars.resize(modify_index);
        return modify_index;
    }

};

