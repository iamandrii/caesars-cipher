#include <bits/stdc++.h>
using namespace std;
int main(){
	cout<<" => enter shift (any integer that fits int64 restrictions)"<<endl;
	long long shift;
	cin >> shift;
	cout<<" => enter mode (1 - only letters, 2 - all characters)"<<endl;
	int mode;
	cin >> mode;
	if(mode != 1 && mode != 2){
		cout<<" => wrong mode"<<endl;
		return -1;
	}
	if(mode == 1){
		shift = (shift%26 + 26)%26;
	}else{
		shift = (shift%95 + 95)%95;
	}
	cout<<" => enter *input* message file name"<<endl;
	string input;
	cin >> input;
	cout<<" => enter *output* message file name"<<endl;
	string output;
	cin >> output;
	ifstream fin(input.c_str());
	ofstream fout(output.c_str());	
	string message;
	while(getline(fin, message)){
		for(auto &i : message){
			if(mode == 1){
				if(i >= 'a' && i<='z'){i = 'a' + (i-'a'+shift)%26;}
				if(i >= 'A' && i<='Z'){i = 'A' + (i-'A'+shift)%26;}
			}else{
				i = ' '+(i-' '+shift)%95;
			}
		}
		fout << message << '\n';
	}

}
