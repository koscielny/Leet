class Solution {
    vector<string> result_set;
public:
    vector<string> generateParenthesis(int n) {
        result_set.clear();
        Recur(1, n-1, "(");
        return result_set;
    }
    
    void Recur(int pos_diff, int n_left_parenthesis, string cur_combo){
        if(n_left_parenthesis == 0){
            if(pos_diff >= 0){
                for(size_t i = 0; i < pos_diff; ++i){
                    cur_combo += ')';
                }
                result_set.push_back(cur_combo);
            }
            return;
        }
        else if(n_left_parenthesis > 0){
            if(pos_diff >= 1){
                Recur(pos_diff + 1, n_left_parenthesis - 1, cur_combo + '(');
                Recur(pos_diff - 1, n_left_parenthesis, cur_combo + ')');
                return;
            }
            else if(pos_diff == 0){
                Recur(pos_diff + 1, n_left_parenthesis - 1, cur_combo + '(');
                return;
            }
            else return;
        }
        else return;
    }

};

