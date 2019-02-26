#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,time;
	cin>>n>>time;
	pair<int,int> t[n];
	int mini = 0, maki = 0;
	for(int i=0;i<n;i++) {
		cin>>t[i].first>>t[i].second;
		mini +=t[i].first;
		maki +=t[i].second;
	}
	if (time<mini || time>maki) {
		cout<< "NO";
		return 0;
	}
	cout<<"YES\n";
	for(int i=0;i<n;i++) {
		//cout<< endl << mini << " " << maki<< " " << time << endl;
		//mini -= t[i].first;
		maki -= t[i].second;
		int zm = min(t[i].second,t[i].first + time - mini);
		mini -= t[i].first;
		time -= zm;
		cout<< zm << " ";
	}
}
		

