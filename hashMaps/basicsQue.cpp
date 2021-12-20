#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


// Given an array of integer, return the number with maximum frequency
void maxFrequency(int *arr, int size){
    unordered_map<int, int> freq;
    int maxFreq = arr[0];
    for (int i=0; i<size; i++){
        freq[arr[i]] += 1;
        if (freq[maxFreq] <= freq[arr[i]]){
            maxFreq = arr[i];
        }
    }
    cout<<maxFreq<<" has the Max Frequency of : "<<freq[maxFreq]<<endl;
}


// Given an array/vector of integers remove dublicates from it, & return a vector
vector<int> removeDuplicates(int arr[], int size){
    unordered_map<int, bool> uMap;
    vector<int> unique;
    for (int i=0; i<size; i++){
        int curr = arr[i];
        if (!uMap[curr]){
            unique.push_back(curr);
            uMap[curr] = true;
        }
    }
    return unique;
}


// Given an String, return string which has only unique characters
string removeDuplicates(string str){
    unordered_map<char, bool> uniqueChar;
    string unique = "";
    for (int i=0; i<str.length(); i++){
        if (uniqueChar[str[i]] == 0){
            uniqueChar[str[i]] = true;
            unique += str[i];
        }
    }
    return unique;
}


// Given two array of different size, print their intersections
void intersection(int *arr1, int *arr2, int s1, int s2){
    unordered_map<int, bool> intrs;
    for (int i=0; i<s1; i++) intrs[arr1[i]] = true;
    for (int j=0; j<s2; j++){
        if (intrs[arr2[j]]) cout<<arr2[j]<<" ";
    }
    cout<<endl;
}


// Given an array, print the count of pairs of elements which sums to 0
void countPairs(int *arr, int size){
    unordered_map<int, bool> p;
    int countPair = 0;
    for (int i=0; i<size; i++){
        if (arr[i] >= 0) p[arr[i]] += 1;
        else{
            if (p[-arr[i]] > 0) countPair++;
        }
    }
    cout<<"Pairs : "<<2*countPair<<endl;
}


/* Find the longest subsequence in given array 
    e.g. for array 9, 1, 8, 6, 3, 4, 2, 7, 10, 15 
         the subsequences are  -> 1, 2, 3, 4  -> 6, 7, 8, 9, 10  so the ls are : 6 to 10 
   -> A simple way is to sort the array then find the longest subsequence    */ 
// void findlongSubSeq(int arr[], int size){
// }
void longSubSeq(int arr[], int size){
    // unordered_map<int, bool> map;
    // for (int i=0; i<size; i++){
    //     map[arr[i]] = 1;
    // }

}


// Given an array find the numbers of pairs with difference k
// but the current solution will only be true when k is greater than 0 and we've to find the pairs with absolute difference
int pairDiffk(int arr[], int size, int k){
    unordered_map<int, int> pairs;
    for (int i=0; i<size; i++){
        pairs[arr[i]] += 1;
    }
    int p = 0;
    for (int i=0; i<size; i++){
        if (pairs[arr[i]-k] > 0){
            p += 1;
        }
    }
    return p;
}

int main(){

    int arr[9] = {1, 2, 3, 2, 1, 5, 4, 1, 3};

    maxFrequency(arr, 9);

    vector<int> vec = removeDuplicates(arr, 9);
    for (int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout << endl;

    cout << removeDuplicates("ababacd") << endl;

    int arr1[6] = {2, 6, 8, 5, 4, 3};

    intersection(arr, arr1, 9, 6);

    int arr2[5] = {2, 1, -2, 2, 3};
    countPairs(arr2, 5);

    // Iterator in STL, is used to iterate over data structures like vector, map, unordered_map, set, etc.
    // Iterating through unordered_map :
    unordered_map<string, int> data;
    data["Akash"] = 18;
    data["Elon"] = 43;
    data["Jeff"] = 42;
    // Creating an iterator
    unordered_map<string, int> :: iterator it;
    for (it=data.begin(); it!=data.end(); it++){
        cout << it->first << " : " << (*it).second << endl;
    }
    // it's like an pionter which is initially pointing to the first pair of key:value in unorderedmap

    int newArr[4] = {4, 4, 4, 3};
    cout << "No. of Pairs : " << pairDiffk(newArr, 4, 1) << endl;


    // int temp[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 15};
    // findlongSubSeq(temp, 10);


    return 0;
}