/*
Create Substrings With ASCII number :
ip := "AB"
op := "" "B" "66" "A" "BA" "66A"  "65" "B65" "6665"
*/
#include<bits\stdc++.h>
using namespace std;
void subsequence(string s,string ans)
{
    if(s.length()==0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);

    subsequence(ros, ans);
    subsequence(ros, ans + ch);
    subsequence(ros, ans + to_string(code));//stl used to_string(code)
}
int main()
{
    subsequence("AB", "");
    return 0;
}
/*
Output :

B
66 
A  
AB 
A66
65 
65B
6566
*/