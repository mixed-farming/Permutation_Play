#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int fact(int x)
{
    int factorial=1;
    for(int j=x; j>0; j--)
    {
        factorial*=j;
    }
    return factorial;
}

int main()
{
    int n,k,i,m,rem;
    cout << "Enter the number of characters in the word/number : ";
    cin >> n;
    m=n;
    char a[100];
    int index[100];

    cout << "\nEnter the word : ";
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }

    cout << "\nWhich permutation of the word/number do you want? : ";
    cin >>k;

    if(k<=fact(n)&&k>=1)
    {
        k-=1;
        rem=k;

        for(i=0; i<n-1; i++)
        {
            index[i]=rem/fact(n-i-1);
            rem=rem%fact(n-i-1);
        }

        cout << "\nLexicographical index : ";
        for(i=0; i<n-1; i++)
        {
            cout << index[i];
        }


        cout << "\n\nLexicographical order : ";
        for(i=0; i<m; i++)
        {
            cout << a[index[i]];

            for(k=index[i]; k<n-1; k++)
            {
                a[k]=a[k+1];
            }
            n=n-1;

            if(n==1)
            {
                cout << a[0];
                break;
            }
        }
        cout << endl;
    }
    else
    {
        cout << "\nEnter a valid number for permutation !\n";
    }

    return 0;
}
