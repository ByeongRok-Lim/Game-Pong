#include "brickMgr.h"

brickMgr::brickMgr(const int& xCount, const int& yCount)
	:xCount(xCount), yCount(yCount)
{
	brickArray = new brick[xCount * yCount];

	float xPos = 1920.f *0.5f - 120.f * (xCount / 2.f);
	float yPos = 0.f;
	int temp = 0;
	for (int i = 0; i < yCount; i++)
	{
		for (int j = temp; j < xCount + temp; j++)
		{
			brickArray[j].SetPosition(xPos, yPos);
			xPos += 120.f;
		}
		temp += xCount;
		yPos += 70.f;
		xPos = 1920.f * 0.5f - 120.f * (xCount * 0.5f);
	}
}

brickMgr::~brickMgr()
{
	delete[] brickArray;
}

FloatRect brickMgr::GetGlobalBounds(int i)
{
	return brickArray[i].GetGlobalBounds();
}

const RectangleShape& brickMgr::GetShape(int i)
{

	return brickArray[i].GetShape();
}

void brickMgr::DeleteBrick(int idx)
{
}