#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

char valet;
string owner,carnum;
float intime,outime;
class cars
{
string carno;
string ownername;
float timein;
float timeout;
int days;
char valet;
	public:
		cars()
		{ 
		int i,j=0;	
			cout<<"enter car no size 10"<<endl;
		     cin>>carno;
		     int x=sizeof(carno);
			cout<<"enter ownername"<<endl;
	         cin>>ownername;
			cout<<"enter time in as decimal quantity(24-hour format)"<<endl;
			cin>>timein;
			try
			{
				if(timein>=24.00 && timein<0.00)
				throw 1.0;
				else if(timein-(int)timein>(0.59))
				throw 2.0;
				else;
			}
			catch(float x)
			{
				cout<<"enter proper in  time"<<endl;
				exit(10);
			}
			
			cout<<"enter timeout as decimal quantity(24-hour format)"<<endl;
			cin>>timeout;
			try
			{
				if(timein>=24.00 && timein<=0.00)
				throw 'a';
				else if(timein-(int)timein>0.59)
				throw 'b';
				else;
			}
			catch(char x)
			{
				cout<<"enter proper exit time"<<endl;
				exit(10);
			}
			
		}
		float costgenerator(int timein,int timeout)
		{
			float cost,t,tcost;
			t=timeout;
			if(t<timein)
			{
				t=(24.00)+timein;
				cost=t-timein;
			}
			else if(t==timein)
			{
				cout<<"enter proper time"<<endl;
				exit(10);
			}
			else
			cost=timeout-timein;
			if(cost<=0.30)
			tcost=90;
			else if(cost>0.30 && (cost<=1.00))
			tcost=180;
			else if((cost>1.00) && (cost<=3.00))
			tcost=270;
			else
			tcost=310;
			
			return tcost;
		}
		float lcostgenerator(int days,char valet)
		{
			float ltcost,lcost;
			if(valet=='y'&& days>0)
			{
			 ltcost=60*days;
			 if(days<10)
			 ltcost+=(1000*days);
			 else if(days>=10 && days<100)
			 ltcost+=(2000*days);
			 else if(days>100 && days<360)
			 ltcost+=(4000*days);
			 else
			 cout<<"pay the due to park"<<endl;
		    }
		    else
		     {
		     if(days<10)
			 ltcost+=(1000*days);
			 else if(days>=10 && days<100)
			 ltcost+=(2000*days);
			 else if(days>100 && days<360)
			 ltcost+=(4000*days);
			 else
			 cout<<"pay the due to park"<<endl;
			 }
	     return ltcost;
		}	
	friend void cardet(cars c);
};
void cardet(cars c)
{
 	outime=c.timeout;
 	intime=c.timein;
 	owner=c.ownername;
 	carnum=c.carno;
}

int main()
{
	string s;
	string line;
    string word;
	int ch,cha;
	char chara;
	int x;
	fstream f;
	float costl;
	f.open("fils.txt",ios::in|ios::out|ios::app);

	do
	{
		cout<<"welcome to car park fee collector"<<endl;
		cout<<"_________________________________"<<endl;
		cout<<"MENU"<<endl;
		cout<<"1.NEW TO THIS PARKING LOT ??"<<endl;
		cout<<"       a.luxury parking"<<endl;
		cout<<"       b.normal"<<endl;
	    cout<<"2.SHOW ALL RECORD DETAILS??"<<endl;	
		cout<<"3.RETRIEVE RECORD based on car no"<<endl;
		cout<<"ENTER CHOICE"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1:
			{
		    	cars c;
				char chara;
				char val;
				int daysl;
				cardet(c);
				f<<carnum<<" ";
				f<<owner<<" ";
				f<<outime<<" ";
				f<<intime<<" ";
			    cout<<"enter choice for luxury parking or not from menu(a/b)"<<endl;
			    cin>>chara;
			    
			    	if(chara=='a')
			    	{
					
			    		cout<<"you have chosen luxury car park"<<endl;
			    		cout<<"enter days you will be parking your car for"<<endl;
			    		cin>>daysl;
			    		cout<<"do you require valet"<<"\n"<<"enter yes as y and no as n"<<endl;
			    		cin>>val;
						costl=c.lcostgenerator(daysl,val);
					}
					if(chara='b')
					{
					  costl=c.costgenerator(intime,outime);
				    }
				}
				cout<<"your cost="<<costl<<endl;
				f<<costl<<" ";
			 break;
		
			case 2:
			{
        
       	    string word;
	       while(f>>word)
	       {
	       	cout<<word;
		   }
	        }
			break;
	
			case 3:
		    {	
	       	string word,line;
            fstream f;
             f.open("fils.txt",ios::in|ios::out|ios::app);
            cout<<"enter number"<<endl;
	        cin>>word;
	        if(f.is_open())
	        {
		     while(getline(f,line))
		    {
			if(line.find(word)!=string::npos)
			{
			cout<<"found!!!"<<endl;
			cout<<line;
		    }
		    else 
		    cout<<"notfound"<<endl;
		    }
	        }
			break;
		 }
       }
        cout<<"continue?? 1/0"<<endl;
        cin>>x;
    }while(x==1);
	
	
}


