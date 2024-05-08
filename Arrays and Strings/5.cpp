#include <bits/stdc++.h>

using namespace std;

int main(){

    string first_string, second_string;
    cin >> first_string >> second_string;

    if(abs((int)first_string.size() - (int)second_string.size()) > 1){
        cout << "False" << endl;
    }
    else if(first_string.size() == second_string.size()){
        int differences = 0;
        for(int i = 0; i < first_string.size(); i++){
            if(first_string[i] != second_string[i]) differences++;
        }
        differences > 1 ? cout << "False" << endl : cout << "True" << endl;
    }
    else{
        string bigger_string = first_string.size() > second_string.size() ? first_string : second_string;
        string smaller_string = first_string.size() < second_string.size() ? first_string : second_string;
        
        int index_bigger = 0;
        int index_smaller = 0;
        int found_differences = 0;

        while(index_bigger < bigger_string.size() && index_smaller < smaller_string.size()){
            if(bigger_string[index_bigger] != smaller_string[index_smaller]){
                found_differences++;
                index_bigger++;
            }
            else{
                index_bigger++;
                index_smaller++;
            }
        }
        found_differences > 1 ? cout << "False" << endl : cout << "True" << endl;
    }

    return 0;
}