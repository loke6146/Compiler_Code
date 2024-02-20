#include<iostream>
#include<algorithm>
#include<chrono>
#include<thread>

#include<vector>

using namespace std;
void listofUsers();
void registerform();
void userlogin();
void security();
int otpgenerator();
void firstclass(int );
void secondclass(int);
void businessclass(int);
void bill(char,int);
void fstructure(char);
void busticketregister(string);


char fclass[5] , sclass[10] ,bclass[10];

void empty()
{
    for(int i=0;i<10;i++)
    {
        sclass[i]='O';
        if(i<5) fclass[i]='O';
        if(i<10) bclass[i]='O';
    }
}


struct node
{
    string name;
    string password;
};

struct node n;

struct findelement
{
    string name;
    findelement(string name ) : name(name){}
    bool operator() (node &q)
    {
        return name == q.name;
    }
};
vector<node> vt;

int main()
{
    empty();
    int i,loop=3;
    
    while(loop==3)
    {
        
        cout<<"1.LOGINFORM     2.REGISTERFORM      3.PRIVACY          4.LISTOFUSERS     5.END/EXIT"<<endl;
        cout<<"enter choice num :";
        cin>>i;
        switch(i)
        {
            case 1: cout << "\033[2J\033[1;1H";
                    userlogin();
                    break;
           case 2 :  cout << "\033[2J\033[1;1H";
                    registerform();
                    break;
           case 3:   cout << "\033[2J\033[1;1H";
                    security();
                    break;
          case 4:   cout << "\033[2J\033[1;1H";
                    listofUsers();
                    break;
                   
          case 5:   loop=5;
                    break;
          default: cout<<"invalid input"<<endl;
                    break;
        }
    }
    return 0;
}



void registerform()
{
    cout<<"REGISTERFORM   "<<endl;
    string uname,upassword;
    cout<<"enter your name: ";
    cin>>uname;
    if(vt.end() == find_if ( vt.begin() , vt.end() , findelement(uname)))
    {
        n.name=uname;
      
        cout<<" enter your password :";
        cin>>n.password;
        vt.push_back(n);
        cout<<"Mail is verified and saved ..."<<endl;
    }
    else{ cout<<"username already registered "<<endl;
        return;
    }
}

void userlogin()
{    cout<<" LOGINFORM   "<<endl;
int i;
    string uname,upassword,duppassword;
    cout<<"enter your name: ";
    cin>>uname;
    if(vt.end() != find_if ( vt.begin() , vt.end() , findelement(uname)))
    {
        
        cout<<"we found your account .."<<endl;
        cout<<" enter your password :";
        cin>>upassword;
        
        for(auto it : vt)
        {
            if(it.name == uname ) duppassword=it.password;
            if(it.name == uname && it.password == upassword)
            {
                cout<<" \t you are entered with username { "<<it.name<<" } "<<endl;
                cout << "\033[2J\033[1;1H";
                busticketregister(it.name);
                //cout<<" \t welcome to the "
                return;
            }
        }
         cout<<"wrong password ... "<<endl;
         cout<<" 1. retry  2.otp 3.mainmenu"<<endl;
         cin>>i;
         switch(i)
         {
             case 1 : cout << "\033[2J\033[1;1H";
             userlogin();break;
             case 2 : if(i==otpgenerator())
                       {
                           cout<<"your password is :"<<duppassword<<endl;
                           std::chrono::seconds durc(5);
                           std::this_thread::sleep_for( durc );
                           //cout << "\033[2J\033[1;1H";
                       }
                       else 
                       {cout<<"wrong OTP try ..."<<endl;return;}
                       
                       break;
             default: return;
         }

    }
    else{ cout<<" you have to register first "<<endl;
        registerform();
    }
}

void busticketregister(string username)

{cout<<" \t you are entered with username { "<<username<<" } "<<endl;
    
    cout<<"WELCOME TO TRAIN TICKET REGISTRATIONFORM , VIJAYWADA TO HYDERABAD"<<endl;
    int s,t,loop=0;
    while(loop==0){
    cout<<"1.firstclass 2.second class 3.business class 4.exit"<<endl;
    
    cin>>s;
    
    switch(s)
    {
        case 1 : cout << "\033[2J\033[1;1H";
                 cout<<"enter num of seats in firstclass : ";
                cin>>t;
                firstclass(t);
                break;
        case 2 : cout << "\033[2J\033[1;1H";
        cout<<"enter num of seats  secondclass : ";
                cin>>t;
                secondclass(t);break;
        case 3: cout << "\033[2J\033[1;1H";
                cout<<"enter num of seats  businessclass : ";
                cin>>t;
                businessclass(t);break;
        default : loop=1;
    }}
   
}

void businessclass(int seats)
{cout << "\033[2J\033[1;1H";
    cout<<"***BUSINESSCLASS REGISTRATION VIJAYWADA TO HYDERABAD***"<<"( "<<seats<<") seats"<<endl;
    fstructure('b');
    int n,d=0;
    while(seats<=10 && seats!=0)
    {
        cout<<"enter seat num :";
        cin>>n;
        if(n>=16 && n<=25 && bclass[n-16] == 'O')
        {++d;
            bclass[ n-16 ]='R';
            seats=seats-1;
        }
        else
        {
            cout<<"error in your input ..please check "<<endl;
        }
    }
    cout<<"printing bil...." <<endl;
    bill('b' , d);
}


void secondclass(int seats)
{cout << "\033[2J\033[1;1H";
 cout<<"***SECONDCLASS REGISTRACTION VIJAYWADA TO HYDERABAD***"<<" ( "<<seats<<") seats"<<endl;
    int n,d=0;
    fstructure('s');
    while(seats<=10 && seats!=0)
    {
        cout<<"enter seat num :";
        cin>>n;
        if(n>=6 && n<=15 && sclass[n-6] == 'O')
        {++d;
            sclass[ n-6 ]='R';
            seats=seats-1;
        }
        else
        {
            cout<<"error in your input ..please check "<<endl;
        }
    }
    cout<<"printing bil...." <<endl;
    cout << "\033[2J\033[1;1H";
    bill('s' , d);
}

void firstclass(int seats)
{  cout<<"***SFIRSTCLASS REGISTRACTION VIJAYWADA TO HYDERABAD***"<<"( "<<seats<<") seats"<<endl;
    int n,d=0;
    fstructure('f');
    while(seats<=5 && seats!=0)
    {
        cout<<"enter seat num :";
        cin>>n;
        if(n>=1 && n<=5 && fclass[n-1] == 'O')
        {++d;
            fclass[n-1]='R';
            seats=seats-1;
        }
        else
        {
            cout<<"error in your input ..please check "<<endl;
        }
    }
    cout<<"printing bil...." <<endl;
    bill('f' , d);
}

void fstructure(char a)
{
    
    switch(a)
    {
        case 'f' : cout<<"1 ["<<fclass[0]<<"] \t\t "<<"2 ["<<fclass[1]<<"] "<<endl;
                   cout<<"3 ["<<fclass[2]<<"] \t\t "<<"4 ["<<fclass[3]<<"] "<<endl;
                   cout<<"5 ["<<fclass[4]<<"] \t\t "<<endl;
                   break;
        
        case 's' : cout<<"6 ["<<sclass[0]<<"] \t\t "<<"7 ["<<sclass[1]<<"] "<<endl;
                   cout<<"8 ["<<sclass[2]<<"] \t\t "<<"9 ["<<sclass[3]<<"] "<<endl;
                   cout<<"10 ["<<sclass[4]<<"] \t\t "<<"11["<<sclass[5]<<"] "<<endl;
                   cout<<"12["<<sclass[6]<<"] \t\t "<<"13["<<sclass[7]<<"] "<<endl;
                   cout<<"14["<<sclass[8]<<"] \t\t "<<"15["<<sclass[9]<<"] "<<endl; 
                   break;
        case 'b' : cout<<"16["<<bclass[0]<<"] \t\t "<<"17["<<bclass[1]<<"] "<<endl;
                   cout<<"18["<<bclass[2]<<"] \t\t "<<"19["<<bclass[3]<<"] "<<endl;
                   cout<<"20["<<bclass[4]<<"] \t\t "<<"21["<<bclass[5]<<"] "<<endl;
                   cout<<"22["<<bclass[6]<<"] \t\t "<<"23["<<bclass[7]<<"] "<<endl;
                   cout<<"24["<<bclass[8]<<"] \t\t "<<"25["<<bclass[9]<<"] "<<endl; 
                   break;    
    }
    
}

void bill(char a,int seats)
{cout << "\033[2J\033[1;1H";
    switch(a)
    {
        case 'f'  : cout<<"**** FIRSTCLASS TICKET  VIJAYWADA TO HYDERABAD****"<<endl;
                    cout<<"     no.of passengers: "<<seats<<endl;
                    cout<<"     no of seats booked: "<<seats<<endl;
                    cout<<"\t AMOUNT : "<<700*seats<<"/-"<<endl;
                    fstructure('f');
                    break;
        case 's'  : cout<<"**** SECONDCLASS TICKET  VIJAYWADA TO HYDERABAD****"<<endl;
                    cout<<"     no.of passengers: "<<seats<<endl;
                    cout<<"     no of seats booked: "<<seats<<endl;
                    cout<<"\t AMOUNT : "<<500*seats<< "/-"<<endl;
                    fstructure('s');
                    break;
        case 'b'  : cout<<"**** BUSINESSCLASS TICKET  VIJAYWADA TO HYDERABAD****"<<endl;
                    cout<<"     no.of passengers: "<<seats<<endl;
                    cout<<"     no of seats booked: "<<seats<<endl;
                    cout<<"\t AMOUNT : "<<900*seats<< "/-"<<endl;
                    fstructure('b');
                    break;
    }
    
}

void security()
{
    int pas=9999,pin;
    cout<<"enter default pin : ";
    cin>>pin;
    if(pas== pin)
    {       cout<<"\t"<<"/ users "<<" -- "<<"passwords /"<<endl;
        for(auto it: vt)
        {
            cout<<"\t "<<it.name<<" -- "<<it.password<<endl;
        }
    }
    else cout<<" wrong pin ";
    
}

void listofUsers()
{
	cout<<endl<<"\t\t\t\tLIST OF USERS "<<endl;
	int i=0;
	if(vt.end() == vt.begin())
	{
	    cout<<"\t\t\t\tempty list ..."<<endl;
	}
	else{
	for(auto it : vt)
	{
		cout<<++i<<". "<<it.name<<endl;
	}}
	cout<<"____________________________________"<<endl;
}

int otpgenerator()
{
    int otp=(rand()%9999+1000);
    cout<<"generating otp in 3sec"<<endl;
    cout << "generating otp...." << std::endl;
    std::chrono::seconds dura(3);
    std::this_thread::sleep_for( dura );
    cout<<"\x1B[42m"<<"otp : "<<otp<<"\033[0m\t\t"<<endl;
    //cout << "OTP: "<<otp<<endl;
    cout<<" clearing screen in 5sec.."<<endl;
    std::chrono::seconds durb(5);
    std::this_thread::sleep_for( durb );
    cout << "\033[2J\033[1;1H";
    int userotp;
    cout<<"enter otp: ";
    cin>>userotp;
    if(otp==userotp)
    {
        return 2;
    }
    else return 1;
}
