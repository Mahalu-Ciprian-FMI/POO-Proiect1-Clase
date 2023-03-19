#include <iostream>
#include <istream>
#include <cstring>
#include <string>
#include <typeinfo>
using namespace std;

class Materie
{
	string denumire;
	bool optional;
public:
	Materie materie()
	{

	}
	Materie()
	{
	}
	Materie(string denumire2, bool optional2)
	{
		denumire = denumire2;
		optional = optional2;
	}
	 const bool& operator==(const Materie& obiect)
	{
		if (denumire == obiect.denumire && optional==obiect.optional)
			return 1;
		return 0;
	}
	 friend ostream& operator<<( ostream&, Materie&);
};
ostream& operator<<( ostream& out, Materie& obiect)
{
	cout << obiect.denumire << " " << obiect.optional;
	return out;
}
class Student
{
	int nrMatricol, grupa;
	string nume;
public:
	Student()
	{

	};
	Student(int nrmat, string numele, int grup)
	{
		nrMatricol = nrmat;
		nume = numele;
		grupa = grup;
	}
	friend  istream& operator>>(istream& in,  Student& obj);
	friend  ostream& operator<<(ostream& out, Student& obj);
};
istream& operator >>(istream& in,  Student& obj)
{
	cout << "Introduceti numarul matricol" << endl;
	in >> obj.nrMatricol;
	cout << "Introduceti numele studentului" << endl;
	in >> obj.nume;
	cout << "Introduceti numarul grupei" << endl;
	in >> obj.grupa;
	return in;
}
 ostream& operator<<(ostream& out, Student& obj)
{
	 out << obj.nrMatricol << " " << obj.nume << " " << obj.grupa << endl;
	return out;
}
class Curs
{
	Materie mat;
	int nrStudenti;
	Student St[];
public:
	Curs(Materie matr)
	{
		mat = matr;
	}
	Curs& operator+=(Student& elev)
	{
		St[++nrStudenti] = elev;
		return *this;
	}
	Curs& operator+(Student& elev)
	{
		St[++nrStudenti] = elev;
		return *this;

	}
	Curs& operator=( Curs& curs)
	{
		return curs;
	}
	friend ostream& operator<<(ostream&, Curs&);
};
ostream& operator<<(ostream& out, Curs& curs)
{
	out << curs.nrStudenti;
	return out;
}
int main()
{
	Materie m1("POO", 1), m2("Pedagogie", 1), m3;
	if (m1 == m2)
		cout << "Cursuri identice" << endl;
	else
		cout << "Denumiri diferite" << endl;
	Student s1(12, "Ionescu", 133), s2, s3;
	cin >> s2;
	cout << s1 << s2;
	Curs c1(m1);
	c1 += s1;
	c1 = c1 + s2;
	Curs c2 = c1;
	//m3 = c2.mat();   -nu ruleaza;
	cout<<m3;

	return 0;
}