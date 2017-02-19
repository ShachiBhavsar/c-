/*#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>*/
#include <iostream>
/*#include <algorithm>
#include <unordered_map>*/

using namespace std;
class aStack
{
         int top;
    int a[100000];
    public:
        aStack()
            {
            top=-1;
        }
        void push(int x)
            {
            a[++top]=x;
        }
        void pop()
            {
            top--;
        }

        int tp()
            {
            return(a[top]);
        }

};

int main(){
    int n1;
    int n2;
    int n3;
    int ans;
    cin >> n1 >> n2 >> n3;
    aStack s1,s2,s3,sum1,sum2,sum3;
    int h1[n1]={0};
    for(int i = 0;i < n1;i++){
       cin >> h1[i];
    }
    int h2[n2]={0};
    for(int i = 0;i < n2;i++){
       cin >> h2[i];
    }
    int h3[n3]={0};
    for(int i = 0;i < n3;i++){
       cin >> h3[i];
    }
    for(int i = n1-1;i >=0;i--){
        s1.push(h1[i]);
        sum1.push(h1[i]+sum1.tp());
        //cout<<sm1.tp()<<" ";
    }
    for(int i = n2-1;i >=0;i--){
        s2.push(h2[i]);
        sum2.push(h2[i]+sum2.tp());
        //cout<<sm2.tp()<<" ";
    }
    for(int i = n3-1;i >=0;i--){
        s3.push(h3[i]);
        sum3.push(h3[i]+sum3.tp());
        //cout<<sm3.tp()<<" ";
    }
    while(1)
    {
        if(sum1.tp()==sum2.tp())
            {
            if(sum1.tp()==sum3.tp())
            {
                ans=sum1.tp();
                break;
            }
            else if(sum1.tp()>sum3.tp())
            {
                sum1.pop();
                sum2.pop();
            }
            else
                sum3.pop();

        }
        else if(sum1.tp()>sum2.tp())
            {
                if(sum1.tp()>sum3.tp())
                    sum1.pop();
                else if(sum1.tp()==sum3.tp())
                    {
                    sum3.pop();
                    sum1.pop();
                }
                else
                    sum3.pop();

        }
        else
            {
            if(sum2.tp()>sum3.tp())
                sum2.pop();
            else if(sum2.tp()==sum3.tp())
                {
                sum2.pop();
                sum3.pop();
            }
            else
                sum3.pop();
        }
    }
    cout<<ans;
    return 0;
}

