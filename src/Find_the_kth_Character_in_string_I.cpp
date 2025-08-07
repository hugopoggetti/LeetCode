class Solution {
public:
    char kthCharacter(int k) 
    {
        std::string word = "a";
        std::string generated = "";
        
        while (word.size() < k) {
            word += get_next_gen(word);
        }
        return word[k - 1];
    }
    private:
        int get_alpha_value(int c)
        {
            return c % 24;
        }
        
        std::string get_next_gen(const std::string &word)
        {
            std::string next;

            for (size_t i = 0; i < word.size(); i++) {
                next.push_back(word[i] + 1);
            }
            return next;
        }
};
