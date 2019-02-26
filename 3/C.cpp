#include<bits/stdc++.h>

using namespace std;
char a[3][3];
bool isWinner(char c){
	for(int i=0;i<3;i++){
		if(a[i][0]==c && a[i][1]==c && a[i][2]==c) return true;
		if(a[0][i]==c && a[1][i]==c && a[2][i]==c) return true;
	}
	if(a[0][0]==c && a[1][1]==c && a[2][2]==c) return true;
	if(a[0][2]==c && a[1][1]==c && a[2][0]==c) return true;
	return false;
}
bool wo=false,wx=false;
int no,nx;
int main(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(a[i][j]=='0') no++;
			if(a[i][j]=='X') nx++;
		}
	}
	wo = isWinner('0');
	wx = isWinner('X');
	//cout<<wo << " " << wx<< " " << no << " "<< nx<<endl;
	if((wx && nx!=no+1)||(wo && nx!=no)||(nx!=no+1&&nx!=no)){
		cout<<"illegal";
		return 0;
	}
	if(wx){
		cout<<"the first player won";
		return 0;
	}
	if(wo){
		cout<<"the second player won";
		return 0;
	}
	if(no + nx == 9 ) {
		cout<<"draw";
		return 0;
	}
	if(no == nx){
		cout<<"first";
		return 0;
	}
	cout<<"second";
	return 0;
}
