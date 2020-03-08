#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
using namespace std;

static int p=0;


class Bus
{
    char bus_no[10],driver[20],from[10],to[10],date[15],arrival[5],depart[5],seat[8][4][10],contact_no[15],fare[15];
public:
    int bus_reg();
    void reservation();
    void empty();
    void display();
    void available();
    void position(int i);
    friend void vline(char ch);
    void cancel();
}bus[10];



int Bus::bus_reg()
{
     if(p>9)
     {
         cout<<"Already ten buses are registered.\nMaximum number of buses are registered.\n";

     }
     else
     {
        fstream out;
        out.open("busreg.txt",ios::out|ios::app);
        if(!out)
        {
            cout<<"cannot open";
            return 1;
        }
        cout<<"Enter the Bus number: ";
        cin>>bus[p].bus_no;
        cout<<"\nEnter Driver's name: ";
        cin>>bus[p].driver;
        cout<<"\nEnter Driver's Contact number: ";
        cin>>bus[p].contact_no;
        cout<<"\nDeparture time: ";
        cin>>bus[p].depart;
        cout<<"\nArrival time: ";
        cin>>bus[p].arrival;
        cout<<"\nFrom: ";
        cin>>bus[p].from;
        cout<<"\nTo: ";
        cin>>bus[p].to;
        cout<<"\nDate: ";
        cin>>bus[p].date;
        cout<<"\nFare: ";
        cin>>bus[p].fare;

        out<<endl<<"\t"<<bus[p].bus_no<<"\t\t"<<bus[p].driver<<"\t\t"<<bus[p].contact_no <<"\t\t"
        << bus[p].depart<<"\t\t"<<bus[p].arrival <<"\t\t"<< bus[p].from<<"\t\t"<< bus[p].to<<"\t\t"<<bus[p].date<<"\t\t"<<bus[p].fare<<endl;
        out.close();
        bus[p].empty();
        p++;
       /* fstream in;
        in.open("busreg.txt",ios::in);
        if(!in)
        {
            cout<<"cannot read the file";
            return 1;
        }
        in.read((char *)&bus[p],sizeof(Bus));
        in.close();
    */}
}


void Bus::reservation()
{
    int seat,n;
    char num[5];
    top:
    cout<<"Bus Number: ";
    cin>>num;
    for(n=0;n<=p;n++)
        {
            if(strcmp(bus[n].bus_no,num)==0)
            break;
        }
    while(n<=p)
        {
            cout<<"\nSeat Number: ";
            cin>>seat;
            if(seat>32)
                {
                    cout<<"\nThere are only 32 seats available in this bus.";
                }
            else
                {
                    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
                    {
                        cout<<"\nEnter passenger's name: ";
                        cin>>bus[n].seat[seat/4][(seat%4)-1];
                        break;
                    }
                        else
                        {
                            cout<<"The seat no. is already reserved.\n";
                        }
                }
                if(n>p)
                    {
                        cout<<"Enter correct bus no.\n";
                        goto top;
                    }
            }
}

void Bus::empty()

{

  for(int i=0; i<8;i++)
  {
      for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
      }
    }

}

void vline(char ch)
{
    for (int i=141;i>0;i--)
        {cout<<ch;
          }
          cout<<"\n";
}

void Bus::display()
{
    int n;
    char num[10];
    cout<<"Enter the Bus number: ";
    cin>>num;
    for(n=0;n<=p;n++)
    {
        if(strcmp(bus[n].bus_no, num)==0)
            break;
    }
        while(n<=p)
            {
                vline('*');
                cout<<"\nBus no: "<<bus[n].bus_no
                <<"\nDriver: "<<bus[n].driver<<"\n"<<"Arrival: "
                <<bus[n].arrival<<"\t\tDeparture: "<<bus[n].depart
                <<"\nFrom: "<<bus[n].from<<"\t\tTo: "<<
                bus[n].to<<"\nDate: "<<bus[n].date<<"\t\tContact number: "<<bus[n].contact_no
                <<"\nFare: "<<bus[n].fare<<endl;
                vline('*');
                bus[0].position(n);
                int a=1;
                for (int i=0; i<8; i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            a++;
                            if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                                cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
                        }
                    }
                        break;
            }
                    if(n>p)
                        cout<<"Enter the correct bus number: ";
                        cin>>num;
}
void Bus::position(int l)
{
    int s=0;p=0;
    for (int i =0; i<8;i++)
        {
            cout<<"\n";
            for (int j = 0;j<4; j++)
                {
                    s++;
                    if(strcmp(bus[l].seat[i][j], "Empty")==0)
                    {
                        cout.width(10);
                        cout.fill(' ');
                        cout<<s<<".";
                        cout.width(5);
                        cout.fill(' ');
                        cout<<bus[l].seat[i][j];
                        p++;

                    }
                    else
                        {
                            cout.width(10);
                            cout.fill(' ');
                            cout<<s<<".";
                            cout.width(5);
                            cout.fill(' ');
                            cout<<bus[l].seat[i][j];
                        }
                }

    }
    cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].bus_no;

}
void Bus::available()
{
    for(int n=0;n<p;n++)
        {
            vline('*');
            cout<<"Bus no: "<<bus[n].bus_no<<"\nDriver: "<<bus[n].driver<<"\n"
            <<"Arrival: "<<bus[n].arrival<<"\t\tDeparture: "
            <<bus[n].depart<<"\nDate: "<<bus[n].date<<"\nFrom: "<<bus[n].from<<"\t\tTo: "<<bus[n].to
            <<"\nFare: "<<bus[n].fare<<"\t\tContact number: "<<bus[n].contact_no<<endl;
            vline('*');

        }
}
void Bus::cancel()
{
    int seat,n;
    char num[10];
    char c;
    cout<<"Bus Number: ";
    cin>>num;
    for(n=0;n<=p;n++)
        {
            if(strcmp(bus[n].bus_no,num)==0)
            break;
        }
        while(n<=p)
            {
               cout<<"\n Enter seat number";
                cin>>seat;
               if(bus[n].seat[seat/4][(seat%4)-1]== "Empty")
               {
                    printf("The seat is already empty");
               }
               else
               {
                    strcpy(bus[n].seat[seat/4][(seat%4)-1], "Empty");
                    cout<<"\nPlease confirm your cancellation(y/n)";
                    cin>>c;
                    if(c=='y')
                    {
                        cout<<"your seat has been successfully cancelled";
                        bus[p].position(n);
                        break;
                    }
                    else
                    {
                        cout<<"\nyour seat has not been cancelled";
                    }
               }
           }
}


int main()
{
top1:
int choice,main_choice=0;

char user[10],pass[10];

cout<<"\n\t\t********Main Menu********";

cout<<"\n\n\t\t1.OWNER\n\t\t"
<<"2.PASSENGER\n\t\t"<<"\n\t\tENTER YOUR CHOICE:";

cin>>main_choice;

if(main_choice==1)
{
        cout<<"\n\tEnter the username\n\t\t";
        cin>>user;

        if(strcmp(user,"owner")==0){
                cout<<"\n\tenter the password\n\t\t";
                cin>>pass;
            if(strcmp(pass,"owner123")==0)
            {
                while(1)
                    {
                        cout<<"\n\n\n";
                        cout<<"\n\t\t\t1.Bus Registration\n\t\t\t"
                        <<"2.Buses Available\n\t\t\t"
                        <<"3.Exit\n\t\t\t";
                        cout<<"\n\t\t\tEnter your choice:";
                        cin>>choice;
                        switch(choice)
                        {
                            case 1:  bus[p].bus_reg();
                            break;
                            case 2:  bus[0].available();
                            break;
                            case 3:  goto top1;
                        }
                    }
            }
            else
            {
                cout<<"\n\t\tWrong password";
                goto top1;
            }
        }
        else
        {
            cout<<"\n\t\tWrong username";
            goto top1;
        }
}
else if(main_choice==2)
{
    while(1)
    {
        cout<<"\n\t\t\t1.Ticket Reservation\n\t\t\t"
        <<"2.buses available\n\t\t\t"
        <<"3.Display the details of the bus\n\t\t\t"
        <<"4.Cancel the booked ticket\n\t\t\t"
        <<"5.Main menu\n\t\t\t"<<"6.Exit\n\t\t"<<"ENTER YOUR CHOICE:\n\t\t\t";
        cin>>choice;

            switch(choice)
            {
                case 1: bus[p].reservation();
                break;
                case 2:  bus[0].available();
                break;
                case 3:  bus[0].display();
                break;
                case 4:  bus[p].cancel();
                break;
                case 5: goto top1;break;
                case 6:exit(0);
            }
    }

}
else
    {
        cout<<"\n\nChoose from the given options only\n\n";

        cin.clear();
        cin.ignore(100, '\n');
        goto top1;
    }
return 0;
}
