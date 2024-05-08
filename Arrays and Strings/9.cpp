#include <bits/stdc++.h>

using namespace std;

int main(){

    string s1;
    cout << "Input the original string:" << endl;
    cin >> s1;

    string s2;
    cout << "Input the possible rotated string:" << endl;
    cin >> s2;

    if(s1.size() != s2.size()){
        cout << "Not a rotation" << endl;
        return 0;
    }

    int operation_count = 0;
    while(s1 != s2 && operation_count < s1.size()){
        operation_count++;
        
        char begin_char = s2[0];
        reverse(s2.begin(), s2.end());
        s2.pop_back();
        reverse(s2.begin(), s2.end());
        s2.push_back(begin_char);

        if(s1 == s2){
            cout << "Is a rotation" << endl;
            return 0;
        }
    }

    cout << "Not a rotation" << endl;
    return 0;
}