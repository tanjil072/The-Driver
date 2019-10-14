#ifndef myRacer_H_INCLUDED
#define myRacer_H_INCLUDED

#include"Score.h"
#include"myPolice.h"


/*/*collision logic between the main car and the police car1;called from police method;return type boolean*/
bool Collision5(Point mainCarLeft, Point mainCarRight, Point policeCar1Left, Point policeCar1Right){
	if (mainCarLeft.x > policeCar1Right.x || policeCar1Left.x > mainCarRight.x){
		return false;
	}
	if (mainCarLeft.y < policeCar1Right.y || policeCar1Left.y < mainCarRight.y){
		return false;
	}
	return true;
}

/*/*collision logic between the main car and the police car2;called from police method;return type boolean*/
bool Collision6(Point mainCarLeft, Point mainCarRight, Point policeCar2Left, Point policeCar2Right){
	if (mainCarLeft.x > policeCar2Right.x || policeCar2Left.x > mainCarRight.x){
		return false;
	}
	if (mainCarLeft.y < policeCar2Right.y || policeCar2Left.y < mainCarRight.y){
		return false;
	}
	return true;
}

/*shows the backgrounds of the Racer part and the controller of all the logical methods of this part;called from iDraw;return type void type*/
void Racer()
{

	
	iSetColor(51, 25, 0);
	iFilledRectangle(0, 0, 1522, 792);


	for (int i = 0; i < 12; i++)
	{
		iShowImage(buildingX[i], buildingY[i], 200, buildingHeight, building[i]);

	}
	for (int i = 0; i < 20; i++)
	{
		if (i == 4)
			treeWidth = 150;
		else if (i == 11)
			treeWidth = 120;
		else if (i == 13)
			treeWidth = 150;
		else if (i == 14)
			treeWidth = 120;
		else if (i == 17)
			treeWidth = 120;

		iShowImage(treeX[i], treeY[i], treeWidth, treeHeight[i], tree[i]);
		treeWidth = 100;
	}

	for (int i = 0; i < 8; i++)
	{
		iShowImage(rockX[i], rockY[i], rockWidth[i], rockHeight[i], rock[i]);
	}

	iSetColor(32, 32, 32);
	iFilledRectangle(roadX, roadY, roadWidth, roadHeight);
	iSetColor(193, 193, 5);
	iFilledRectangle(roadX + 10, roadY, 15, roadHeight);
	iFilledRectangle(roadX + roadWidth - 25, roadY, 15, roadHeight);

	iSetColor(255, 255, 255);
	for (int i = 0; i < 14; i++)
	{
		if (i <= 6)
			iFilledRectangle(687, roadDiv[i], 15, roadDivHeight);
		else
			iFilledRectangle(854, roadDiv[i], 15, roadDivHeight);
	}

	iShowImage(mainCarX, mainCarY, mainCarWidth, mainCarHeight, mainCarPic);
	iShowImage(policeCar1.carX, policeCar1.carY, policeCar1.carWidth, policeCar1.carHeight, policeCarPic1);
	iShowImage(policeCar2.carX, policeCar2.carY, policeCar2.carWidth, policeCar2.carHeight, policeCarPic2);

	Point mainCarLeft = { mainCarX, mainCarY + mainCarHeight };
	Point mainCarRight = { mainCarX + mainCarWidth, mainCarY };

	Point policeCar1Left = { policeCar1.carX, policeCar1.carY + policeCar1.carHeight };
	Point policeCar1Right = { policeCar1.carX + policeCar1.carWidth, policeCar1.carY };

	Point policeCar2Left = { policeCar2.carX, policeCar2.carY + policeCar2.carHeight };
	Point policeCar2Right = { policeCar2.carX + policeCar2.carWidth, policeCar2.carY };


	if (Collision5(mainCarLeft, mainCarRight, policeCar1Left, policeCar1Right))
	{
		iPauseTimer(0);
		GameoverScore = 1;
		MainScore = 0;
	}
	if (Collision6(mainCarLeft, mainCarRight, policeCar2Left, policeCar2Right))
	{
		iPauseTimer(0);
		GameoverScore = 1;
		MainScore = 0;
	}










}
#endif // myRacer_H_INCLUDED