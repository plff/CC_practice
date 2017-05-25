#include <iostream>

using namespace std;

int main () {
	int T,n,s;
	int a[100], p[100];
	double subs[10000] = {0};
	double pr;
	cin >> T;
	while(T--){
		pr=0;
		cin >> n;
		for (int i =0; i<n;i++) cin>>a[i];
		for (int i =0; i<n;i++) cin>>p[i];	
		s=a[0];
		subs[a[0]] = p[0];
		subs[0] = 100-p[0];
		for (int i=1;i<n;i++){
			s+=a[i];
			for (int j=s; j>=0;j--){
				if (j>=a[i]) subs[j] = (subs[j]*(100-p[i]) + subs[j-a[i]]*p[i])/100;
				else subs[j] = subs[j]*(100-p[i])/100; 
			}
		}
		for (int i = s; i>=(s+1)/2;i--) pr+=subs[i];
		cout << pr/100 <<endl;
		for (int i =0;i<=s;i++) subs[i] = 0;
	}

}