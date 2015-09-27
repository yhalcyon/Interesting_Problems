/* A cpp program for mimic the game 'WOW'*/
/* This the part I of the program*/
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
 */

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<iomanip>

using namespace std;

class WOW{

  int l_dragon;
  int l_nijia;
  int l_iceman;
  int l_lion;
  int l_wolf;
  vector<int> redOrder;
  vector<int> redNumber;
  vector<string> redName;
  vector<int> blueOrder;
  vector<int> blueNumber;
  vector<string> blueName;
public:
 //constructor, initialize the red/blue headquarter product order and strength
  // for each kind of worriors
  WOW(int a, int b, int c, int d, int e):l_dragon(a), l_nijia(b), l_iceman(c), l_lion(d), l_wolf(e){      
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
  bool redProduce(int &remain, int &b, int &time){
		int min = *min_element(redOrder.begin(), redOrder.end());
		if(remain < min){
		        cout<<setfill('0')<<setw(3)<<time-1
			    <<" red headquarter stops making warriors"<<endl;
			return false;
		}
		int len = redOrder.size();
		int i = b;
		for(int Try=0; Try!=len; ++Try,i=(i+1)%len){
			if(remain >= redOrder[i]){
				redNumber[i]++;
				remain -= redOrder[i];
				cout<<setfill('0')<<setw(3)<<time-1<<" red "<<redName[i]
					<<" "<<time<<" born with strength "
					<<redOrder[i]<<", "<<redNumber[i]<<" "<<redName[i]
					<<" in red headquarter"<<endl;
				break;
			}
		}
		b = (i+1)%len;
		time++;
		return true;
	}
  /* The function to produce the warriors in the blue headquarters */
  bool blueProduce(int &remain, int &b, int &time){
		int min = *min_element(blueOrder.begin(), blueOrder.end());
		if(remain < min){
		        cout<<setfill('0')<<setw(3)<<time-1
			    <<" blue headquarter stops making warriors"<<endl;
			return false;
		}
		int len = blueOrder.size();
		int i = b;
		for(int Try=0; Try!=len; ++Try,i=(i+1)%len){
			if(remain >= blueOrder[i]){
				blueNumber[i]++;
				remain -= blueOrder[i];
				cout<<setfill('0')<<setw(3)<<time-1<<" blue "<<blueName[i]
					<<" "<<time<<" born with strength "
					<<blueOrder[i]<<", "<<blueNumber[i]<<" "<<blueName[i]
					<<" in blue headquarter"<<endl;
				break;
			}
		}
		b = (i+1)%len;
		time++;
		return true;
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
		WOW Red(a,b,c,d,e);
		WOW Blue(a,b,c,d,e);
		int redtotal(totalStrength), bluetotal(totalStrength);
		int redfirst(0), redtime(1),bluefirst(0),bluetime(1);
		int red_flag(0),blue_flag(0);
		while(1){
		  if(red_flag && blue_flag)
		    break;
		  if(!red_flag)
		    if(!Red.redProduce(redtotal, redfirst, redtime))
		      red_flag = 1;
		  if(!blue_flag)
		    if(!Blue.blueProduce(bluetotal, bluefirst, bluetime))
		      blue_flag = 1;
		}
	}
	return 0;
}
