#include<iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;


char totalseats[17];
char rseates[13];
int stops[5];
void kms(int s)
{
    for(int j=1;j<=5;j++)
    {
        stops[j]=5*j;
    }
    for(int i=0;i<17;i++)
    {
        totalseats[i]='O';
    }
}


class bus
{
    string stop;
int user;
int metroseats;
int cityseats;
int palleveluguseats;
int startpoint,endpoint;

public:

void selectbus()
{
   cout<<"|| 1->APSRTC  || 2-> PRIVATE Bus ||"<<endl;
   cout<<"Enter your bus : ";
   cin>>user;
   switch(user)
   {
       case 1: cout<<" enter no of seats : ";
               cin>>metroseats;
               int seatarr[metroseats];
               journey();
               kms(metroseats);
               printticket(stops,metroseats);
               reservedSeates();
               break;


   }
}

void journey()
{
   cout<<"Enter Starting Point: "<<endl;
   cout<<"1.Gannavaram || 2.Eluru || 3.Tadepalligudem || 4.Rajamundry || 5.Anakapalle"<<endl;
   cin>>startpoint;
   cout<<"Enter Destination Point: "<<endl;
   cout<<"1.Gannavaram || 2.Eluru || 3.Tadepalligudem || 4.Rajamundry || 5.Anakapalle"<<endl;
   cin>>endpoint;
}

void printticket(int arr[],int seats)
{
   cout<<" Startpoint - ";
   points(startpoint);
   cout<<" Destination - ";
   points(endpoint);
   cout<<" No.of passengers : "<<metroseats<<endl;
   cout<<"TICKET PRICCE : "<<(((stops[endpoint]-stops[startpoint])*45)*metroseats)<<endl;
   
}

void points(int a)
{
   switch(a)
   {
       case 1: stop="Gannavaram \n";
               cout<<stop;
               break;
       case 2: stop="Eluru \n";
                        cout<<stop;break;
       case 3: stop="Tadepalligudem \n";
                        cout<<stop;break;
       case 4: stop="Rajamundry \n";
                        cout<<stop;break;
       case 5: stop="Anakapalle \n";
                        cout<<stop;                
   }
}

void reservedSeates()
{       int seatarr[metroseats];

    busstructure();
   for(int i=0;i<metroseats;i++)
   {
     
       cout<<"Choose your seat : ";
       cin>>seatarr[i];
       while((totalseats[seatarr[i]-1]=='R')||(seatarr[i]>16)){cout<<"invalid seat or that seat is already booked ..\n try again ";
            cin>>seatarr[i];
       }
       totalseats[seatarr[i]-1]='R';
   }
   busstructure();
   cout<<"TICKET PRICCE : "<<(((stops[endpoint]-stops[startpoint])*45)*metroseats)<<endl;

}

void busstructure()
{
   cout<<"|| s1("<<totalseats[0]<<")   s2("<<totalseats[1]<<")                      s3( "<<totalseats[2]<<")   s4("<<totalseats[3]<<")    ||"<<endl;
   cout<<"|| s5("<<totalseats[4]<<")   s6("<<totalseats[5]<<")                      s7( "<<totalseats[6]<<")   s8("<<totalseats[7]<<")    ||"<<endl;
   cout<<"|| s9("<<totalseats[8]<<")   s10("<<totalseats[9]<<")                     s11( "<<totalseats[10]<<") s12("<<totalseats[11]<<")    ||"<<endl;
   cout<<"|| s13("<<totalseats[12]<<")   s14("<<totalseats[13]<<")                  s15( "<<totalseats[14]<<") s16("<<totalseats[15]<<")      ||"<<endl;
}



};
int main()
{
   
bus b;
b.selectbus();
}