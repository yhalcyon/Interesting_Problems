#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

class MixSort{
private:
	vector<string> split_string(string s){
		int len = s.length();
		string tmp("");
		vector<string> result;
		for(int i = 0; i<len; ++i){
			if(s[i] != ' ')
				tmp += s[i];
			if(s[i]==' ')
				if(tmp != ""){
					result.push_back(tmp);
				//	cout<<tmp<<endl;
					tmp = "";
				}
		}
		if(tmp != "")
			result.push_back(tmp);
			//cout<<tmp<<endl;
		return result;
	}
	bool isNumber(string s){
		if(s[0]>='0' && s[0]<='9')
			return true;
		else 
			return false;
	}
	int strToInt(string s){
		int result(0), len = s.length();
		for(int i=len-1; i>=0; --i)
			result += (s[i]-'0')*pow(10,len-1-i);
		return result;
	}			
	string intToStr(int n){
		string result("");
		if(n==0) return "0";
		while(n){
			result = (char)(n%10+'0') + result;
			n /= 10;
		}
		return result;
	}
		
public:
	string mixSort(string s){
		string result="";
		int i, len=s.length();
		vector<string> s_sep, words;
		vector<int> elementType, integers;
		s_sep = split_string(s);
		for(i=0;i<s_sep.size();++i){
			if(isNumber(s_sep[i])){
				elementType.push_back(0);
				integers.push_back(strToInt(s_sep[i]));
			}
			else{
				elementType.push_back(1);
				words.push_back(s_sep[i]);
			}
		}
		sort(integers.begin(), integers.end());
		sort(words.begin(), words.end());
		int pwords(0), pintegers(0);
		for(i=0;i<s_sep.size();++i){
			if(!elementType[i]){
				result += " "+intToStr(integers[pintegers]);
				pintegers++;
			}
			else{
				result += " "+words[pwords];
				pwords++;
			}
		}
		return result.substr(1);
	}
};

int main(){
	MixSort A;
/*	int n;
	cin>>n;
	string s, result;
	for(int i=0;i<n;++i){
		string tmp;
		cin>>tmp;
		s += " " + tmp;
	}
	s=s.substr(1);
*/
	string s, result;
	getline(cin,s);
	//cout<<s<<endl;
	result = A.mixSort(s);
	cout<<result<<endl;
	
	return 0;
}
