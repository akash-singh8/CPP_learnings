#include <iostream>
using namespace std;

/* How to Approach Pattern questions: 
    1. Run the outer forloop for the no. of row(lines of pattern) times.
    2. Identify the no. of columns and the type of elements in column for every rows(or the relationship between rows and columns), according 
    to that create another forloop.

*/


int main(){

    /*   1. *
            **
            ***
            ****
            *****      */
    for (int i=0; i<5; i++){
        for (int j=0; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }


    /*  2. *****
           ****
           ***
           **
           *                  */
    for (int i=0; i<5; i++){
        for (int j=0; j<5-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }


    /*  3. 1
           1 2
           1 2 3
           1 2 3 4
           1 2 3 4 5                  */
    for (int i=1; i<=5; i++){
        for (int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    /*  4. *
           **
           ***
           ****
           *****
           ****
           ***
           **
           *                    */
    for (int i=0; i<10; i++){
        int upto = (i<5)? i : 10-i;
        for (int j=0; j<upto; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    

    /*  5.      *
               **
              ***
             ****
            *****        */
    for (int i=0; i<5; i++){
        for (int j=0; j<5-i-1; j++){
            cout<<" ";
        }
        for (int k=0; k<=i; k++){
            cout<<"*";
        }
        cout<<endl;
    }


    /*  6.  *****
            ****
            ***
            **
            *            */
    for (int i=0; i<5; i++){
        for (int j=0; j<5-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }


    /*  7.      *
               ***
              *****
             *******
            *********        */
    for (int i=0; i<5; i++){
        for (int j=0; j<5-i-1; j++){
            cout<<" ";
        }
        for (int j=0; j<2*i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }


    /*  8.  *********
             *******
              *****
               ***
                *             */
    for (int i=0; i<5; i++){
        for (int j=0; j<i; j++){
            cout<<" ";
        }
        for (int k=0; k<9-(2*i); k++){
            cout<<"*";
        }
        cout<<endl;
    }


    /*  9.      *
               * *
              * * *
             * * * *
            * * * * *         */
    for (int i=0; i<5; i++){
        for (int j=0; j<5-i-1; j++){
            cout<<" ";
        }
        for (int k=0; k<=i; k++){
            cout<<"* ";   // just put the extra space in question 5
        }
        cout<<endl;
    }


    /*   10.  * * * * *
               * * * *
                * * *
                 * *
                  *             */
    for (int i=0; i<5; i++){
        for (int k=0; k<i; k++){
            cout<<" ";
        }
        for (int j=0; j<5-i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }


    /*  11. * * * * *
             * * * *
              * * *
               * *
                *
                *
               * *
              * * *
             * * * *
            * * * * *       */
    for (int i=1; i<=10; i++){
        int star = ( i <= 5 )? 5-i+1 : i-5; 
        int space = (i <= 5 )? i : 5-star+1;
        for (int j=1; j<space; j++){
            cout<<" ";
        }
        for (int k=1; k<=star; k++){
            cout<<"* ";
        }
        cout<<endl;
    }


    /*  13.     *
               * *
              *   *
             *     *
            *********        */
    for (int i=0; i<5; i++){
        if (i==4){
            for(int l=1; l<10; l++){
                cout<<"*";
            }
            break;
        }
        for (int j=0; j<5-i-1; j++){
            cout<<" ";
        }
        cout<<"*";
        for (int k=0; k<2*i-1; k++){
            cout<<" ";
        }
        if (i>0){
            cout<<"*";
        }
        cout<<endl;
    }
    
    
    cout<<"\n\n";
    /*  14.   *********
               *     *
                *   *
                 * *
                  *         */
    for (int i=1; i<=5; i++){
        for (int j=1; j<i; j++){
            cout<<" ";
        }
        if(i==1){
            for (int j=0; j<9; j++){
                cout<<"*";
            }
            cout<<endl;
            continue;
        }
        cout<<"*";
        for (int j=0; j<9-2*i; j++){
            cout<<" ";
        }
        if (i<5){
            cout<<"*\n";
        }
    }


    /*  15.      *
                * *
               *   *
              *     *
             *       *
              *     *
               *   *
                * *
                 *            */
    for (int i=0; i<9; i++){
        int space1 = (i < 5)? 4-i : i-4;
        for (int j=0; j<space1; j++){
            cout<<" ";
        }
        if (i>0 && i<8){
            cout<<"*";
        }
        int space2 = (i < 5)? 2*i-1 : 15-2*i; 
        for (int j=0; j<space2; j++){
            cout<<" ";
        }
        cout<<"*\n";
    }

    return 0;
}