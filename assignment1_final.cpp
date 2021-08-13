#include<bits/stdc++.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include<map>

using namespace std;

static string g_id;
static string g_name;
static string g_dob;

class pro{
	
public:
	void _cr(int a){
		HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h,a);
	}	
	void _stay(){		cout<<"\n Press any key to Continue.\n";  getch();		}
	
	void _clr(){	system("CLS");		}
	
	void _pstar(){
		_cr(1);
    	cout<<"##################################\n";
		_cr(7);
	}
	int _choice(){
		int ch;
		cout<<"\nEnter your Choice :- ";
		cin>>ch;
//		cout<<"\n";
		return ch;
	}
	
	void _login(){
		char pd[50];
		int a1=0;
		_cr(3);cout<<"############################################\n";_cr(7);
			   cout<<"#   PLEASE ENTER YOUR DETAILS TO SIGN IN   #\n";
 		_cr(3);cout<<"############################################\n";_cr(7);
		int count;
		string user_id,pwd,u,p,n,d;
		cout<<"\nUSERID : ";
		cin>>user_id;
		cout<<"\nPASSWORD : ";
		while(pd[a1-1]!='\r')
		{
			pd[a1]=getch();
			if(pd[a1-1]!='\r'){cout<<"*";
			}
			a1++;
		}
		pd[a1-1]='\0';
		//cin>>pwd;
		pwd=pd;
		ifstream input("SHOP_DB.txt");
		while(input>>u>>p>>n>>d){
			if(u==user_id && p==pwd)
			{
				count=1;
				break;
			}
		}
		g_id=u;
		g_name=n;
		g_dob=d;
		input.close();
		if(count==1)
		{
			_cr(3);cout<<"\n-------------------------------------------\n";_cr(7);
			cout<<"HELLO ";_cr(10);cout<<n;_cr(7);cout<<" LOGIN SUCCESSFUL.\n";
			_cr(3);cout<<"-------------------------------------------\n";_cr(7);
		}
		else{
			_cr(3);cout<<"\n------------------------------------------------------------------\n";_cr(7);
			_cr(4);cout<<"PLEASE CHECK CREDENTIALS or IF NOT SIGNEDUP THEN SIGNUP FIRST.\n";
			_cr(3);cout<<"------------------------------------------------------------------\n";_cr(7);
		}
	}
	
	void _register(){
		char pd[50];
		int a1=0;
		_cr(3);cout<<"############################################\n";_cr(7);
		cout<<"#   PLEASE ENTER YOUR DETAILS TO REGISTER  #\n";
		_cr(3);cout<<"############################################\n";_cr(7);
		string user_id,pwd,name,dob;
		cout<<"\nEnter User ID(email) : ";
		cin>>user_id; 
		cout<<"\nEnter Password : ";
		while(pd[a1-1]!='\r')
		{
			pd[a1]=getch();
			if(pd[a1-1]!='\r'){cout<<"*";
			}
			a1++;
		}
		pd[a1-1]='\0';
		pwd=pd;
		cout<<"\n\nEnter User Name : ";
		cin>>name;
		cout<<"\nEnter Date of Birth : ";
		cin>>dob;
		ofstream reg("SHOP_DB.txt",ios::app);
		reg<<user_id<<' '<<pwd<<' '<<name<<' '<<dob<<"\n";
		_cr(3);cout<<"-------------------------------------------\n";_cr(7);
		_cr(10);cout<<"\tREGISTRATION SUCCESSFULL.\n";_cr(7);
		_cr(3);cout<<"-------------------------------------------\n";_cr(7);	
	}
	
	void _shop(int z,int k ,int ch)
	{
		string S;
		int l;
		double a1=0,f_am=0,gst=0;
		ofstream cart("CART.txt",ios::app);
		if(z==1 && k==1)	// M clothing	
		{
			string s;
			int a,d;
			fstream input;
			input.open("M_C.txt",ios::in);
			if(ch==1)	//regular
			{
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(12)<<"PRICE"<<setw(17)<<"DISCOUNT\n";
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d==0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(11)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
			}
			else	//dicounted
			{
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(11)<<"PRICE"<<setw(20)<<"DISCOUNT\n";_cr(7);
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d>0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(15)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
			}
				input.open("M_C.txt",ios::in);
				_cr(3);cout<<"\n Enter ITEM Name you want to purchase : ";_cr(7);
				cin>>S;
				while(input>>s>>a>>d)
				{
					if(S==s)
					{
						a1=a;
						a1=a-(a*d)/100;
						if(a1<=1000)
							gst=(a1*5)/100;
						else
							gst=(a1*12)/100;
						f_am=a1+gst;
						cart<<s<<" "<<a<<" "<<d<<" "<<gst<<" "<<f_am<<"\n";
						_cr(10);cout<<"\n ITEM Added Successfully.\n";_cr(7);
						break;
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
		}
		if(z==1 && k==2)	// M Footaware
		{
			string s;
			int a,d;
			fstream input;
			input.open("M_F.txt",ios::in);
			if(ch==1)	//regular
			{
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(11)<<"PRICE"<<setw(17)<<"DISCOUNT\n";
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d==0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(11)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();	
			}
			else	//dicounted
			{
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(11)<<"PRICE"<<setw(17)<<"DISCOUNT\n";
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d!=0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(11)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();	
			}
				input.open("M_F.txt",ios::in);
				_cr(3);cout<<"\n Enter ITEM Name you want to purchase : ";_cr(7);
				cin>>S;
				while(input>>s>>a>>d)
				{
					if(S==s)
					{
						a1=a;
						a1=a-(a*d)/100;
						if(a1<=500)
							gst=(a1*5)/100;
						else
							gst=(a1*18)/100;
						f_am=a1+gst;
						cart<<s<<" "<<a<<" "<<d<<" "<<gst<<" "<<f_am<<"\n";
						_cr(10);cout<<"\n ITEM Added Successfully.\n";_cr(7);
						break;
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();	
		}
		if(z==2 && k==1)// W clothing
		{
			string s;
			int a,d;
			fstream input;
			input.open("W_C.txt",ios::in);
			if(ch==1)	//regular
			{
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(11)<<"PRICE"<<setw(17)<<"DISCOUNT\n";
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d==0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(11)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
			}
			else	//dicounted
			{	
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(11)<<"PRICE"<<setw(17)<<"DISCOUNT\n";
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d!=0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(11)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
			}
				input.open("W_C.txt",ios::in);
				_cr(3);cout<<"\n Enter ITEM Name you want to purchase : ";_cr(7);
				cin>>S;
				while(input>>s>>a>>d)
				{
					if(S==s)
					{
						a1=a;
						a1=a-(a*d)/100;
						if(a1<=1000)
							gst=(a1*5)/100;
						else
							gst=(a1*12)/100;
						f_am=a1+gst;
						cart<<s<<" "<<a<<" "<<d<<" "<<gst<<" "<<f_am<<"\n";
						_cr(10);cout<<"\n ITEM Added Successfully.\n";_cr(7);
						break;
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();	
		}
		if(z==2 && k==2)	// W footware.
		{
			string s;
			int a,d;
			fstream input;
			input.open("W_F.txt",ios::in);
			if(ch==1)	//regular
			{
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(11)<<"PRICE"<<setw(17)<<"DISCOUNT\n";
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d==0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(11)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
			}
			else	//dicounted
			{	_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				_cr(3);cout<<"ITEMS_NAME"<<setw(11)<<"PRICE"<<setw(17)<<"DISCOUNT\n";
				_cr(12);cout<<"-----------------------------------------------------\n";_cr(7);
				while(input>>s>>a>>d)
				{
					if(d!=0)
					{
						l=s.length();
						l=20-l;	
						cout<<s<<setw(l)<<"Rs."<<a<<setw(11)<<d<<"%"<<"\n";
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
			}
				input.open("W_F.txt",ios::in);
				_cr(3);cout<<"\n Enter ITEM Name you want to purchase : ";_cr(7);
				cin>>S;
				while(input>>s>>a>>d)
				{
					if(S==s)
					{
						a1=a;
						a1=a-(a*d)/100;
						if(a1<=500)
							gst=(a1*5)/100;
						else
							gst=(a1*18)/100;
						f_am=a1+gst;
						cart<<s<<" "<<a<<" "<<d<<" "<<gst<<" "<<f_am<<"\n";
						_cr(10);cout<<"\n ITEM Added Successfully.\n";_cr(7);
						break;
					}
				}
				_cr(12);cout<<"-----------------------------------------------------";_cr(7);
				input.close();
		}
	}
	void d_cart()
	{
		string s;
		int a,d,l,f=0;
		double f_amt,gst,bill=0;
		ifstream cart("CART.txt");
		_cr(10);cout<<"\nITEMS IN YOUR CART \n";
		_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);_cr(4);
		cout<<"PRODUCT"<<setw(15)<<"Amount"<<setw(15)<<"Discount."<<setw(12)<<"GST APP."<<setw(15)<<"NetAmount."<<"\n";
		_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);
		while(cart>>s>>a>>d>>gst>>f_amt){
			l=s.length();
			l=19-l;
			cout<<s<<setw(l)<<" Rs."<<a<<setw(9)<<d<<"%"<<setw(12)<<"Rs."<<gst<<" \t"<<"Rs."<<f_amt<<"\n";
			bill+=f_amt;
			f=1;
		}
		if(f!=0){
		_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);
		if(bill!=0)
			cout<<"                                    Amount to pay is  : Rs."<<bill<<"\n";
		_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);
		}
		else{
			_cr(4);cout<<"\t\t\tCART is EMPTY.\n";
			_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);
		}
		
	}
	
	void dlt_item(){
		string s,S;
		//ofstream ofs;
		int a,d,f=0;
		double f_amt,gst;
		_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);
		_cr(3);cout<<"Please Enter Item name to delete : ";_cr(7);
		cin>>S;
		fstream cart,temp;
		temp.open("Temp.txt",ios::app);
		cart.open("CART.txt",ios::in);
		while(cart>>s>>a>>d>>gst>>f_amt)
		{
			if(S==s){}
			else
				temp<<s<<" "<<a<<" "<<d<<" "<<gst<<" "<<f_amt<<"\n";
			f=1;	
		}
		cart.close();
		temp.close();
		remove("CART.txt");
		rename("Temp.txt","CART.txt");
		
//		ofs.open("CART.txt", std::ofstream::out | std::ofstream::trunc);
//		ofs.close();
//		//rename("Temp.txt","CART.txt");
//		temp.open("Temp.txt",ios::in);
//		cart.open("CART.txt",ios::app);
//		while(temp>>s>>a>>d>>gst>>f_amt)
//		{
//			cart<<s<<" "<<a<<" "<<d<<" "<<gst<<" "<<f_amt<<"\n";
//		}
//		ofs.open("Temp.txt", std::ofstream::out | std::ofstream::trunc);
//		ofs.close();
		if(f!=0){
		_cr(10);cout<<"ITEM DELETED SUCCESSFULLY \n";_cr(7);
		_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);
		}
		else{
			_cr(10);cout<<"NO ITEM IN CART TO DELETE \n";_cr(7);
			_cr(1);cout<<"------------------------------------------------------------------\n";_cr(7);
		}	
	}
	
	void placeOrder(){
		if(g_id[0]=='\0'){
			_cr(1);cout<<"---------------------------------------------\n";_cr(7);
			_cr(4);cout<<"Please Login First to Place Order.\n";_cr(4);
			_cr(1);cout<<"---------------------------------------------\n";_cr(7);
		}
		else{
			_cr(1);cout<<"-------------------------------------------------------\n";_cr(7);
			cout<<"Thanks for Purchase  ";_cr(10);cout<<g_name;_cr(7);cout<<"  Have a good Day.\n";
			_cr(1);cout<<"-------------------------------------------------------\n";_cr(7);
			remove("CART.txt");
		}
	}	
};

int main()
{
	pro obj;
	int ch,k,z;
	SHOPPING:
		obj._clr();
		obj._cr(1);
		obj._pstar();
    	cout<<"#   WELCOME TO SHOPPING PORTAL   #\n";
    	obj._pstar();
		cout<<"\n1. ACCOUNT\n2. SHOP.\n3. CHECKOUT. \n4. EXIT.\n";
    	ofstream ofs;
		ch=obj._choice();
    	
		switch(ch){
    		case 1:goto ACCOUNT; break;
    		case 2:goto SHOP; break;
    		case 3:goto CHECKOUT; break;
    		case 4:	remove("CART.txt");
					//ofs.open("CART.txt", std::ofstream::out | std::ofstream::trunc);
					//ofs.close();
					exit(0); 
					break;
    		default:	cout<<"\nINVALID CHOICE\n";obj._stay(); goto SHOPPING;
		}
		
		ACCOUNT:
			obj._clr();//obj._pstar();
			obj._cr(3);cout<<"##################################\n";obj._cr(7);
			cout<<"#     WELCOME TO ACCOUNT MENU    #\n";
			obj._cr(3);cout<<"##################################\n";obj._cr(7);
			//obj._pstar();
			cout<<"\n1. SIGN_IN.\n2. SIGN_UP.\n3. BACK.\n";
			ch=obj._choice();
			switch(ch){
    			case 1:obj._clr(); obj._login(); break;
    			case 2:obj._clr();	obj._register(); break;
    			case 3:	goto SHOPPING; break;
				default:	cout<<"\nINVALID CHOICE\n"; obj._stay(); goto ACCOUNT; 
    		}
			obj._stay();goto ACCOUNT;
			
		SHOP:
			obj._clr();
			obj._cr(12);cout<<"##################################\n";obj._cr(7);
			cout<<"#      WELCOME TO SHOP MENU     #\n";
			obj._cr(12);cout<<"##################################\n";obj._cr(7);
			cout<<"\n1. MEN.\n2. WOMEN.\n3. BACK.\n";
			ch=obj._choice();
			z=ch;
			switch(ch){
    			case 1: goto c_f; break;
    			case 2:	goto c_f; break;
    			case 3: goto SHOPPING; break;
    			default:	cout<<"\nINVALID CHOICE\n"; obj._stay(); goto SHOP; 
    		}
			obj._stay();goto SHOP;
			
		CHECKOUT:
			obj._clr();obj._pstar();
			cout<<"#     WELCOME TO CHECKOUT MENU    #\n";
			obj._pstar();
			obj.d_cart();
			cout<<"1. PLACE ORDER.\n2. DELETE ITEM.\n3. BACK.\n";
			ch=obj._choice();
			switch(ch){
    			case 1:  obj.placeOrder(); obj._stay(); break;
    			case 2:	obj.dlt_item();obj._stay(); break;
    			case 3: goto SHOPPING;
    			default:	cout<<"\nINVALID CHOICE\n"; obj._stay(); goto CHECKOUT; 
    		}
			goto CHECKOUT;
		
		c_f:
			obj._clr();
			obj._cr(12);cout<<"##############################\n";obj._cr(7);
			cout<<"#  WHAT ARE YOU LOOKING FOR. #\n";
			obj._cr(12);cout<<"##############################\n\n";obj._cr(7);
			cout<<"1. CLOTHING.\n2. FOOTWEAR.\n3. BACK.\n";
			ch=obj._choice();
			k=ch;
			switch(ch){
				case 1: goto r_d;  break;
				case 2: goto r_d ; break;
				case 3: goto SHOP;
				default: cout<<"\nINVALID CHOICE.\n"; obj._stay(); goto c_f; 
			}
			goto c_f;
		
		r_d:
			obj._clr();
			obj._cr(12);cout<<"###########################\n";obj._cr(7);
			cout<<"#  SELECT YOUR PREFRENCE. #\n";
			obj._cr(12);cout<<"###########################\n\n";obj._cr(7);
			cout<<"1. REGULAR ITEMS.\n2. DISCOUNTED ITEMS.\n3. BACK.\n";
			ch=obj._choice();
			switch(ch){
				case 1:  cout<<"\n";obj._shop(z,k,ch); obj._stay(); break;
				case 2:  cout<<"\n";obj._shop(z,k,ch); obj._stay(); break;
				case 3: goto c_f;
				default: cout<<"\nINVALID CHOICE.\n"; obj._stay(); goto r_d; 
			}
			goto r_d;

    return 0;
}