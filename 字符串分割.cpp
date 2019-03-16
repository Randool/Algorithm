#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> split(string str, string pattern)
{
    string::size_type pos;
    vector<string> result;
    str += pattern;
    int size = str.size();

    for(int i=0; i<size; i++)
    {
        pos = str.find(pattern, i);
        if(pos < size)
        {
            string s = str.substr(i, pos-i);
            result.push_back(s);
            i = pos;
        }
    }
    return result;
}

int main() {
    char s[] = "Golden Global View,disk * desk";
    printf("strtok �ָ%s", s);
    const char* d = " ,*";
    char* p;
    p = strtok(s, d);
    while(p)
    {
        printf("%s\n", p);
        p = strtok(NULL, d);
    }

    cout << endl << "find & substr:" << endl;
    string str;
    string pattern;
    cout << "Input the string: ";
    getline(cin, str);
    cout << "Input the pattern: ";
    getline(cin, pattern);
    vector<string> result = split(str, pattern);
    cout << "The result:" << endl;
    for(int i=0; i<result.size(); i++)
        cout << result[i] << endl;


    return 0;
}
