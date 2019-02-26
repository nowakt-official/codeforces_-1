#include <bits/stdc++.h>

using namespace std;
int main(){
	string s;
	cin>>s;
	long long m = 0,cost =0;;
	int a,b;
	priority_queue<pair<int,int> >q;
	for(int i=0;i<s.size();i++){
		m --;
		if(s[i]=='(') m +=2;
		if(s[i] == '?'){
			s[i]=')';
			cin>>a>>b;
			q.push(make_pair(b-a,i));
			cost +=b;
		}
		if(m<0){
			if(q.empty()) break;
			pair<int,int> x = q.top();
			q.pop();
			s[x.second] = '(';
			cost -= x.first;
			m +=2;
		}
	}
	if(m!=0) {
		cout<<-1;
		return 0;
	}
	cout<<cost<<endl<<s;
}




