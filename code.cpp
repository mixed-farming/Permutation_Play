#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int fact(int x)//factorial function
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
    char choice;
    int n,k,i,m,rem;
    char a[100],revlexi[100],temp;//string array
    int index[100];//lexicographical index order array
    while(1)
    {
        cout << "Enter your choice number : \n";
        cout << "1)Lexicographical order\n2)Reverse Lexicographical order\n3)Fike's order\n4)Exit\n";
        cout << "Your choice : ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "\nEnter the number of characters in the word/number : ";
            cin >> n;
            m=n;
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

                cout << "\nLexicographical index : ";

                for(i=0; i<n-1; i++)
                {
                    cout << index[i];
                }


                cout << "\n\nLexicographical order : ";

                for(i=0; i<m; i++)
                {
                    cout << a[index[i]];
                    //removing the printed element

                    for(k=index[i]; k<n-1; k++)
                    {
                        a[k]=a[k+1];//shift the elements to left
                    }

                    n=n-1;//decrement the count of no of elements

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

            cout << "\n\n*************************\n\n";
            break;


        case '2':
            cout << "\nEnter the number of characters in the word/number : ";
            cin >> n;
            m=n;
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

                for(i=0; i<m/2; i++)
                {
                    int temp=a[i];
                    a[i]=a[n-i-1];
                    a[n-i-1]=temp;
                }

                for(i=0; i<m; i++)
                {
                    revlexi[i]=a[index[i]];
                    //removing the printed element

                    for(k=index[i]; k<n-1; k++)
                    {
                        a[k]=a[k+1];//shift the elements to left
                    }

                    n=n-1;//decrement the count of no of elements

                    if(n==1)
                    {
                        revlexi[m-1]=a[0];
                        break;
                    }
                }

                for(i=0; i<m/2; i++)
                {
                    int temp=revlexi[i];
                    revlexi[i]=revlexi[m-i-1];
                    revlexi[m-i-1]=temp;
                }

                for(i=0; i<m; i++)
                {
                    cout << revlexi[i];
                }

                cout << endl;
            }
            else
            {
                cout << "\nEnter a valid number for permutation !\n";
            }

            cout << "\n\n*************************\n\n";
            break;


        case '3':
            cout << "\nEnter the number of characters in the word/number : ";
            cin >> n;
            m=n;
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

                for(i=1; i<n; i++)
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

                    for(int j=0; j<m; j++)
                    {
                        cout << a[j];
                    }

                }

                cout << "\n\nFike's order : ";

                for(i=0; i<m; i++)
                {
                    cout << a[i];
                }

                cout << endl;
            }
            else
            {
                cout << "\nEnter a valid number for permutation !\n";
            }

            cout << "\n\n*************************\n\n";
            break;


        case '4':
            exit(0);

            break;


        default:
            cout << "\nEnter proper choice !\n";

        cout << "\n\n*************************\n\n";
        }
    }

    return 0;
}
