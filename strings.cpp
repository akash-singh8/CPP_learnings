#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string name;
    // cout<<"Enter your name dude : ";
    // cin>>name;
    // cout<<name<<endl;

    // Another way to declare a String : 
    string str(5, 'a');
    cout<<str<<endl;

    // To take a space separated user input string we use getline() function
    // string Name;
    // getline(cin, Name);
    // cout<<Name<<endl;

    // String's Functions
    // Concatiniting a string
    string s1 = "fam";
    string s2 = "ily";
    cout<<s1+s2<<endl; // or we can also use s1.append(s2)

    // Indexing can also be used with string as we use in Arrays
    cout<<s1[1]<<endl;

    string fst = "acb";
    string sec = "bac";

    // Converting a lowercase string to upper case
    for (int i=0; i<fst.length(); i++){
        if (fst[i]>='a'){
            fst[i] = fst[i] - 32;
        }
    }
    cout<<fst<<endl;

    // form the biggest number from the numeric string
    string stri = "53214";
    sort(stri.begin(), stri.end());
    for (int i=0; i<stri.length()/2; i++){
        char temp = stri[i];
        stri[i] = stri[stri.length()-i-1];
        stri[stri.length()-i-1] = temp;
    }
    cout<<stri.begin()<<" "<<stri.end();
    cout<<stri<<endl;
    return 0;
}