#include<iostream>
using namespace std;


// Check if the given number is prime or not.
bool checkPrime(int num){
    bool isPrime = true;
    for (int i=2; i*i<=num; i++){
        // if we check upto i<=sqrt(num) it'll also give true answer or squaring both sides i*i<=num.
        if (num%i==0){
            return false;
        }
    }
    return true;
}

// Find all the primes number less than given number n
// another way to solve this is using Sieve of Eratosthenes method which hace SC : O(n) and TC : O(n(log(logn)))
void printPrime(int n){
    for (int i=2; i<=n; i++){
        if (checkPrime(i)){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

// Finding trailing Zeroes in Factorial of a number e.g. 12! = 479001600, has two trailing zeroes
int trailing0(int num){
    // To solve it first we've to count the number of 2's and 5's as it's the smallest no. responsible for a digit 10, the common of 2's & 5's will be the answer, but 2's will be always greater than 5's so we've to focus on no. of 5's, so the answer should be num/5 but in case of 30! num/5=6, but here 5 occurs 2 times at 25 so it should be 7.   
    int count = 0;
    for (int i=25; i<=num; i*=5){
            count += i/5-1;
    }
    count += num/5;
    return count;
}


// Check if a number is palindrome or not
bool isPalindromeNum(int num){
    int temp=num, reverse=0;
    while (temp!=0){
        reverse = reverse*10 + temp%10;
        temp /= 10;
    }
    return (num == reverse);
}


// Sieve of Eratosthenes : used to find prime number upto n
void findPrimes(int num){
}
    

// Find square root of a number
float sqroot(int num){
    float ans;
    for (int i=1; i<=num/2; i++){
        if (i*i<=num){
            ans = i;
            continue;
        }
        break;
    }
    float i, j;
    for (i=1; i<=9; i++){
        if (((ans+i/10)*(ans+i/10)) <= num){
            j=i;
        }
    }
    return ans+(j/10);
}

// Another way to find square root using Binary Search : Time Complexity -> O(logn)
float sqrut(int num, int pre){
    int start=1, end=num ;
    float root;
    while (start<=end){
        root = (start+end)/2;
        if (root*root>num){
            end = root-1;
        }
        else if (root*root<num){
            start = root+1;
        }
        else{
            break;
        }
    }
    (root*root>num)? root-- : root++;
    float incr=0.1;
    for (int i=1; i<=pre; i++){
        while (root*root<=num){
            root = root+incr;
        }
        root -= incr;
        incr /= 10;
    }    
    return root;
}

// Another way to find Square Root -> Newton Raphson Method
float findSqRoot(int num){
    int start=1, end=num ;
    float root;
    while (start<=end){
        root = (start+end)/2;
        if (root*root>num){
            end = root-1;
        }
        else if (root*root<num){
            start = root+1;
        }
        else{
            break;
        }
    }
    (root*root>num)? root-- : root++;
    root = (root + num/root)/2;
    return root;
}


// Factors of a number  1. BruteForce Approach, Time Complexity : O(n)
void factors(int num){
    for (int i=1; i<=num; i++){
        if (num%i==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
// Another approach, Time Complexity : O(sqrt(n))
void factor(int num){
    for (int i=1; i*i<=num; i++){
        if (num%i==0){
            if (i*i==num){
                cout<<i<<" ";
                continue;
            }
            cout<<i<<" "<<num/i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    checkPrime(7);
    printPrime(40);
    cout<<"Square root : "<<sqroot(8)<<endl;

    cout<<trailing0(19)<<endl;

    cout<<isPalindromeNum(301)<<endl;

    findPrimes(25);

    cout<<sqrut(38, 2)<<endl;
    cout<<findSqRoot(38)<<endl;

    factors(20);
    factor(36);

    return 0;
}