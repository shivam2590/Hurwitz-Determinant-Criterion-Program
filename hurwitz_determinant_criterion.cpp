#include <iostream>
#include<math.h>
using namespace std;

int determinant(int matrix[10][10], int n);
int main()
{

    //this part covers intilization
    int order;

    cout << "Enter The order of system: ";
    cin >> order;
    float Array[order + 1];
    for (int i = 0; i <= order; i++)
    {
        cin >> Array[i];
    }
    for (int i = 0; i <= order; i++)
    {
        cout << Array[i];
    }
    

    cout << endl;

    int H[order][order];

    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {

            H[i][j] = 0;
        }
    }
    for (int k = 0; k < order; k++)
    {
        for (int l = 0; l < order; l++)
        {
            cout << " "
                << H[k][l];
        }
        cout << endl;
    }

    int a, m;
    if (order % 2 == 0)
    {
        a = ((int)order / 2);
        m= (a + (a % 2));  //first change
        cout << "in if\n a="
            << a<<endl;
    }
    else
    {
        a = ((int)order / 2) + 1;
        m=(a + (a % 2) -1);
        cout << "in else\n a= "
            << a << endl<<endl;
    }

    for (int i = 0; i < a; i++)
    {

        for (int j = 0; j <=m; j++)
        {

            if (order % 2 == 0)
            {
                if ((j * 2 + 1) <= order)
                {

                    H[2 * i][j + i] = Array[2 * j + 1]; //odd
                }
                H[i * 2+1][j + i] = Array[(j * 2)]; //even
            }
            else
            {
                if (i == (a - 1)) //changes
                {
                    if ((j * 2 + 1) <= order)
                    {
                        H[2 * i][j + i] = Array[2 * j];
                    }
                }
                else
                {
                    if ((j * 2 + 1) <= order)
                    {
                        H[i * 2][j + i] = Array[(j * 2+ 1)];

                    }
                    H[2 * i + 1][j + i] = Array[2 * j];


                }
            }
        }
    }
    for (int k = 0; k < order; k++)
    {
        for (int l = 0; l < order; l++)
        {
            cout << " "
                << H[k][l];
        }
        cout << endl;
    }





    //matrix starts
    
    int extractedDeterminants[order];
    cout << "Determinant matrix: "<<endl;
    for (int i = 1; i <= order; i++)
    {
        if (i == 1)
        {
            extractedDeterminants[0] = H[0][0];
            cout<<"D1 = "<<extractedDeterminants[0]<<endl;

        }
        else if (i==2)
         {
            extractedDeterminants[1] = ((H[0][0] * H[1][1]) - (H[1][0] * H[0][1]));
            cout<< "D2 = "<<extractedDeterminants[1]<<endl;
                     }
        else {
            // copy a part from the main matrix
            int newMatrix[10][10];
            for (int k = 0; k < i; k++)
            {
                for (int l = 0; l < i; l++)
                {

                    newMatrix[k][l] = H[k][l];
                    cout<<" "<<newMatrix[k][l]; //change

                }
                cout<<endl;
                
            }
              
            extractedDeterminants[i-1] = determinant(newMatrix, i);
            cout<<"\nDeterminats D"<<i<<" "<<extractedDeterminants[i-1]<<endl;

        }
       // cout<<"\nDeterminats D"<<i<<" "<<extractedDeterminants[i]<<endl;
    }
}



int determinant(int matrix[10][10], int n) {
    int det = 0;
    int submatrix[10][10];
    
    if (n==2)
    {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}
