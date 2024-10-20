#include<string>
#include<iostream>
using namespace std;

string itr_LCS(string a, int m, string b, int n)
{
    string LCS[m+2][n+2];
    for(int i=0;i<m+2;i++)
        LCS[i][0]="";
    for(int j=0;j<n+2;j++)
        LCS[0][j]="";
    for(int i=1;i<m+2;i++)
    {
        for(int j=1;j<n+2;j++)
        {
            if(a[i-1]==b[j-1])
            {
                LCS[i][j]=LCS[i-1][j-1]+a[i-1];
            }
            else
            {
                LCS[i][j]=(LCS[i-1][j].size()>LCS[i][j-1].size())?LCS[i-1][j]:LCS[i][j-1];
            }
        }
    }
    return LCS[m+1][n+1];
}

int main()
{
    string a,b;
    a = "dictacticaldictact";
    b = "advantageadvant";
    cout<<a+"\n"<<b+"\n"<<itr_LCS(a,a.size()-1,b,b.size()-1)<<endl;
}
