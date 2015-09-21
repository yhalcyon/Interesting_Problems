#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

class strClean{
public:
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
					tmp = "";
				}
		}
		if(tmp != "")
			result.push_back(tmp);
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
		
};

int main(){
	strClean A;
	cout<<"input:"<<endl;
	int n;
	cin>>n;
	string stmp;
	getline(cin,stmp);
	//cout<<"the number of dataset is:"<<n<<endl;
	vector< vector<int> > data(n,vector<int>(0));
	set<int> totalData;
	for(int i=0;i<n;++i){
		string str;
		getline(cin,str);
		vector<string> s;
		s = A.split_string(str);
		int len = s.size(),tmp;
		for(int j=1;j<len;++j){
			tmp = A.strToInt(s[j]);
			data[i].push_back(tmp);
			totalData.insert(tmp);
		}
	}
	
	set<int>::iterator it;
	cout<<"output:"<<endl;
	for(it=totalData.begin();it!=totalData.end();++it){
		for(int j=0; j<n; j++){
			if(find(data[j].begin(),data[j].end(),*it)==data[j].end()){
				for(int k=0; k<n; ++k){
					if(find(data[k].begin(),data[k].end(),*it)!=data[k].end()){
						cout<<*it<<' '<<k+1<<' '<<j+1<<endl;
						break;
					}
				}
			}
		}
	}
	cout<<"done"<<endl;	
	return 0;
}
