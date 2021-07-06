#include<bits/stdc++.h>
#include<climits>
using namespace std;
class A{
    public:
	int ship(int weights[], int n, int D) {
        if(n <= 0)
		return 0;
        int unit = 0;
        if(n % D == 0){
            unit = n/D;
        }else{
            unit = n/D+1;
        }
        int max = 0;
        int first;
        for(int i = 0; i < n && i+unit-1<n;i++){
            first = 0;
            for(int j = 0; j < unit;j++){
                first += weights[i+j];
            }
            if(first > max)max = first;
        }
        int maxValue = 0;
        for(int i = 0; i<n;i++){
            if(weights[i] > maxValue){
                maxValue = weights[i];
            }
        }
        int temp = max -1;
        int days;
        bool flag = true;
        int sum;
        while(flag && temp >= maxValue){
            days = 0;
            sum = 0;
            for(int i = 0; i < n; i++){
                sum += weights[i];
                if(sum > temp){
                    days++;
                    sum = weights[i];
                }else if(sum == temp){
                    days++;
                    sum = 0;
                }
            }
            if(sum > 0)days++;
            if(days > D) flag = false;
            else{
                temp--;
            }
        }
        return temp + 1;
    }
};
int main()
{
	A a;
	int n, days = 5, arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	n = sizeof(arr)/sizeof(arr[0]);
	cout<<a.ship(arr,n,days);
	return 0;
}
