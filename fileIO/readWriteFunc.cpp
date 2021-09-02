#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    /* Using member function of class to read and write the file, but first we've to create an object, and to write in a file 
        we use ofstream class to create an object for writing whereas to read a file we create an object using ifstream class
        and first we've to open a file before writing/reading */
    ofstream wfile;
    // Now the file has been open, so we can write to it by using << operator 
    wfile.open("sample.txt");
    wfile<<"Writing in the file using open() member function.\nI'm Akash Kumar Singh";
    wfile.close();
    // it's mandotory to close the file after using it because if we didn't close it, later on we can't perform any operation on it
    
    ifstream rfile;
    string data;
    rfile.open("sample.txt");
    /* rfile>>data>>data1; this will read 2 words from the file, sa by default a string stores only till no space/newLine found
     getline(rfile, data); but this will also read only one line so, to read the whole file we use a loop and iterate it till 
     the file not ends, to do it we use eof() function (end of file) it returns 1 when file ends;
    */
    while (rfile.eof() != 1){
        getline(rfile, data);
        cout<<data<<endl;
    }
    rfile.close();

    return 0;
}