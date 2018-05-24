#include <iostream>

using namespace std;

class CBox
{
public:
	explicit CBox(double lv, double bv = 1.0, double hv = 1.0)
	{
		cout << "Constructor called!!!" << endl;
		m_length = lv;
		m_width = bv;
		m_height = hv;
	}

	CBox()
	{
		cout << "Default constructor called." << endl;
		m_length = m_width = m_height = 1.0;
	}

	double Volume() const
	{
		return m_length * m_width * m_height;
	}

private:
	double m_length;
	double m_width;
	double m_height;
};


int main1111()
{
	CBox boxes[5];
	CBox cigar(8.0, 5.0, 1.0);

	cout << "volume of boxes[3] = " << boxes[3].Volume() << endl
		<< "Volume of cigar = " << cigar.Volume() << endl;

	return 0;
}
