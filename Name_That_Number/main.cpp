/*
ID: kang_zi1
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <typeinfo>

using namespace std;

ofstream fout("namenum.out");
ifstream fin("namenum.in");
ifstream fin_dict("dict.txt");

string num;
map<char,char> numString;

void init_map(){
    char c = 'A';
    for(int i=2; i<=9; i++){
        numString[c]=i-2+'2'; c++; if(c=='Q'||c=='Z') c++;
        numString[c]=i-2+'2'; c++; if(c=='Q'||c=='Z') c++;
        numString[c]=i-2+'2'; c++; if(c=='Q'||c=='Z') c++;
    }
}

int main(){
    init_map();
    fin >> num;
    string dict_name;
    bool flag = true;
    bool flag_none = true;
    while(!fin_dict.eof()){
    	fin_dict >> dict_name;
	if(dict_name.size()!=num.size())
		continue;
	flag = true;
	for(int j=0; j<dict_name.size(); j++){
		//cout << dict_name;
		//cout << typeid(dict_name);
		if(numString[dict_name[j]]!=num[j]){
			flag = false;
			break;
		}
	}
	if(flag){
		fout << dict_name << endl;
		flag_none = false;
	}
    }
    if(flag_none)
	    fout << "NONE" << endl;
    return 0;

}
