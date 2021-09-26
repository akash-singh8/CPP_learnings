#include<iostream>
#include<math.h>
using namespace std;

/* Whatever processes running on our computer internally it's all bunch of 0s and 1s -> a bit(binary digit) which has the
    base of 2 (means only 2 numbers 0 & 1)


   Number Systems : 
    1. Decimal -> 1, 2, 3, 4, 5, 6, 7, 8, 9  -> Base 10
    2. Binary -> 0 & 1  -> Base 2
    3. Octal -> 0, 1, 2, 3, 4, 5, 6, 7  -> Base 8
    e.g  Counting in Decimal -> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ....
         counting in Octal  -> 0, 1, 2, 3, 4, 5, 7, 7, 10, 11, 12, 13, .....
        so,   8 in Decimal -> 10 in Octal
    4. HexaDecimal -> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F  -> Base 16
        e,g,  10 in Decimal -> A in Hexadecimal
    
   Number System Conversion : 
   1. Decimal to Base b :
        just divide the decimal with b and the remainders in backward direction
        (17)10 -> (21)8 -> (10001)2
   2. Any Base b to Decimal : 
        start from the last and first find b^index and multiply it with the num -> and add all of them
        (10001)2 -> (17)10
        to convert a binary to octal -> first convert the binary to decimal and then convert the decimal to octal

   Bitwise Operator : 
    1. And (&) -> takes two operand & returns the AND of them  e.g. 1 & 3 -> 1
    2. Or (|) -> takes two operand & returns OR of them e.g. 1 | 3 -> 3
    3. XOR (^) -> returns true if both bits are opposite(Or only of them is true) e.g. 1 ^ 3 -> 2 
        -> if an number is odd and if we do num^1 it'll return num-1 -> even num
            and if num is even and if we do num^1 it'll return num+1 -> odd num
        -> num ^ 0 -> num (returns the same num)
        -> num ^ num -> 0 (returns 0)
    4. Complement (~) -> it opposites all of the bits 
    5. Left Shift (<<) -> shift all 1 bits to the left
        by doing n left shift to number x (x<<n) it'll be same as doing x * 2^n
        e.g. 10<<1 -> 20
    6. Right Shift (>>) -> shift all 1 bits to the right
        by doing n right shirt to number x (x>>n) it'll be same as doing x/2^n
        e.g. 10>>1 -> 5

   Bit Masking : 
    1. Find ith bit -> To find the ith bit of an number, one way is to right shift it ith times and & it with 1 in this case if
        bit is 1 it'll return 1 else 0, and another way is to left shift 1 ith times and then & it with the number if the ith 
        bit is 1 it'll return a non zero number and if it's zero then it'll return 0.
    2. Set ith bit -> in this we'll set the ith bit to only 1, so To set the bit we can left shift one ith times and then do 
        OR with the number.
    3. Clear ith bit -> it this we'll set the ith bit to only 0(means clear the bit), so To clear to ith bit we have to left 
        shift 1 ith time and then & the complement of it with the number.
    --> n & (n-1) -> sets the last 1 digit to 0.

   Negative of a number in Binary form : 
    As integer takes 4bytes(32bits) the first bit is known as Most Significant Bit(MSB) and the last bit is known as Least 
    Significat Bit (LSB).
    -> MSB take care of sign of the number if it's 0 means number is +ve and if it's 1 -> number is -ve
    -> LSB tells us whether the number is even or odd if it's 1 -> odd and 0 -> even
    Finding the negative of a number : 
     1. do complement of the Number.
     2. Add 1 to it.

    
    Formula : No. of digits in base b of number n -> int(logn(toBase b)) + 1
*/

// Given a number, find if it's even or odd.
void checkEvenOdd(int num){
    // if we use any number with and(&) operator and with 1, if the num is odd it'll always return 1 and if it's even it'll return 0 
    if (num & 1 == 1){
        cout<<"Odd"<<endl;
    }
    else{ 
        cout<<"Even"<<endl;
    }
}


// Given an array of int in which every no. appears twice except one, find that number
int findNum(int arr[], int size){
    int sum = 0;
    for (int i=0; i<size; i++){
        sum = sum ^ arr[i];
    }
    return sum;
}


// find the number of set bit, TC : O(no. of set bit) another way is to iterate through whole bit which'll have TC : O(nuOfBits)
int findNoOfSetBit(int num){
    int count = 0;
    while (num!=0){
        count++;
        num = (num&(num-1));
    }
    return count;
}
// Find the position of right most set bit
int findPos(int num){
    int pos = 0;
    while (num!=0){
        if ((num&1)==1){
            return pos;
        }
        pos++;
        num = num>>1;
    }
    return -1;
}


// Find nth magic number
int findMagic(int n){
    int bin = 0, nm = n;
    while (n!=0){
        bin = bin*10 + n%2;
        n = n/2;
    }
    int revBin = 0, magicNum = 0;
    while (nm!=0){
        revBin = revBin*10 + bin%10;
        bin = bin/10;
        nm /= 2;
    }
    int i=1;
    while (revBin!=0){
        magicNum += (revBin%10)*pow(5, i);
        revBin /= 10;
        i++;
    }
    return magicNum;
}
int findMagicN(int n){
    int magicNum=0, base=5;
    while (n!=0){
        magicNum += (n&1) * base;
        n = n>>1;
        base = base*5;
    }
    return magicNum;
}


// Find the sun of nth row in pascal triangle
int nRowSum(int n){
    return 1<<(n-1);
}

/* Given a number find it's power of two or not -> so a number will be power of 2 only & only if the bits of it has only one 
leading 1 e.g. 1000 is power of two whereas 1010 isn't power of two */
bool isPowerOf2(int num){
    if ((num&(num-1))==0 && num!=0){
        // as we do know n&(n-1) do remove last set bit, so as power of 2 has only one bit.. thus if it become 0 means it's has only one bit hence it's an power of two
        return true;
    }
    return false;
}


// calculate a to power b
int power(int a, int b){
    int ans = 1;
    while (b!=0){
        if ((b&1)==1){
            ans = ans * a;
        }
        a = a*a;    
        b = b>>1;
    }
    return ans;
}


// Find the XOR of number in the range 0->n
int XORuptoN(int n){
    int xorNum = 0;
    do{
        xorNum = xorNum ^ n;
    }while(n--);
    return xorNum;
}
// Another Solution : by oberving the pattern
int XORn(int n){
    if (n%4==0){
        return n;
    }
    else if (n%4==1){
        return 1;
    }
    else if (n%4==2){
        return n+1;
    }
    else if (n%4==3){
        return 0;
    }
    return -1;
}


// Find the XOR of all the numbers between a and b
int XORaTob(int a, int b){
    int XOR_0_a1 = XORn(a-1);   // finding the xor of numbers from 0 to a-1
    int XOR_0_b = XORn(b);  // xor of number from 0 to b
    return (XOR_0_b ^ XOR_0_a1);
    // as we do XOR of 0-a-1 with XOR from 0-b, as the XOR of 0-a-1 are in both(means two times) thus it'll get cancelled
}

// Find the number of bits we have to change to convert a number A to B
int findBit(int num1, int num2){
    int bitToChange = num1 ^ num2; // the number of ones it has -> by that many time we have to change the bits
    int count = 0;
    while (bitToChange!=0){
        if ((bitToChange&1)==1){
            count++;
        }
        bitToChange = bitToChange>>1;
    }
    return count;
}


// Find the two non-reapiting elements in an array where every element repeats twice
#include<vector>
void find2unique(int arr[], int size){
    int xorNum = arr[0];
    for (int i=1; i<size; i++){
        xorNum ^= arr[i];
    }
    vector<int> vec1;
    for(int i=0; i<size; i++){
        if ((arr[i]&1)==1){
            vec1.push_back(arr[i]);
        }
    }
    int fstUniq = 0;
    for(int i=0; i<vec1.size(); i++){
        fstUniq ^= vec1[i];
    }
    fstUniq = fstUniq ^ xorNum;
    cout<<"Unique No. : "<<fstUniq<<" "<<(fstUniq^xorNum)<<endl;
}


// find only non-repeating element in an array where every element repeats thrice -- will do it later....

int main(){
    checkEvenOdd(5);
    checkEvenOdd(10);

    int arr[9] = {2, 3, 4, 1, 2, 1, 3, 6, 4};
    cout<<findNum(arr, 9)<<endl;

    // Bit masking : 
    // find the 2 bit in number 7
    cout<<((7>>2)&1)<<endl;    // one way, right shift the number ith times and & it with 1
    cout<<(7&(1<<2))<<endl;    // sec way, left shift 1 ith time and & it with number
    // set the 3 bit of number 7
    cout<<(7|(1<<3))<<endl;
    // clear the 2 bit of number 7
    cout<<(7&(~(1<<2)))<<endl;

    // Find the number of bits we have to change to convert number 7 to 10
    cout<<findBit(7, 3)<<endl;

    // finding the first set bit :
    cout<<findPos(7)<<endl;

    // finding negative of number 13
    cout<<(~13)+1<<endl;
    //another way to find the complement is (~0)-number is similar as ~number
    cout<<((~0)-13)+1<<endl;

    cout<<"Number of Set Bit : "<<findNoOfSetBit(7)<<endl;
    cout<<findMagic(3)<<endl;
    cout<<findMagicN(5)<<endl;

    // Number of digit in base b of number n;
    int n=11, base=2;
    int digits = (log(n) / log(base)) + 1;
    cout<<digits<<endl;

    cout<<nRowSum(5)<<endl;
    cout<<isPowerOf2(1024)<<endl;
    cout<<isPowerOf2(328)<<endl;

    cout<<power(2, 5)<<endl;
    cout<<XORuptoN(2)<<endl;
    cout<<XORn(2)<<endl;

    cout<<XORaTob(3, 9)<<endl;

    // Finding two unique nu. in an array where every item is repeating twice
    int a[8] = {5, 4, 1, 4, 3, 5, 1, 2};
    find2unique(a, 8);
    return 0;
}