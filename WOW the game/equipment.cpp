/* A cpp program for mimic the game 'WOW'*/
/* This the part II of the program*/
/* The production of the warriors:
 * given the 
 * 1. first line: the number of test cases
 * 2. second line: an interger number, means the 
 *    value of the life source at the beginning.
 * 3. third line: five integers, means the initial 
 * 	  life value of 
 * 	  dragon, nijia, iceman, lion and wolf
 *
 * the order of red headquarter: iceman, lion, wolf, nijia, dragon
 * the order of blue headquarter: lion, dragon, nijia, iceman, wolf
 *
 * There are three types of equipments: sword, bomb and arrow
 * The three equipments No. are 0, 1, 2 respectively
 *
 * dragon can have one equipment, and the dragon with the No.n can
 * have No. n%3 equipment. It also has a morale value, which equals
 * to the remaining life strength it belongs to over the life strength 
 * of a single new dragon.
 *
 * nijia can have two equipments: No. n%3 and (n+1)%3
 *
 * iceman can have one equipment: No. n%3
 *
 * lion has the value of loyaty, which equals to the remaining life strength of
 * the headquarter it belongs to
 *
 * wolf has no additional features
 */

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<iomanip>

using namespace std;

class WOW{

  vector<int> redOrder;
  vector<int> redNumber;
  vector<string> redName;
  vector<int> blueOrder;
  vector<int> blueNumber;
  vector<string> blueName;

public:
  int l_dragon;
  int l_nijia;
  int l_iceman;
  int l_lion;
  int l_wolf;
 //constructor, initialize the red/blue headquarter product order and 
 //life strenth for each kind of worriors
  void wow(int a, int b, int c, int d, int e){
	  l_dragon=a;
	  l_nijia=b;
      l_iceman=c;
	  l_lion=d; 
	  l_wolf=e;      

	  redOrder.push_back(c);
	  redOrder.push_back(d);
	  redOrder.push_back(e);
	  redOrder.push_back(b);
	  redOrder.push_back(a);
		
	  redName.push_back("iceman");
	  redName.push_back("lion");
	  redName.push_back("wolf");
	  redName.push_back("nijia");
	  redName.push_back("dragon");

	  blueOrder.push_back(d);
	  blueOrder.push_back(a);
	  blueOrder.push_back(b);
	  blueOrder.push_back(c);
	  blueOrder.push_back(e);
		
	  blueName.push_back("lion");
	  blueName.push_back("dragon");
	  blueName.push_back("nijia");
	  blueName.push_back("iceman");
	  blueName.push_back("wolf");
	  for(int i=0;i<5;++i){
	      redNumber.push_back(0);
	      blueNumber.push_back(0);
	   }
	}
  /* The function to produce the warriors in the red headquarters */
  string redProduce(int &remain, int &b, int &time){
		int min = *min_element(redOrder.begin(), redOrder.end());
		if(remain < min){
		        cout<<setfill('0')<<setw(3)<<time-1
			    <<" red headquarter stops making warriors"<<endl;
			return "";
		}
		int len = redOrder.size();
		int i = b;
		string name;
		for(int Try=0; Try!=len; ++Try,i=(i+1)%len){
			if(remain >= redOrder[i]){
				redNumber[i]++;
				remain -= redOrder[i];
				name = redName[i];
				cout<<setfill('0')<<setw(3)<<time-1<<" red "<<redName[i]
					<<" "<<time<<" born with strength "
					<<redOrder[i]<<", "<<redNumber[i]<<" "<<redName[i]
					<<" in red headquarter"<<endl;
				break;
			}
		}
		b = (i+1)%len;
		time++;
		return name;
	}
  /* The function to produce the warriors in the blue headquarters */
  string blueProduce(int &remain, int &b, int &time){
		int min = *min_element(blueOrder.begin(), blueOrder.end());
		if(remain < min){
		        cout<<setfill('0')<<setw(3)<<time-1
			    <<" blue headquarter stops making warriors"<<endl;
			return "";
		}
		int len = blueOrder.size();
		int i = b;
		string name;
		for(int Try=0; Try!=len; ++Try,i=(i+1)%len){
			if(remain >= blueOrder[i]){
				blueNumber[i]++;
				remain -= blueOrder[i];
				name = blueName[i];
				cout<<setfill('0')<<setw(3)<<time-1<<" blue "<<blueName[i]
					<<" "<<time<<" born with strength "
					<<blueOrder[i]<<", "<<blueNumber[i]<<" "<<blueName[i]
					<<" in blue headquarter"<<endl;
				break;
			}
		}
		b = (i+1)%len;
		time++;
		return name;
	}
};

/*The class define the equipmens*/
class Equipment:public WOW{
	vector<string> equip;
	
public:
	Equipment(){
		equip.push_back("sword");
		equip.push_back("bomb");
		equip.push_back("arrow");
	}
	void Dragon(int time, int remain){
		cout<<"It has a "<<equip[time%3]<<", and it's morale is "
			<<(double)remain/l_dragon<<endl;
	}
	void Nijia(int time){
		cout<<"It has a "<<equip[time%3]<<" and a "<<equip[(time+1)%3]<<endl;
	}
	void Iceman(int time){
		cout<<"It has a "<<equip[time%3]<<endl;
	}
	void Lion(int remain){
		cout<<"It's loyalty is "<<remain<<endl;
	}	
};

 /* Given the certain total life strength to both of the red headquarter and
  * blue headquarter, out put the warriors production procedure for both sides.
  */
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i){
		int totalStrength;
		cin>>totalStrength;
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		cout<<"Case:"<<i<<endl;
		Equipment Red;
		Red.wow(a,b,c,d,e);
		Equipment Blue;
		Blue.wow(a,b,c,d,e);
		int redtotal(totalStrength), bluetotal(totalStrength);
		int redfirst(0), redtime(1),bluefirst(0),bluetime(1);
		int red_flag(0),blue_flag(0);
		string name;
		while(1){
		  if(red_flag && blue_flag)
		    break;
		  if(!red_flag){
		    	name = Red.redProduce(redtotal, redfirst, redtime);
		     	if(name == "")
					 red_flag = 1;
				else{
					if(name == "dragon") {Red.Dragon(redtime, redtotal);}
					if(name=="nijia") {Red.Nijia(redtime);}
					if(name=="iceman") {Red.Iceman(redtime);}
					if(name=="lion") {Red.Lion(redtotal);}
				}
			}
				
		  if(!blue_flag){
		  		name = Blue.blueProduce(bluetotal, bluefirst, bluetime);
				if(name == "")
					blue_flag = 1;
				else{
					if(name == "dragon") {Blue.Dragon(bluetime, bluetotal);}
					else if(name== "nijia") {Blue.Nijia(bluetime);}
					else if(name=="iceman") {Blue.Iceman(bluetime);}
					else if(name=="lion") {Blue.Lion(bluetotal);}
				}
			}
		}
	}
	return 0;
}
