// test617.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
class CMyDate
{
private:
	int year;
	int month;
	int day;
	int check();

public:
	CMyDate();
	~CMyDate();
	CMyDate(int y, int m, int d);
	int setDate(int y, int m, int d);
	void displayDate();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
	CMyDate addDate(CMyDate &od);         
	CMyDate operator + (CMyDate &otemp);   
	CMyDate operator + (const int &d);
	void print() const;
	
};
CMyDate CMyDate::operator +(CMyDate &otemp)
{
	CMyDate temp;
	temp.setDate(year + otemp.year, month + otemp.month, day + otemp.day);
	return temp;
}
CMyDate CMyDate::operator + (const int &d)
{
	CMyDate temp;
	temp.setDate(year, month, day + d);
	return temp;
}
CMyDate CMyDate::addDate(CMyDate &od)
{
	CMyDate temp;
	temp.setDate(year + od.year, month + od.month, day + od.day);
	return temp;
}
CMyDate::CMyDate()
{
	year = 2019;
	month = 1;
	day = 1;
	cout << "CMyDate's constructor called." << endl;
}
CMyDate::~CMyDate()
{
	cout << "CMyDate's constructor called." << endl;
}
CMyDate::CMyDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();
	cout << "CMyDate's constructor called." << endl;
}
int CMyDate::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	check();
	return 0;

}
void CMyDate::displayDate()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
int CMyDate::check()
{
	int flatYearDays[13] = { 31,31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[13] = { 31,31,29,31,30,31,30,31,31,30,31,30,31 };
	int temp = 1;
	while (temp == 1 && month != 0 && day != 0)
	{
		if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		{
			if (leapYearDays[month] < day)
			{
				day = day - leapYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		else
		{
			if (flatYearDays[month] < day)
			{
				day = day - flatYearDays[month];
				month++;
				temp = 1;
			}
			else
			{
				temp = 0;
			}
		}
		if (month > 12)
		{
			year++;
			month = month - 12;
			temp = 1;
		}
	}

	return 0;
}
int CMyDate::getYear()
{
	return year;
}
int CMyDate::getMonth()
{
	return month;
}
int CMyDate::getDay()
{
	return day;
}
void CMyDate::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}
void CMyDate::print() const
	{
		cout << year<<month<<day<< endl;
	}
class CMeter :public CMyDate
{
private:
	int meters;
public:
	CMeter();
	CMeter(int i, int j);
	~CMeter();
	void print() const;
};
CMeter::CMeter()
{
	meters = 2;
	cout << "CMeters's default constructor called." << endl;
}
CMeter::CMeter(int i, int j)
{
	meters = i;
	cout << "CMeters's constructor called." << endl;
}
CMeter::~CMeter()
{
	cout << "CMeters's constructor called." << endl;
}
void CMeter::print() const
{
	CMyDate::print();
	cout << meters << endl;
}
int main()
{
	CMeter obj(1, 4);
	obj.print();
    return 0;
}

