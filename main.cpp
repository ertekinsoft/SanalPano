#include <iostream>
#include <vector>
using namespace std;
vector<int> D;

int main()
{
int N,S,left,right,x;
long long cost = 0;
long long leftSum = 0;
long long rightSum = 0;
double leftW=0;
double rightW=0;
int gun = 1;
    cin>>N>>S;
    S = S-1;
    left=S;
    right=S;
    for(int i=0;i<N;i++){
        cin>>x;
        if(i<S){
            leftSum+=x;
        }else if(i>S){
            rightSum+=x;
        }
        D.push_back(x);
    }
    cost = D[S];
    gun = 1;
    N--;
    while(left>0||right<D.size()-1){
        rightW = left*rightSum;
        leftW = (N-right)*leftSum;
        gun++;
        if(rightW<leftW && left>0){
            left--;
            cost += gun*D[left];
            leftSum -= D[left];
        }else if(rightW>leftW && right<D.size()-1){
            right++;
            cost += gun*D[right];
            rightSum -= D[right];
        }else{

            if(left>0){
            left--;
            cost += gun*D[left];
            leftSum -= D[left];
            }else{
            right++;
            cost += gun*D[right];
            rightSum -= D[right];
            }
        }

    }
    cout<<cost;
    return 0;
}
