#include<iostream>

using namespace std;

/*
There are three types of Control Structure in C++
 1. Sequence Structure : it's the whole program as it does execute in sequence line by line
 2. Selection Structure : check some condition & executes the selected code. e.g. If/else and switch-case
 3. Loop Structure : check some condition & iterates until the condition become false e.g. forloop, whileloop
*/
int main(){
    cout<<"Learning about control structure in C++"<<endl;

    // Selection Control Structure 
    int age;
    cout<<"Enter Your age : ";
    cin>>age;
    if (age>=18){
        cout<<"Yo Boiii! Your can Drive."<<endl;
    }
    else if (age<0)
    {
        cout<<"Boiii! Go and sleep in your Mama's godi"<<endl;
    }
    else{
        cout<<"No Boiiii!"<<endl;
    }

    switch (age)
    {
    case 18:
        cout<<"You are 18 brother"<<endl;
        break;
    default:
        cout<<"You are Human brother"<<endl;
        break;
    }

    /* Loop Control Structure
        There are three of loops in C++
            1. For loop
            2. While loop
            3. do-while loop
    */

    // For loop
    for(int i=0; i<10; i++){
        cout<<i;
    }
    cout<<"\n";

    // while loop
    int i = 0;
    while (i<10){
        cout<<i;
        i ++;
    }
    cout<<"\n";

    // do-while loop
    int j = 0;
    do
    {
        j++;
        cout<<"6 x "<<j<<" : "<<6*j<<endl;
    } while (j<10);
    
    return 0;
}