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
    char a[100],temp;
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
            index[i]=rem/(fact(n)/fact(i+2));
            rem=rem%(fact(n)/fact(i+2));
        }

        for(i=1;i<n;i++)
        {
            index[i-1]=i-index[i-1];
        }
        cout << "\nFike's sequence : ";
        for(i=0; i<n-1; i++)
        {
            cout << index[i];
        }

        for(i=0; i<m-1; i++)
        {
            temp=a[i+1];
            a[i+1]=a[index[i]];
            a[index[i]]=temp;
            cout << "\n\nAfter swap : ";
            for(int j=0;j<m;j++)
            {
                cout << a[j];
            }
        }

        cout << "\n\nFike's order : ";
        for(i=0;i<m;i++)
        {
            cout << a[i];
        }

        cout << endl;
    }
    else
    {
        cout << "\nEnter a valid number for permutation !\n";
    }

    return 0;
}
