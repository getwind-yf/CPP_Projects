//
// Menu.h
// Created by dongfrank on 2020/4/19.

#include<string>
#include<iostream> 
#include<iomanip> 
using namespace std; 

//定义日期类，存年月日及小时
#ifndef DATE_H 
#define DATE_H 
class Date 
{
private:
	int year, month, day, hour; 

public: 
	Date(); 
	Date(int y, int m,int d,int h); 
	bool operator == (Date date2);  //overload == ？ 
	int getYear();  //声明函数 declaration 
	int getMonth();
	int getDay();
	int getHour(); 
	void setYear(int); 
	void setMonth(int); 
	void setDay(int);
	void setHour(int);  
		
};  //注意class后面需要增加分号 
#endif 

#ifndef _Menu_h_
#define _Menu_h_
class Menu 
{
protected: 
	std::string dishName, dishID; 
	double price; 
public: 
	Menu();  // 构造函数 
	Menu(string dishName, string dishID, double price); 
	void setDishName(string); 
	void setDishID(string); 
	void setPrice(double); 
	string getDishName(); 
	string getDishID(); 
	double getPrice();

};

#endif

//Order类存有用户名、地址、电话、数量、日期、确认状态 
#ifndef ORDER_H
#define ORDER_H 
class Order:public Menu  //类的定义？？
{
private: 
	string customerName,adress,phone;
	int num; 
	Date bookDate;
	bool modify; 
public: 
	Order();
	Order(string dishName, string dishID, double price, string customerName, string adress, string phone, Date bookDate); 
	Order(string dishName, string dishID, double price) ; 
	const bool operator == (Order order2); 
	Order(Menu,int);
	string getCustomerName(); 
	string getAdress(); 
	string getPhone(); 
	Date getBookDate(); 
	bool getModify();
	int getNum();
	bool setCustomerName(string customerName);
	bool setAdress(string adress);
	bool setPhone(string phone);
	bool setnum(int num);
	bool setBookDate(Date bookDate); 
	void setModify();  
		
}; 
#endif 