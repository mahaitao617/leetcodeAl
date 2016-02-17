 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
class Solution {
public:
    /*
    This hepler function insert result strings to "vector<string> result"
    When number of '(' less than "n", can append '(';
    When number of '(' is more than number of ')', can append ')';
    string s : current string;
    int leftpare_need : number of '(' that have not put into "string s";
    int moreleft : number of '(' minus number of ')' in the "string s";
    */
    void helper(string  s,int leftcompare_need,int moreleft)
    {
      if(leftcompare_need==0 && moreleft==0)
      {
      result.push_back(s);
      return ;
      }
      if(leftcompare_need>0)helper(s+"(",leftcompare_need-1,moreleft+1);
      if(moreleft>0)helper(s+")",leftcompare_need,moreleft-1);
    }
    vector<string> generateParenthesis(int n) {
    helper("",n,0);
    return result;
    }
private:
    vector<string>result;
};
