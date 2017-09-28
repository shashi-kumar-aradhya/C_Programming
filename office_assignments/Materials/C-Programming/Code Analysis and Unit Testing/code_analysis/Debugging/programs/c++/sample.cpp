#include <iostream>

using namespace std;

class Invalid_month_err {
};
    
class Date {
    int d,m,y;
public:
    Date (int dd = 0, int mm = 0, int yy = 0);//constructor 

	void add_year (int n);
	void add_month (int n) throw (Invalid_month_err);
	void add_day (int t);
};

Date::Date(int dd, int mm, int yy)
{
    d = dd ;
	m = mm ;
	y = yy ;
}
void Date::add_year (int n)
{
    y += n;
}
void Date::add_month (int n)throw (Invalid_month_err)
{
   try{
    m += n;
	if (m > 12) throw Invalid_month_err();
   }
   catch (Invalid_month_err e){
    cout<<"Invalid addition to month\n";
   }
}
void Date::add_day (int n)
{
    d += n;
}
int main()
{
	cout<<"\nHello World in C++\n";
	Date *some_day = new Date(31,12,1980);
	some_day->add_month(2);
	delete some_day;
	return 0;
}
