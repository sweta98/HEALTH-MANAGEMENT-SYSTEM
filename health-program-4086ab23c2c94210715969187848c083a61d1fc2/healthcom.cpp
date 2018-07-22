 #include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
int count;
using namespace std;
class user
{
public:
    string id;
    string name;

};
class admin:public virtual user
{

    public:
    string username;
    string password;

    friend admin login2(admin);
    virtual void user_login();
    void patient_details(string );
    void doctor_details(string );
   void hospital_details(string);
};
class doctor:public virtual user,public admin
{
public:
    void user_login();
    friend doctor login3(doctor);
};

class patient:public virtual user,public admin
{
    public:
        void register1();
        friend patient login1(patient);
        void call(string);
        void user_login();
        string show_date();
        void book_appointment(string,string,string,string);
        bool compare(string);
        bool com(string);
};

//function for registration

void patient:: register1()
    {
string id,username,password,city,Blood,email,gender,contactno,name,history,DOB,age;
    cout<<"Enter name:"<<" ";
    cin.ignore();
	getline(cin,name);
	cout<<"Enter id:"<<" ";
	cin>>id;
	if(com(id))
    {
        cout<<"the Id you entered already exist"<<endl;
        cout<<"enter another"<<endl;
        cin>>id;
    }
	cout<<"Enter Username : "<<endl;
	cin>>username;
	if(compare(username))
    {
        cout<<"username exists"<<endl;
        cout<<"Enter Username : "<<endl;
        cin>>username;
    }
    cout<<"Enter Password : "<<endl;
    cin>>password;
    cout<<"Enter city : "<<endl;
    cin>>city;
    cout<<"Enter Blood Group: "<<endl;
    cin>>Blood;
    cout<<"Enter email address : "<<endl;
    cin>>email;
    cout<<"Enter your DOB"<<endl;
    cin>>DOB;
    cout<<"Enter your Age"<<endl;
    cin>>age;
    cout<<"Enter your gender(M/F): "<<endl;
    cin>>gender;
    cout<<"Enter contact no. : "<<endl;
    cin>>contactno;
    cout<<"Enter your health history (surgeries/ any medication prescribed) :"<<endl;
    cin.ignore();
	getline(cin,history);
    fstream fhandle1;
    fhandle1.open("username.csv",ios::app);
    fhandle1<<id<<","<<name<<","<<username<<","<<password<<","<<city<<","<<Blood<<","<<email<<","<<DOB<<","<<age<<","<<gender<<","<<contactno<<","<<history<<"\n";
    fhandle1.close();

    }
    //function for comparing unique username
   bool patient::  compare(string uname )
    {
        int flag=0;
        string s,name,username,password,city,blood,em,gen,con,his,d,age;
        fstream fhandle1;
        fhandle1.open("username.csv");
        while(fhandle1.good())
        {

            getline(fhandle1,s,',');
            getline(fhandle1,name,',');
            getline(fhandle1,username,',');
            getline(fhandle1,password,',');
            getline(fhandle1,city,',');
            getline(fhandle1,blood,',');
            getline(fhandle1,em,',');
            getline(fhandle1,d,',');
            getline(fhandle1,age,',');
            getline(fhandle1,gen,',');
            getline(fhandle1,con,',');
            getline(fhandle1,his,',');
            if(uname.compare(username)==0)
            {
                flag=1;
                break;

            }

    }
    if(flag==1)
    {

        return true;
    }
    else
        return false;
    }
    bool patient:: com(string id)
    {
          int flag=0;
        string s,name,username,password,city,blood,em,gen,con,his,d,age;
        fstream fhandle1;
        fhandle1.open("username.csv");
        while(fhandle1.good())
        {

            getline(fhandle1,s,',');
            getline(fhandle1,name,',');
            getline(fhandle1,username,',');
            getline(fhandle1,password,',');
            getline(fhandle1,city,',');
            getline(fhandle1,blood,',');
            getline(fhandle1,em,',');
            getline(fhandle1,d,',');
            getline(fhandle1,age,',');
            getline(fhandle1,gen,',');
            getline(fhandle1,con,',');
            getline(fhandle1,his,',');
            if(id.compare(s)==0)
            {
                flag=1;
                break;

            }

    }
    if(flag==1)
    {

        return true;
    }
    else
        return false;
    }




//friend fuction declaration
patient login1(patient ob)
    {

    string username,password;
	cout<<"Enter Username : "<<endl;
	cin>>ob.username;

		cout<<"Enter Password : "<<endl;
		cin>>ob.password;
        return ob;
    }

//friend fuction declaration
    admin login2(admin ob)
    {

    string username,password;
	cout<<"Enter Username : "<<endl;
	cin>>ob.username;

		cout<<"Enter Password : "<<endl;
		cin>>ob.password;
		return ob;

    }


       doctor login3(doctor ob)
    {

    string username,password;
	cout<<"Enter Username : "<<endl;
	cin>>ob.username;

		cout<<"Enter Password : "<<endl;
		cin>>ob.password;
		return ob;

    }

//functions for patient login

    void patient::user_login()
    {
        int flag=0;
	string name,uname,pass,id,city,b,e,g,con,his,d,age;
	fstream fhandle;
	fhandle.open("username.csv", ios::in);
	while(!fhandle.eof())
	{
		getline(fhandle,id,',');
		getline(fhandle,name,',');
		getline(fhandle,uname,',');
		getline(fhandle,pass,',');
		getline(fhandle,city,',');
		getline(fhandle,b,',');
		getline(fhandle,e,',');
		getline(fhandle,d,',');
		getline(fhandle,age,',');
		getline(fhandle,g,',');
		getline(fhandle,con,',');
		getline(fhandle,his,'\n');
		if(uname==username && pass==password)
        {
            flag++;
            std::cout<<"login succesful";
            break;
        }
        else{

        }
	}
	if(flag == 0)
    {
        cout<<"login unsucessful";
    }
    cout<<"\n\nplease log in"<<endl;
    cout<<"username"<<endl;
    cin>>username;
    cout<<"password"<<endl;
    cin>>password;
    system("cls");
     call(username);
    }


    //function for showing date
    string patient::show_date()
{
    int choice;
	time_t now=time(0);
  struct tm * ltm=localtime(&now);
  char day1[20],day2[20],day3[20],day4[20],day5[20];

    ltm->tm_mday=ltm->tm_mday+1;
    strftime (day1,20,"%Y-%m-%d",ltm);
	cout<<"1. ";
    puts(day1);
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day2,20,"%Y-%m-%d",ltm);
	cout<<"2. ";
    puts(day2);
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day3,20,"%Y-%m-%d",ltm);
	cout<<"3. ";
    puts(day3);
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day4,20,"%Y-%m-%d",ltm);
	cout<<"4. ";
    puts(day4);
     ltm->tm_mday=ltm->tm_mday+1;
    strftime (day5,20,"%Y-%m-%d",ltm);
	cout<<"5. ";
    puts(day5);
	cout<<"Choose the Date of Appointment"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
		{
			string st(day1);
			return st;
			break;
		}
		case 2:
		{
			string st(day2);
			return st;
			break;

		}
		case 3:
		{
			string st(day3);
			return st;
			break;
		}
		case 4:
		{
			string st(day4);
			return st;
			break;
		}
		case 5:
		{
			string st(day5);
			return st;
			break;
		}
		default:
		{
			cout<<"Invalid Input"<<endl;
		}
	}

}

//function to book appointment
void patient::book_appointment(string p,string q,string r,string s)
{
	string uhid=s;
	string hname,hid;
	string did,dname,depart,timing,hid1,city;
	string pid,pname,g,a,bgroup,phone,mail,history,d,age;

	time_t now=time(0);
	char *dt=ctime(&now);
	char value;
	cout<<"Confirm Appointment (y/n)"<<endl;
	cin>>value;
	switch(value)
	{
		case 'y':
		{
			fstream fhandle;
			count++;
			 fstream f;
            cout<<"count="<<count<<endl;
            f.open("counte.csv");
            f<<count;
			fhandle.open("cuttack.csv",ios::in);
			while(fhandle)
			{
				getline(fhandle,hid,',');
				getline(fhandle,hname,'\n');
				if(p.compare(hid)==0)
				break;
				else
				continue;
			}
			fhandle.close();
			fhandle.open("kalinga.csv",ios::in);
			while(fhandle)
			{
				getline(fhandle,did,',');
				getline(fhandle,dname,',');
				getline(fhandle,depart,',');
				getline(fhandle,timing,'\n');
				if(q.compare(did)==0)
				break;
				else
				continue;
			}
			fhandle.close();
			fhandle.open("username.csv",ios::in);
			while(fhandle)
			{
				getline(fhandle,pid,',');
				getline(fhandle,pname,',');
				getline(fhandle,g,',');
				getline(fhandle,a,',');
                getline(fhandle,city,',');
				getline(fhandle,bgroup,',');
				getline(fhandle,mail,',');
				getline(fhandle,phone,',');
				getline(fhandle,d,',');
				getline(fhandle,age,',');
				getline(fhandle,history,'\n');
				if(s.compare(pid)==0)
				break;
				else
				continue;
			}
			fhandle.close();
			//show the appointment details to the patient

			cout<<"Appointment Booked"<<endl;
			cout<<"Patient Name : "<<pname<<endl;
			cout<<"Patient Id : "<<s<<endl;
			cout<<"Hospital Name : "<<hname<<endl;
			cout<<"Doctor Name : "<<dname<<endl;
			cout<<"Appointment Date : "<<r<<endl;
			cout<<"Booked on : "<<dt<<endl;
			fhandle.open("appointments.csv",ios::app);
			cin.ignore();
			fhandle<<s<<","<<pname<<","<<hname<<","<<dname<<","<<r<<endl;
			fhandle.close();

}
}
}
//function for showing patient details
    void admin::patient_details(string pid)
    {
        int flag=0;
        string s,name,username,password,city,blood,em,gen,con,his,d,age;
        fstream fhandle1;
        fhandle1.open("username.csv");
        while(fhandle1.good())
        {

            getline(fhandle1,s,',');
            getline(fhandle1,name,',');
            getline(fhandle1,username,',');
            getline(fhandle1,password,',');
            getline(fhandle1,city,',');
            getline(fhandle1,blood,',');
            getline(fhandle1,em,',');
            getline(fhandle1,d,',');
            getline(fhandle1,age,',');
            getline(fhandle1,gen,',');
            getline(fhandle1,con,',');
            getline(fhandle1,his,'\n');
            if(pid.compare(s)==0)
            {
                break;

            }

    }
    cout<<"Patient Name:"<<" "<<name<<endl;
    cout<<"Patient Blood Group:"<<" "<<blood<<endl;
    cout<<"Patient Gender:"<<" "<<gen<<endl;
    cout<<"Patient's Contact:"<<" "<<con<<endl;
    cout<<"Patient's History:"<<" "<<his<<endl;

    }
    //function for showing hospital details
    void admin:: hospital_details(string pname)
    {
       string usernam,name,docname,hosname,time;
       fstream f;
       f.open("appointments.csv");
       while(f.good())
       {
           getline(f,usernam,',');
           getline(f,name,',');
           getline(f,hosname,',');
           getline(f,docname,',');
           getline(f,time,'\n');
           if(pname.compare(usernam)==0)
           {
               break;
           }
       }
       cout<<"Patient's Name:"<<" "<<name<<endl;
       cout<<"Hospital Name: "<<" "<<hosname<<endl;
       cout<<"Doctor name:"<<" "<<docname<<endl;
       cout<< "Alloted Date:"<<" "<<time<<endl;
    }
    //function for showing doctor details

        void admin::doctor_details(string did)
    {

        string id,name,spec,time;
        fstream fhandle1;
        fhandle1.open("kalinga.csv");
        while(fhandle1.good())
        {

            getline(fhandle1,id,',');
            getline(fhandle1,name,',');
            getline(fhandle1,spec,',');
            getline(fhandle1,time,'\n');

            if(did.compare(id)==0)
            {
                break;

            }

    }
    cout<<"Doctor Name"<<name<<endl;
    cout<<"Doctor Designation"<<spec<<endl;
    cout<<"Doctor Timing"<<time<<endl;
    }


    void patient::call(string username)
    {
        char *line; //change
        string date;
        cout<<"1.Book your appointment"<<endl;
        cout<<"2.cancel your appointment"<<endl;
        cout<<"3.logout"<<endl;
        cout<<"\n\nenter your choice"<<endl;
        int ch;
        cin>>ch;
        char s1[]="bhubaneswar";
            char s2[]="raipur";
            char s3[]="hyderabad";
            char city[30];
        if(ch==1)
        {
            fstream f;
            f.open("counte.csv",ios::in);

            string s;
            while(f.good())
            {

                getline(f,s,',');

            }
            const char* p=s.c_str();
            count=atoi(p);
            if(count<=2)
            {




            cout<<"Enter your city"<<endl;
            cin>>city;
            system("cls");
            if(!(strcmp(city,s1)))
                {
                     ifstream f;
                f.open("cuttack.csv");
                line=new char[sizeof(f)];
                f>>line;
                int i,c;
                char n[4], s[30];
                 while(!f.eof())
                  {
        //string g;
        //getline(f,g,',');
        i=0;
        c=0;
        for(;line[i]!=',';i++)
            n[c++]=line[i];
        n[c]='\0';
        i++;
        c=0;
        for(;line[i]!='*';i++)
            s[c++]=line[i];
        s[c]='\0';
        cout<<n<<"\t"<<s<<endl;
        delete [] line;
        line=new char[sizeof(f)];
        f>>line;

                  }
        cout<<"\n\nEnter the hospital serial number"<<endl;
        string  hid;
        cin>>hid;
        if(hid=="1")
        {
           ifstream f;
           f.open("kalinga.csv");
           cout<<"\n\nThe Doctor Details of Kalinga Hospital\n\nh"<<endl;
           while(f.good())
    {
        string m;
        getline(f,m,',');
        cout<<m;
    }


  string did;
  cout<<"\n\nEnter your choice : ";
  cin>>did;


    cout<<endl;
  date=show_date();
  book_appointment(hid,did,date,username);


        }
        }
            }
            else
            {
                cout<<"Appointments Exceded for today"<<endl;
            }

        }
                else if(!(strcmp(city,s2)))
                {
                    ifstream f;
                    f.open("raipur.csv");
                    while(f.good())
                    {
                        string m;
                        getline(f,m,',');
                        cout<<m;

                    }
                }
                else if(!(strcmp(city,s3)))
                {
                    ifstream f;
                    f.open("hyderabad.csv");
                    while(f.good())
                    {
                        string s;
                        getline(f,s,',');
                        cout<<s;

                    }
                }
                else{
                    cout<<"The city you have entered doesn't exist"<<endl;
                }

    }

    void doctor::user_login()
    {
        int flag=0;
        string pname,did,pass;
            fstream fhandle;
        	fhandle.open("doctor.csv",ios::in);
			while(fhandle)
			{
				getline(fhandle,did,',');
				getline(fhandle,pass,'\n');
				if(username.compare(did)==0 && password.compare(pass)==0 )
				{
				    flag=1;
				    break;
				}
				else
				continue;
			}
            if(flag==0)
            {
                cout<<"Login Unsuccessful"<<endl;
            }
            else
            {
                  system("cls");
                        cout<<"1. View patient details"<<endl;
                        cout<<"2. View doctors details"<<endl;
                        cout<<"3. View the Hospital Details"<<endl;
                        cout<<"4. Logout account"<<endl;
                        int choice;
                        cout<<"enter your choice"<<endl;
                        cin>>choice;
                        if(choice==1)
                        {
                            cout<<"Enter patient Id : ";
                            cin>>pname;
                            patient_details(pname);
                        }
                        else if(choice==2)
                        {
                            string did;
                            cout<<"Enter doctor id : ";
                            cin>>did;
                            doctor_details(did);
                        }
                        else if(choice==3)
                        {
                            cout<<"enter the patient name"<<endl;
                            cin>>pname;
                            hospital_details( pname);
                        }
            }



    }


            void admin::user_login()
            {
                string pname;
                if((username=="iiit") && (password=="iiitbbsr"))
                {
                    cout<<"admin login succesful"<<endl;

                    char city[30];
                    char s1[]="bhubaneswar";
                    char s2[]="raipur";
                    char s3[]="hyderabad";
                    cout<<"enter the city"<<endl;
                    cin>>city;
                    if(!(strcmp(city,s1)))
                    {
                    ifstream f;
                    f.open("cuttack.csv",ios :: out);
                    while(f.good())
                    {
                        string s;
                        getline(f,s,',');
                        cout<<s;
                    }
                    cout<<"\nenter the hospital serial number:"<<endl;
                    int i;
                    cin>>i;
                    if(i==1)
                    {
                        system("cls");
                        cout<<"1. View patient details"<<endl;
                        cout<<"2. View doctors details"<<endl;
                        cout<<"3. View the Hospital Details"<<endl;
                        cout<<"4. Logout account"<<endl;
                        int choice;
                        cout<<"enter your choice"<<endl;
                        cin>>choice;
                        if(choice==1)
                        {
                            cout<<"Enter patient Id : ";
                            cin>>pname;
                            patient_details(pname);
                        }
                        else if(choice==2)
                        {
                            string did;
                            cout<<"Enter doctor id : ";
                            cin>>did;
                            doctor_details(did);
                        }
                        else if(choice==3)
                        {
                            cout<<"enter the patient name"<<endl;
                            cin>>pname;
                            hospital_details( pname);
                        }
                    }
                    }
                     if(!(strcmp(city,s2)))
                    {
                    ifstream f;
                    f.open("raipur.csv",ios :: out);
                    while(f.good())
                    {
                        string s;
                        getline(f,s,',');
                        cout<<s;
                    }
                    }
                    if(!(strcmp(city,s3)))
                    {
                    ifstream f;
                    f.open("hyderabad.csv",ios :: out);
                    while(f.good())
                    {
                        string s;
                        getline(f,s,',');
                        cout<<s;
                    }
                    }
                     }
            }


int main()
{
   while(1)
   {
    cout<<"*****WELCOME TO HEALTH MONITERING SYSTEM GOVERNMENT OF INDIA******\n\n      ****************************************************"<<endl;
    cout<<"\n\n1.   PATIENT REGISTRATION"<<endl;
    cout<<"2.   PATIENT LOGIN"<<endl;
    cout<<"3.   ADMIN LOGIN"<<endl;
    cout<<"4.   DOCTOR LOGIN"<<endl;
    cout<<"5.   EXIT"<<endl;
    char ch;
    cout<<"\n\n\n ENTER YOUR CHOICE"<<endl;
    cin>>ch;
    system("cls");
    switch(ch)
    {
    case '1':
    {
          patient ob;
          ob.register1();
          cout<<"Any key to return";
            getch();
            system("cls");
          break;
    }

    case '2':
        {
            patient ob;
            ob=login1(ob);
            ob.user_login();
            cout<<"Any key to return";
            getch();
            system("cls");
            break;
        }
    case '3':
        {
            cout<<"                     ##################   ADMINISTRATION LOGIN     ##################\n\n\n"<<endl;
            admin ob1;
            ob1=login2(ob1);
            ob1.user_login();
            cout<<"Any key to return";
            getch();
            system("cls");
            break;
        }

         case '4':
        {
            cout<<"                     ##################   DOCTOR LOGIN     ##################\n\n\n"<<endl;
            doctor ob1;

            ob1=login3(ob1);
            ob1.user_login();
            cout<<"Any key to return";
            getch();
            system("cls");
            break;
        }
        case '5':
        {
            exit(0);
        }

    default:
        {
            break;
        }
    }


   }
return 0;
}

