#include <iostream>
#include <fstream> 
#include <cstring> 
#include <string> 
#include <vector> 
#include "Menu.h" 
#include "User.h" 
using namespace std; 
fstream finout; 
vector<Order> order; 
vector<Menu> menu; 

void seviceForSeller(); 
void seviceForBuyer(); 

int main()
{
	string n; 
	bool success = 0; 
	cout<<setw(55)<<"Welcome to the MyBooking system! " <<endl; 
	cout<< "---------------------"<<endl; 
	cout<<right;
	cout<<endl<<setw(25)<<"1.Buyer"<<setw(15)<<"2.Seller"<<setw(15)<<"3.Exit"<<endl; 
	while(cin>>n)
	{
		order.clear();
		menu.clear();
		if(n!="1" && n!="2")
		{
			cout<<endl<<"Invalid number! Please input again : "<<endl; 
			cout<<endl<<setw(25)<<"1.Buyer"<<setw(15)<<"2.Seller"<<setw(15)<<"3.Exit"<<endl; 
			continue; 
		}
		if(n=="1") seviceForBuyer(); 
		else seviceForSeller();
		cout<<right;
		cout<<endl<<setw(25)<<"1.Buyer"<<setw(15)<<"2.Seller"<<setw(15)<<"3.Exit"<<endl; 
		
	}
	return 0; 
}

//用于读取文件中的菜单
Menu inputMenu
{
	Menu iMenu; 
	string dishID, dishName; 
	double price=-1; 
	finout>> dishID;
	if(dishID == " "|| dishID == "\n"){
		iMenu.setDishID("-1"); 
		return iMenu; 
	}
	finout>>dishName >>price; 
	if(price<0 || price>100000){
		iMenu.setDishID("-1"); 
		return iMenu;
	}
	iMenu.setDishID(dishID);
	iMenu.setDishName(dishName);
	iMenu.setPrice(price);
	return iMenu; 
}

//用于读取文件中的订单 
Order inputOrder()
{
	string dishID,dishName,name,adress,phone;
	double price=-1; 
	int year,month,day,hour,modify,num; 
	finout>>dishID; 
	if(dishID == " " || dishID =="\n") 
	{
		Order iOrder;
		iOrder.setDishID("-1"); 
		return iOrder; 
	}
	finout>>dishName>>price>>num>>name>>adress>>phone; 
	if(price<0 || price>100000){
		Order iOrder;
		iOrder.setDishID("-1"); 
		return iOrder;
	}
	finout>>year>>month>>day>>hour>>modify; 
	Date date(year,month,day,hour);
	Order iOrder(dishName,dishID,price,name,adress,phone,date); 
	iOrder.setnum(num);
	if(!modify) iOrder.setModify();
	return iOrder; 
}

//卖家 
void seviceForSeller()
{
	Seller iSeller; 
	Order iOrder; 
	Menu iMenu; 
	string password; 
	finout.open("password.txt", ios::in); 
	if(finout.fail())
	{
		cout<<endl<<"The system can't find the file!"<<endl; 
		return;
	}
	finout>>password;
	finout.close();
	iSeller.setPassword(password);
	cout<<endl<<"Please input your password(default is 888888) : "; 
	string str; 
	int num=5; 
	cin>>str; 
	while(num-- && str != iSeller.getPassword())
	{
		cout<<endl<<"The password is wrong!\n Please input again: "; 
		cin>>str; 
	}
	if(num<=0)
	{
		cout<<endl<<"You have input wrong password five times! "; 
		return; 
	}
	cout<<endl<<"Please choose the function you want: " << endl; 
	cout<<left; 
	cout<<endl<<"           "<<setw(30)<<"1. Append menu"<<setw(20)<<"2. Cancel menu"<<endl;
	cout<<"           "<<setw(30)<<"3. Inquire"<<setw(20)<<"4.Modify"<<endl;
	cout<<"           "<<setw(30)<<"5.Set password"<<setw(20)<<"6.Main Menu"<<endl;
	string choice; 
	while(cin>>choice)
	{
		if(choice == "6")
		{
			return; 
		}
		if(choice !=)
	}
}