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
    char a[100],revlexi[100];
    int index[100];

    cout << "\nEnter the word : ";
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }

    cout << "\nWhich permutation of the word/number do you want? : ";
    cin >> k;

     if(k<=fact(n)&&k>=1)
    {
        k-=1;
        rem=k;

        for(i=0; i<n-1; i++)
        {
            index[i]=rem/fact(n-i-1);
            rem=rem%fact(n-i-1);
        }

        cout << "\nLexicographical sequence : ";
        for(i=0; i<n-1; i++)
        {
            cout << index[i];
        }


        cout << "\n\nReverse lexicographical order : ";
        for(i=0;i<m/2;i++)
        {
            int temp=a[i];
            a[i]=a[n-i-1];
            a[n-i-1]=temp;
        }

        for(i=0; i<m; i++)
        {
            revlexi[i]=a[index[i]];

            for(k=index[i]; k<n-1; k++)
            {
                a[k]=a[k+1];
            }
            n=n-1;

            if(n==1)
            {
                revlexi[m-1]=a[0];
                break;
            }
        }
        for(i=0;i<m/2;i++)
        {
            int temp=revlexi[i];
            revlexi[i]=revlexi[m-i-1];
            revlexi[m-i-1]=temp;
        }

        for(i=0;i<m;i++)
        {
            cout << revlexi[i];
        }
        cout << endl;
    }
    else
    {
        cout << "\nEnter a valid number for permutation !\n";
    }
    return 0;
}

