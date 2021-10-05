// Recursion Basics (Level-1) question
#include<iostream>
using namespace std;

/* Write a Recursive Function to print from 1 till n 
Sol. As first we are doing the operation(printing the number) and then calling the recursive function, so it's know as Tail
     Recursion                      */
void print1ton(int num){
    cout<<num<<" ";
    if (num==1){
        return;
    }
    print1ton(num-1);
}

/* Write a Recursive function to print number from n till 1  
Sol. Head recursion will be used, bec as we hit the base case then return and start printing nums, so first recursive function 
     will be called then other operation will performed, that's why it's called Head Recursion.                 */
void printNto1(int num){
    if (num == 1){
        cout<<1<<" ";
        return;
    }
    printNto1(num-1);
    cout<<num<<" ";
}


/* Write Recursive function to print number from n to 1 & 1 to n */
void printNum(int num){
    cout<<num<<" ";
    if (num == 1){
        return;
    }
    printNum(num-1);
    cout<<num<<" ";
}

// Recursive function to find sum of 1 to n numbers
int findSum(int num){
    if (num <= 1){
        return num;
    }
    return num+findSum(num-1);
}

// Recursive function to find sum of digits in a number
int digitSum(int num){
    if (num == 0){
        return 0;
    }
    return num%10 + digitSum(num/10);
}


// Recursive function to find product of digits in a number
int digitProduct(int num){
    if (num/10 == 0){
        return num;
    }
    return num%10 * digitProduct(num/10);
}

// Using Recursion reaverse a given number
// Sometimes when we need some additional variables in argument, in such case make another helper function
int helper(int num, int rev=0){
    if (num==0){
       return rev;
    }
    rev = rev*10 + num%10;
    return helper(num/10, rev);
}
int reverseNum(int num){
    return helper(num);
}

// Check if a number is palindrom or not
bool checkPalindrome(int num){
    return (num==helper(num));
}


// Count the Number of Zeroes present in a Number
int helper0(int num, int count=0){
    if (num==0){
        return count;
    }
    if (num%10==0) count++;
    return helper0(num/10, count);
}
int countZeros(int num){
    if (num==0){
        return 1;
    }
    return helper0(num);
}
// Another way without using a helper function
int countZero(int num){
    if (num == 0){
        return 0;
    }
    if (num%10==0){
        return 1+countZero(num/10);
    }
    return countZero(num/10);
}


// Recursive Program to find Number of Steps to Reduce a Number to Zero
int findSteps(int num){
    if (num==0){
        return 0;
    }
    if ((num&1)==0){
        return 1+findSteps(num/2);
    }
    return 1+findSteps(num-1);
}


int main(){
    printNto1(5);
    cout<<endl;

    print1ton(5);
    cout<<endl;

    printNum(5);
    cout<<endl;

    cout<<findSum(5)<<endl;

    cout<<digitSum(549)<<endl;
    
    cout<<digitProduct(549)<<endl;

    cout<<reverseNum(54321)<<endl;

    cout<<checkPalindrome(123421)<<endl;

    cout<<countZeros(10040)<<endl;
    cout<<countZeros(0)<<endl;

    cout<<countZero(302040)<<endl;

    cout<<findSteps(14)<<endl;
    cout<<findSteps(8)<<endl;

    return 0;
}