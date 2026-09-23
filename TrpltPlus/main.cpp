/**
 * Project : TrpltPlus
 * Author : HaneDaniko
 * Version : demo
 */
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define cls system("cls")
const int sye=0xE0,sgre=0xA0,sgra=0x08,swh=0x0F,sli=0xF0;
int yellow=0xE0,green=0xA0,gray=0x08,white=0x0F,light=0xF0;
void scbc(char put,int color){
	if(color==-1) return;
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,color==0?white:color);
	cout<<put<<" ";
	SetConsoleTextAttribute(handle,white);
}
void scbc(string put,int color){
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,color==0?white:color);
	cout<<put;
	SetConsoleTextAttribute(handle,white);
}
#define colorp(x,i) scbc(x,((step==3 or step==11 or step==i)?white:gray))
void print_startpage(){
    cls;
    cout<<"          TrpltPuls          "<<endl;
    cout<<"     Press S to continue     "<<endl;
    cout<<                                 endl;
    cout<<"         Copyright HaneDaniko"<<endl;
}
void startpage(){
    print_startpage();
    while(1){
		if(kbhit()){
			int a=getch();
            if(a=='s') break;
        }
    }
}
/* -- TOPASS -- */
namespace hdk{
	namespace topass{
		class topass{public:int h=0;std::string version="1.0";}topass;
		std::string lock(int public_key,int private_key,std::string word){
			int now=public_key;
			for(int i=0;i<=(int)word.length()-1;++i){
				if(!now) now=public_key;
				if(now&1){
					word[i]^=(private_key+now%8);
				}
				now>>=1;
			}
			std::string ans;
			for(int i=0;i<=(int)word.length()-1;++i){
				if(word[i]<100){
					ans.push_back('0');
					ans.push_back(word[i]/10+'0');
					ans.push_back(word[i]%10+'0');
				}
				else{
					ans.push_back(word[i]/100+'0');
					ans.push_back((word[i]%100)/10+'0');
					ans.push_back(word[i]%10+'0');
				}
			}
			for(int i=1;i<=3;++i)
			ans.push_back('0');
			return ans;
		}
		std::string unlock(int public_key,int private_key,std::string password){
			int now=public_key;std::string ans;
			for(int i=0;i+2<=(int)password.length()-1;i+=3){
				int a=(password[i]-'0')*100+(password[i+1]-'0')*10+(password[i+2]-'0');
				if(a){
					if(!now) now=public_key;
					if(now&1) ans.push_back(a^(private_key+now%8));
					else ans.push_back(a);
					now>>=1;
				}
			}
			return ans;
		}
	}
}
int menuselect;
namespace menulist{
    struct lis{
        string levelname;
        bool islocked;
    };
    const int MAX_MENU=11;
    vector<lis> menuitem={
        {},
        {"Tutorial 1",false},
        {"Level 1",false},
        {"Level 2",true},
        {"Level 3",true},
        {"Level 4",true},
        {"Level 5",true},
        {"Level 6",true},
        {"Level 7",true},
        {"Level 8",true},
        {"Level 9",true},
        {"Level 10",true}
    };
}
void printmenu(){
    system("cls");
    cout<<"Level Selection"<<endl;
    scbc("Use 'Up' and 'Down' to select",gray);
    cout<<endl<<endl;
    for(int i=1;i<=menulist::MAX_MENU;++i){
        scbc(menulist::menuitem[i].levelname,(menuselect==i?light:white));
        if(menulist::menuitem[i].islocked==true){
            cout<<" ";scbc("Locked",gray);
        }
        cout<<endl;
    }
}
namespace levelinfo{
    vector<vector<int>> info={
        {},{},
        {3,3,3,
            1,1,
            1,1,
            1,1,
            1,1,
            1,1,
            0,0,1},
        {10,2,2,
            1,1,
            1,1,
            1,1,
            1,1,
            1,0,
            0,1,1,2,2,2,2,3,4,5},
        {10,0,0,
            1,0,
            0,1,
            2,2,
            2,2,
            2,2,
            0,0,0,0,0,0,1,1,2,3},
        {10,13,13,
            4,3,
            3,4,
            1,0,
            0,4,
            7,3,
            0,1,1,1,1,1,2,2,2,3},
        {10,13,14,
            4,3,
            3,4,
            1,0,
            0,4,
            7,4,
            0,1,1,1,1,1,2,2,2,3},
        {4,3,3,
            2,1,
            1,2,
            1,0,
            0,1,
            1,1,
            0,1,2,3},
        {30,12,12,
            3,2,
            2,3,
            7,9,
            9,7,
            12,12,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2},
        {30,12,12,
            3,2,
            2,3,
            7,9,
            9,7,
            12,12,
            0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2},
        {10,10,10,
            1,0,
            0,1,
            1,0,
            0,1,
            1,0,
            0,5,5,11,11,24,24,49,60,70},
        {30,0,10,
            0,0,
            999,0,
            0,10,
            0,50,
            0,10,
            0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
    };
}
//basic:
//079101118101111081101099111113103045067111115122114105103107119084114112111119080108117112046072097110102071097110105104108045086101113112105111110072102121048100069053086045053101081051101045115058089082052046103101113050083000
string levelstatues="LevelRecord-CopyrightTrpltPlus-HaneDaniko-VersionKey0dF6V-5fR3e-p9YR4-deq2P";
void filestore(){
    ofstream output("trplt.info");
    for(int i=1;i<=menulist::MAX_MENU;++i){
        if(menulist::menuitem[i].islocked==true){
            output<<hdk::topass::lock(17,i-1,levelstatues);
            output.close();
            return;
        }
    }
    output<<hdk::topass::lock(17,menulist::MAX_MENU,levelstatues);
    output.close();
}
void fileread(){
    ifstream input("trplt.info");
    string x;input>>x;input.close();
    int flag=2;
    for(int i=1;i<=menulist::MAX_MENU;++i){
        if(hdk::topass::unlock(17,i,x)==levelstatues){
            flag=i;
            for(int j=1;j<=i;++j){
                menulist::menuitem[j].islocked=false;
            }
            break;
        }
    }
    if(flag>2){
        scbc("Your level progress has been restored.",gray);cout<<endl;
        scbc("Press Enter to continue.",gray);cout<<endl;
        while(1){
            if(kbhit()){
                int a=getch();
                if(a==13){
                    break;
                }
            }
        }
    }
}
namespace games{
    int tot_days;
    int day=0;
    vector<int>req;
    int minyl,minyg;
    struct{
        int remainyf;
        int remainyg;
    }self;
    struct{
        int cnt;
        int costyf;
        int costyg;
    }root;
    struct{
        int cnt;
        int costyf;
        int costyg;
    }high;
    struct{
        int cnt;
        int costyf;
        int costyg;
    }leaf;
    struct{
        int cnt;
        int costyf;
        int costyg;
    }wcgz;
    struct{
        int cnt;
        int costyf;
        int costyg;
    }csgz;
    void clear(){
        day=0;
        self.remainyf=self.remainyg=0;
        root.cnt=0;root.costyf=root.costyg=1;
        high.cnt=0;high.costyf=high.costyg=1;
        leaf.cnt=0;leaf.costyf=leaf.costyg=1;
        wcgz.cnt=0;wcgz.costyf=wcgz.costyg=1;
        csgz.cnt=0;wcgz.costyf=wcgz.costyg=1;
        req.clear();
    }
    void tutorialprint(int step){
        system("cls");
        cout<<"Tutorial"<<endl<<endl;
        if(step==1){
            cout<<"Welcome to Trplt"<<endl<<endl;
        }
        if(step==2){
            cout<<"You are a little tree growing in a beautiful garden."<<endl;
            cout<<"Because the owner likes apples, you need to produce apples, or you'll be replaced by other apple trees."<<endl<<endl;
        }
        if(step==3){
            cout<<"In this game, you need to choose your survival strategy. Use limited resources to grow. And finally meet the owner's apple needs after days"<<endl<<endl;
        }
        if(step==3){
            cout<<"Here's the game interface"<<endl<<endl;
        }
        if(step==4){
            cout<<"This is the remaining days of game."<<endl<<endl;
        }
        if(step==5){
            cout<<"These are your current status."<<endl;
            cout<<"'Now Height' is your height. You need to grow higher before you grow out leaves or apples."<<endl;
            cout<<"Precisely, if you are [x] m high, then you can grow at most [x] leaves and [x] apples"<<endl<<endl;
        }
        if(step==6){
            cout<<"These are your current status."<<endl;
            cout<<"'Fertilizer' and 'Sunlights' is the number of Fertilizer/Sunlights you have."<<endl;
            cout<<"Fertilizer and Sunlights is used when you grow any part of yourself."<<endl<<endl;
        }
        if(step==7){
            cout<<"These are your current status."<<endl;
            cout<<"You can grow your 'Root' and 'Leaf'. They could help you grow faster."<<endl;
            cout<<"Precisely, if you have [x] root and [y] leaves, then when you go to next day, you will get [x]+1 Fertilizer and [y]+1 Sunlights."<<endl<<endl;
        }
        if(step==8){
            cout<<"These are your current status."<<endl;
            cout<<"You can grow apples, and apples need more Fertilizer/Sunlights to grow and heavested"<<endl;
            cout<<"Your game goal is to collect a certain number of apples."<<endl<<endl;
        }
        if(step==9){
            cout<<"These are operations that you can do."<<endl;
            cout<<"Most operations need Fertilizer/Sunlights. It can't be done when Fertilizer/Sunlights aren't enough."<<endl<<endl;
        }
        if(step==10){
            cout<<"These are owner's requests for 'Heavested Apples'"<<endl;
            cout<<"You must meet these requests everyday, or you'll lost the game."<<endl<<endl;
        }
        if(step==11){
            cout<<"Now Input '5' to do the Operation 5, and start your game journey."<<endl<<endl;
        }
        if(step>=3){
            colorp("[Day 1/3 ]",4);cout<<endl<<endl;
            colorp("[Now Height: 0 m ]",5);cout<<endl;
            scbc("[Have]",gray);cout<<endl;
            colorp("Fertilizer: 3",6);cout<<endl;
            colorp("Sunlights: 3",6);cout<<endl<<endl;
            scbc("[Status]",gray);cout<<endl;
            colorp("Root 0",7);cout<<endl;
            colorp("Leaf 0",7);cout<<endl;
            colorp("Apple 0",8);cout<<endl;
            colorp("Heavested apple 0",8);cout<<endl<<endl;
            scbc("[Action Cost]",gray);cout<<endl;
            colorp("[1] new Root : 1 Fertilizer & 1 Sunlights\n\
[2] new Leaf :  { Lacking Height: Need at least 1 m }\n\
[3] new Apple :  { Lacking Height: Need at least 1 m }\n\
[4] Heavest an apple :  { Lacking Apple: Need at least 1 apple }\n\
[5] Add height : 1 Fertilizer & 1 Sunlights\n\
[6] Goto next day : You will Get 1 Fertilizer & 1 Sunlights",9);
            cout<<endl<<endl;
            scbc("[Farmer Request]",gray);cout<<endl;
            colorp("[Day 1 request] 0\n\
[Day 2 request] 0\n\
[Day 3 request] 1",10);
            cout<<endl;
        }
        if(step<=10) scbc("Press Enter to continue",gray);
        else{
            scbc("Enter a '5' to start your operation",gray);cout<<endl;
            int x;
            while(cin>>x){
                if(x==5){
                    cout<<endl;scbc("You've learned all of the game. Have a good time.",light);cout<<endl;
                    scbc("Press Enter to end.",gray);
                    break;
                }
                else{
                    scbc("Oh, you have to enter a '5'.",gray);cout<<endl;
                }
            }
            while(1){
                if(kbhit()){
                    int a=getch();
                    if(a==13){
                        break;
                    }
                }
            }
        }
    }
    void print(){
        cout<<"[ Day "<<day<<"/"<<tot_days<<" ]"<<endl<<endl;
        cout<<"[Now Height: "<<high.cnt<<" m ]"<<endl;
        scbc("[Have]",gray);cout<<endl;
        cout<<"Fertilizer: "<<self.remainyf<<endl;
        cout<<"Sunlights: "<<self.remainyg<<endl<<endl;
        scbc("[Status]",gray);cout<<endl;
        cout<<"Root "<<root.cnt<<endl;
        cout<<"Leaf "<<leaf.cnt<<endl;
        cout<<"Apple "<<wcgz.cnt<<endl;
        cout<<"Heavested apple "<<csgz.cnt<<endl<<endl;
        scbc("[Action Cost]",gray);cout<<endl;
        cout<<"[1] new Root : "<<root.costyf<<" Fertilizer & "<<root.costyg<<" Sunlights"<<endl;
        cout<<"[2] new Leaf : ";
        if(high.cnt<=leaf.cnt) cout<<" { Lacking Height: Need at least "<<leaf.cnt+1<<" m }"<<endl;
        else cout<<leaf.costyf<<" Fertilizer & "<<leaf.costyg<<" Sunlights"<<endl;
        cout<<"[3] new Apple : ";
        if(high.cnt<=wcgz.cnt+csgz.cnt) cout<<" { Lacking Height: Need at least "<<wcgz.cnt+csgz.cnt+1<<" m }"<<endl;
        else cout<<wcgz.costyf<<" Fertilizer & "<<wcgz.costyg<<" Sunlights"<<endl;
        cout<<"[4] Heavest an apple : ";
        if(wcgz.cnt==0) cout<<" { Lacking Apple: Need at least 1 apple }"<<endl;
        else cout<<csgz.costyf<<" Fertilizer & "<<csgz.costyg<<" Sunlights"<<endl;
        cout<<"[5] Add height : "<<high.costyf<<" Fertilizer & "<<high.costyg<<" Sunlights"<<endl;
        cout<<"[6] Goto next day : You will Get "<<1+root.cnt<<" Fertilizer & "<<1+leaf.cnt<<" Sunlights ";
        if(csgz.cnt<req[day]) cout<<" [you will lost if you goto next day, need to add "<<req[day]-csgz.cnt<<" heavest apple]";
        cout<<endl<<endl;
        scbc("[Farmer Request]",gray);cout<<endl;
        for(int i=day;i<=tot_days;++i){
            cout<<"[Day "<<i<<" request] "<<req[i]<<endl;
        }
    }
    vector<int>operat;
    void readinfo(int id){
        minyl=0x7fffffff,minyg=0x7fffffff;
        tot_days=levelinfo::info[id][0];
        self.remainyf=levelinfo::info[id][1];
        self.remainyg=levelinfo::info[id][2];
        self.remainyf--;self.remainyg--;
        root.costyf=levelinfo::info[id][3];
        root.costyg=levelinfo::info[id][4];
        minyl=min(minyl,root.costyf);
        minyg=min(minyg,root.costyg);
        leaf.costyf=levelinfo::info[id][5];
        leaf.costyg=levelinfo::info[id][6];
        minyl=min(minyl,leaf.costyf);
        minyg=min(minyg,leaf.costyg);
        wcgz.costyf=levelinfo::info[id][7];
        wcgz.costyg=levelinfo::info[id][8];
        minyl=min(minyl,wcgz.costyf);
        minyg=min(minyg,wcgz.costyg);
        csgz.costyf=levelinfo::info[id][9];
        csgz.costyg=levelinfo::info[id][10];
        minyl=min(minyl,csgz.costyf);
        minyg=min(minyg,csgz.costyg);
        high.costyf=levelinfo::info[id][11];
        high.costyg=levelinfo::info[id][12];
        minyl=min(minyl,high.costyf);
        minyg=min(minyg,high.costyg);
        req.clear();req.push_back(0);
        for(int i=1;i<=tot_days;++i){
            int x=levelinfo::info[id][12+i];req.push_back(x);
        }
    }
    bool next_day(){
        day++;
        self.remainyg+=1+leaf.cnt;
        self.remainyf+=1+root.cnt;
        if(day>tot_days) return true;
        return false;
    }
    void maint(int id){
        clear();
        readinfo(id);
        bool lost=false;
        while(!next_day()){
            if(csgz.cnt<req[day-1]){
                lost=true;
                break;
            }
            system("cls");
            print();
            while(1){
                if(0) if(self.remainyf<minyl or self.remainyg<minyg) break;
                int opt;cin>>opt;
                if(opt==1){
                    if(self.remainyf>=root.costyf and self.remainyg>=root.costyg){
                        operat.push_back(1);
                        self.remainyf-=root.costyf;
                        self.remainyg-=root.costyg;
                        root.cnt++;
                        #if RAND_MAX==INT_MAX
                        system("clear");
                        #else
                        system("cls");
                        #endif
                        print();
                    }
                    else cout<<"[illegal: Lacking of Fertilizer or Sunlights]"<<endl;
                }
                if(opt==2){
                    if(high.cnt<=leaf.cnt){
                        cout<<"[illegal: Lacking Height: Need at least "<<leaf.cnt+1<<" m ]"<<endl;
                    }
                    else if(self.remainyf>=leaf.costyf and self.remainyg>=leaf.costyg){
                        operat.push_back(2);
                        self.remainyf-=leaf.costyf;
                        self.remainyg-=leaf.costyg;
                        leaf.cnt++;
                        #if RAND_MAX==INT_MAX
                        system("clear");
                        #else
                        system("cls");
                        #endif
                        print();
                    }
                    else cout<<"[illegal: Lacking of Fertilizer or Sunlights]"<<endl;
                }
                if(opt==3){
                    if(high.cnt<=wcgz.cnt+csgz.cnt){
                        cout<<"[illegal: Lacking Height: Need at least "<<wcgz.cnt+csgz.cnt+1<<" m ]"<<endl;
                    }
                    else if(self.remainyf>=wcgz.costyf and self.remainyg>=wcgz.costyg){
                        operat.push_back(3);
                        self.remainyf-=wcgz.costyf;
                        self.remainyg-=wcgz.costyg;
                        wcgz.cnt++;
                        #if RAND_MAX==INT_MAX
                        system("clear");
                        #else
                        system("cls");
                        #endif
                        print();
                    }
                    else cout<<"[illegal: Lacking of Fertilizer or Sunlights]"<<endl;
                }
                if(opt==4){
                    if(wcgz.cnt==0){
                        cout<<"[illiegal: Lacking Apple: Need at least 1 apple]"<<endl;
                    }
                    else if(self.remainyf>=csgz.costyf and self.remainyg>=csgz.costyg){
                        operat.push_back(4);
                        self.remainyf-=csgz.costyf;
                        self.remainyg-=csgz.costyg;
                        wcgz.cnt--;
                        csgz.cnt++;
                        #if RAND_MAX==INT_MAX
                        system("clear");
                        #else
                        system("cls");
                        #endif
                        print();
                    }
                    else cout<<"[illegal: Lacking of Fertilizer or Sunlights]"<<endl;
                }
                if(opt==5){
                    if(self.remainyf>=high.costyf and self.remainyg>=high.costyg){
                        operat.push_back(5);
                        self.remainyf-=high.costyf;
                        self.remainyg-=high.costyg;
                        high.cnt++;
                        #if RAND_MAX==INT_MAX
                        system("clear");
                        #else
                        system("cls");
                        #endif
                        print();
                    }
                    else cout<<"[illegal: Lacking of Fertilizer or Sunlights]"<<endl;
                }
                if(opt==6){
                    operat.push_back(6);
                    break;
                }
            }
        }
        if(csgz.cnt<req[day-1]){
            lost=true;
        }
        cout<<endl;
        if(lost) cout<<"You lost on "<<menulist::menuitem[id].levelname<<endl;
        else{
            cout<<"You win on "<<menulist::menuitem[id].levelname<<endl;
            if(id!=menulist::MAX_MENU and menulist::menuitem[id+1].islocked==true){
                menulist::menuitem[id+1].islocked=false;
                filestore();
                scbc(menulist::menuitem[id+1].levelname,gray);scbc(" have unlocked.",gray);cout<<endl;
                scbc("Your level progress has been saved.",gray);cout<<endl;
            }
        }
        scbc("Press Enter to continue.",gray);
        while(1){
            if(kbhit()){
                int a=getch();
                if(a==13){
                    break;
                }
            }
        }
    }
}
void starttutorial1(){
    system("cls");
    games::readinfo(2);
    int steps=1;
    while(steps<=11){
        games::tutorialprint(steps);
        if(steps<=10){
            while(1){
                if(kbhit()){
                    int a=getch();
                    if(a==13){
                        break;
                    }
                }
            }
        }
        steps++;
    }
}
void startlevel(int id){
    if(id==1){
        starttutorial1();
        return;
    }
    games::maint(id);
}
void menu(){
    menuselect=1;
    printmenu();
    while(1){
		if(kbhit()){
			int a=getch();
			if(a==72 and menuselect!=1){
				menuselect--;//up
                printmenu();
			}
			if(a==80 and menuselect!=menulist::MAX_MENU and menulist::menuitem[menuselect+1].islocked==false){
				menuselect++;//down
                printmenu();
			}
            if(a==13){
                startlevel(menuselect);
                printmenu();
            }
		}
	}
}
int main(){
    fileread();
    startpage();
    menu();
}