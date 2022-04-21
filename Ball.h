#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Ball //얘는 지가 알아서 움직이드라~
{
private:
	Vector2f originalPosition;
	
	Vector2f position;
	RectangleShape shape;

	float speed = 500.f;
	Vector2f dir;

public:
	Ball(float x, float y);

	FloatRect GetGlobalBounds();
	const RectangleShape& GetShape();
	
	void ReboundSides();
	void ReboundBatOrTop();
	void Reboundbottom();

	void Update(float dt);

};

