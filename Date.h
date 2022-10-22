#pragma once

#include <iostream>

using namespace std;

class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int monthDayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return monthDayArray[month];
		}
	}
	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	// 赋值运算符重载
  // d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d) 
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	// 析构函数
	~Date()
	{
		_year = _month = _day = 0;
	}
	// 日期+=天数
	Date& operator+=(int day) 
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}
	// 日期+天数
	Date operator+(int day)
	{
		Date ret(*this);
		return ret += day;
	}
	// 日期-=天数
	Date& operator-=(int day)
	{
		_day -= day;
		while (_day < 0)
		{
			_day += GetMonthDay(_year, _month - 1);
			_month--;
			if (_month == 0)
			{
				_year--;
				_month = 13;
			}
		}
		return *this;
	}
	// 日期-天数
	Date operator-(int day)
	{
		Date ret(*this);
		return ret -= day;
	}
	// 前置++
	Date& operator++()
	{
		*this+=1;
		return *this;
	}
	// 后置++
	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}
	// 后置--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}
	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}
	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		return false;
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
		{
			return true;
		}
		return false;
	}
	// >=运算符重载
	bool operator >= (const Date& d)
	{
		if (*this > d || *this == d)
		{
			return true;
		}
		return false;
	}
	// <运算符重载
	bool operator < (const Date& d)
	{
		if (*this >= d)
		{
			return false;
		}
		return true;
	}
	// <=运算符重载
	bool operator <= (const Date& d)
	{
		if (*this > d)
		{
			return false;
		}
		return true;
	}
	// !=运算符重载
	bool operator != (const Date& d)
	{
		if (*this == d)
		{
			return false;
		}
		return true;
	}
	//int GetMonthDayS(int year, int month)
	//{
	//	int monthDayArray[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	//	{
	//		return 60;
	//	}
	//	else
	//	{
	//		return monthDayArray[month];
	//	}
	//}
	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max(*this);
		Date min(d);
		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int n = 0;
		while (max != min)
		{
			++n;
			++min;
		}
		return n * flag;
	}
private:
	int _year;
	int _month;
	int _day;
};