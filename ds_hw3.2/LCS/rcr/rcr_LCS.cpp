#include<string>
#include<iostream>
using namespace std;

string rcr_LCS(string a,int n, string b, int m)
{
    if(n==-1||m==-1)
    {
        return "";
    }
    else if(a[n]==b[m])
    {

        return rcr_LCS(a,n-1,b,m-1) + a[n];
    }
    else
    {
        string LCS_0 = rcr_LCS(a,n-1,b,m);
        string LCS_1 = rcr_LCS(a,n,b,m-1);
        return (LCS_0.size()>LCS_1.size())?LCS_0:LCS_1;
    }
}

int main()
{
    string a,b;
    a = "dictacticaldictact";
    b = "advantageadvant";
    cout<<a+"\n"<<b+"\n"<<rcr_LCS(a,a.size()-1,b,b.size()-1)<<endl;
}