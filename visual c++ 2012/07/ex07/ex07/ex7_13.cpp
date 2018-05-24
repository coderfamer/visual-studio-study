#include <iostream>

using namespace std;

class CBox
{
public:
	~CBox()
	{
		cout << "Destroctor called. " << endl;
	}

	explicit CBox(double lv = 1.0, double bv = 1.0, double hv = 1.0)
	{
		cout << "Constructor called." << endl;
		m_length = lv;
		m_width = bv;
		m_height = hv;
	}



	double Volume() const
	{
		return m_length * m_width * m_height;
	}

	bool Compare(CBox *pBox) const
	{
		if (!pBox)
			return 0;
		return this->Volume() > pBox->Volume();
	}

private:
	double m_length;
	double m_height;
	double m_width;
};


int main()
{
	CBox boxes[5];
	CBox match(2.2, 1.1, 0.5);
	CBox cigar(8.0, 5.0, 1.0);
	CBox *pB1(&cigar);
	CBox *pB2(nullptr);

	cout << "address of cigar is " << pB1 << endl
		<< "Volume of cigar is " << pB1->Volume() << endl;

	pB2 = &match;
	if (pB2->Compare(pB1))
		cout << "match is greater than cigar" << endl;
	else 
		cout << "math is less than or  equal to cigar " << endl;

	pB1 = boxes;
	boxes[2] = match;
	cout << "Volume of boxes[2] is " <<(pB1 + 2)->Volume() << endl;
	return 0;
}