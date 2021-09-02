#include<iostream>
#include<fstream>
/* fstream header file is used to deal with an file.
 fstream consists of some classes used to work with files.
 The useful classes for working with files in C++ : 
    1. fstreambase
    2. ifstream
    3. ofstream
  -> Both ifstream and ofstream are derived from fstreambase Class.

  First we've to open the file in order to work with it, and for that we've two ways: 
    1. using the constructor.
    2. using the member funciton open() of the class.
*/
using namespace std;

int main(){
    /* Opening files using Constructor : to do that we use ofstream class to create an object and pass file name as argument to 
    it's constructor. */
    ofstream wfile("sample.txt");
    // writing to the file :
    wfile<<"Just Writing to the File";    
    // after writing to the file we also have to close it by using close function, so that later on we can also read the file
    wfile.close();

    /* Reading a file : for reading we have to create an object using ifstream class & pass the file name as constructor's argument but bydefault it stops reading whenever a space or new line comes, to overcome that use use getline function */ 
    string data;
    ifstream rfile("sample.txt");
    // rfile>>data;  will only read one word from the file
    getline(rfile, data);  // but this will also read upto only one line
    cout<<data<<endl;
    rfile.close();

    return 0;
}