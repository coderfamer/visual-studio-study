#include <iostream>

using namespace std;

class CBox
{
public:
	static int objectCount;

	CBox(double lv, double bv = 1.0, double hv = 1.0)
	{
		cout << "Constructor called." << endl;
		m_length = lv;
		m_width = bv;
		m_height = hv;
		objectCount++;
	}

	CBox()
	{
		cout << "Default constructor called." << endl;
		m_length = m_width = m_height = 1.0;
		objectCount++;
	}

	double Volume() const
	{
		return m_length * m_width * m_height;
	}

private:
	double m_length;
	double m_height;
	double m_width;
};

int CBox::objectCount = 0;

int main12()
{
	CBox boxes[5];
	CBox cigar(8.0, 5.0, 1.0);

	cout << "Number of objects (throuth class ) = " << CBox::objectCount << endl;

	cout << "Number of objects (through object) = " << boxes[2].objectCount << endl;

	return 0;
}