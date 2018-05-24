#include <iostream>

using namespace std;

class CBox
{
public:
	double m_length;
	double m_width;
	double m_height;
};

int main02()
{
	CBox box1;
	CBox box2;

	double boxVolume = 0.0;
	box1.m_height = 18.0;
	box1.m_length = 78.0;
	box1.m_width = 24.0;

	box2.m_height = box1.m_height - 10;
	box2.m_length = box1.m_length/2.0;
	box2.m_width = 0.25 * box1.m_length;

	boxVolume = box1.m_height * box1.m_length * box1.m_width;

	cout << "Volume of box1 = " << boxVolume << endl;

	cout << "box2  has sides which total " 
		<< box2.m_height + box2.m_length + box2.m_width << "inches." << endl;

	cout << "A cbox object occupies " << sizeof box1 << " bytes" << endl;

	return 0;
}