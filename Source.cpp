#include <iostream>
using namespace std;

class MyComplex
{

public:
	MyComplex(double NewRe = 0, double NewIm = 0)
	{
		Re = NewRe;
		Im = NewIm;
	}

	MyComplex(MyComplex&a)
	{

	}
	double GetIm()
	{
		return Im;
	}
	double GetRe()
	{
		return Re;
	}
	int SetIm(double NewIm)
	{
		Im = NewIm;
		return 1;
	}
	int SetRe(double NewRe)
	{
		Im = NewRe;
		return 1;
	}
	MyComplex friend operator+ (MyComplex p1, MyComplex p2)
	{
		MyComplex c;
		c.SetRe(p1.GetRe() + p2.GetIm());
		c.SetIm(p1.GetIm() + p2.GetIm());
		return c;
	}
	MyComplex friend operator+ (int p1, MyComplex p2)
	{
		MyComplex c;
		c.SetRe(p1 + p2.GetRe());
		c.SetIm(p2.GetIm());
		return c;
	}

	MyComplex friend operator+(MyComplex p2, int p1)
	{
		return(p1 + p2);
	}
	MyComplex friend operator- (MyComplex p1, MyComplex p2)
	{
		MyComplex c;
		c.SetRe(p1.GetRe() - p2.GetRe()); c.SetIm(p1.GetIm() - p2.GetIm());
		return c;
	} MyComplex friend operator- (double p1, MyComplex p2)
	{
		MyComplex c;
		c.SetRe(p1 - p2.GetRe());
		c.SetIm(p2.GetIm());
		return c;
	} MyComplex friend operator- (MyComplex p2, double p1)
	{
		return (p1 - p2);
	} MyComplex friend operator* (MyComplex p1, MyComplex p2) {
		return MyComplex(p1.GetRe() * p2.GetRe() - p1.GetIm() * p2.GetIm(), p1.GetRe() * p2.GetIm() + p1.GetIm() * p2.GetRe());
	} MyComplex friend operator* (MyComplex p1, double p2) {
		return MyComplex(p1.GetRe() * p2, p1.GetIm() * p2);
	} MyComplex friend operator* (double p2, MyComplex p1) {
		return (p1 * p2);
	} ostream friend &operator << (ostream &os, MyComplex &b) {
		char action = (b.GetIm() > 0) ? '+' : ' '; return os << b.GetRe() << action << b.GetIm() << "*i";
	}

private:
	double Im, Re;

};
 void main()
{
	MyComplex a(2, 3), b(3, 4);
	MyComplex c(10);
	MyComplex d;
	d = a + b;
	d = 5 + a;
	d = a + 5;

	cout << d;
	system("Pause");
}