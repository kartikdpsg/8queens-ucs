#include<bits/stdc++.h>
//#define endl '\n'
#define ll long long
using namespace std;

/*ll int power(ll int base,ll int exponent)
{
    if (exponent == 0) return 1;
    ll int temp = power(base, exponent/2);
    if (exponent % 2 == 0)
        return temp * temp;
    else
        return (base * temp * temp);
}*/

bool isSafe(int b[8][8], int r, int c)
{
    int i, j;
    for (i = 0; i < c; i++)
        if (b[r][i])
            return false;
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (b[i][j])
            return false;
    for (i = r, j = c; j >= 0 && i < 8; i++, j--)
        if (b[i][j])
            return false;
    return true;
}

bool solve(int b[8][8], int c)
{
    if (c >= 8) return true;
    for (int i = 0; i < 8; i++) {
        if (isSafe(b, i, c)) {
            b[i][c] = 1;
              if (solve(b, c + 1))
                return true;
            b[i][c] = 0;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,n,b[8][8] = {0};
    if(solve(b,0)==false){
        cout<<"No solution"<<endl;
    }
    else{
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
