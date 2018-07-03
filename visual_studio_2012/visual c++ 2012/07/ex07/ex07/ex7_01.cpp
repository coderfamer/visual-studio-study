#include <iostream>

using namespace std;

struct RECTANGLE
{
	int left;
	int top;

	int right;
	int bottom;
};

long Area(const RECTANGLE &aRect);
void MoveRect(RECTANGLE &aRect, const int &x, const int &y);

int main01()
{
	RECTANGLE Yard = {0, 0, 100, 120};
	RECTANGLE Pool = {30, 40, 70, 80};
	RECTANGLE Hut1, Hut2;

	Hut1.left = 70;
	Hut1.top = 10;
	Hut1.right = Hut1.left + 25;
	Hut1.bottom = 30;

	Hut2 = Hut1;
	MoveRect(Hut2, 10, 90);

	cout << "coordinates of hut2 are " << Hut2.left << ","
		<< Hut2.top << " and " << Hut2.right << "," << Hut2.bottom << endl;

	cout << "the area of the yard is " << Area(Yard) << endl;

	cout << "the area of the pool is " << Area(Pool) << endl;

	return 0;
}

long Area(const RECTANGLE &aRect)
{
	return (aRect.right - aRect.left) * (aRect.bottom - aRect.top);
}

void MoveRect(RECTANGLE &aRect, const int &x, const int &y)
{
	int length = aRect.right - aRect.left;
	int width = aRect.bottom - aRect.top;

	aRect.left = x;
	aRect.top = y;
	aRect.right = x + length;
	aRect.bottom = y + width;
}