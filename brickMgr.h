#pragma once
#include <SFML/Graphics.hpp>
#include "brick.h"

class brickMgr
{
private:
	brick* brickArray;
	int xCount;
	int yCount;
public:
	brickMgr(const int& xCount, const int& yCount);	//����� ī��Ʈ ��ŭ �����Ѵ�.
	~brickMgr();	//�迭 ��ü�� �����Ҵ��� �����Ѵ�. 
	
	FloatRect GetGlobalBounds(int i);

	const RectangleShape& GetShape(int i);

	void DeleteBrick(int idx);	//idx�� ����� �����Ҵ��� ����.

	
};

