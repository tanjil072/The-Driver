#ifndef myPolice_H_INCLUDED
#define myPolice_H_INCLUDED
#include"Score.h"
#include"myVariables.h"


struct buildingPosition{
	int x, y;
}buildingPos[12];

struct treePosition{
	int x, y;

}treePos[20];

struct Point{
	int x, y;

};

/*collision logic between the police car and the racing car1;called from police method;return type boolean*/
bool Collision1(Point policeCarLeft, Point policeCarRight, Point mainCar1Left, Point mainCar1Right){
	if (policeCarLeft.x > mainCar1Right.x || mainCar1Left.x > policeCarRight.x){
		return false;
	}
	if (policeCarLeft.y < mainCar1Right.y || mainCar1Left.y < policeCarRight.y){
		return false;
	}
	return true;
}

/*collision logic between the police car and the racing car2;called from police method;return type boolean*/
bool Collision2(Point policeCarLeft, Point policeCarRight, Point mainCar2Left, Point mainCar2Right){
	if (policeCarLeft.x > mainCar2Right.x || mainCar2Left.x > policeCarRight.x){
		return false;
	}
	if (policeCarLeft.y < mainCar2Right.y || mainCar2Left.y < policeCarRight.y){
		return false;
	}
	return true;
}


/*collision logic between the bullet and the racing car1;called from police method;return type boolean*/
bool Collision3(Point bulletLeft, Point bulletRight, Point mainCar1Left, Point mainCar1Right){
	if (bulletLeft.x > mainCar1Right.x || mainCar1Left.x > bulletRight.x){
		return false;
	}
	if (bulletLeft.y < mainCar1Right.y || mainCar1Left.y < bulletRight.y){
		return false;
	}
	return true;
}


/*collision logic between the bullet and the racing car2;called from police method;return type boolean*/
bool Collision4(Point bulletLeft, Point bulletRight, Point mainCar2Left, Point mainCar2Right){
	if (bulletLeft.x> mainCar2Right.x || mainCar2Left.x > bulletRight.x){
		return false;
	}
	if (bulletLeft.y < mainCar2Right.y || mainCar2Left.y < bulletRight.y){
		return false;
	}
	return true;
}




/*shows the backgrounds of the COP part and the controller ofall the logical methods of this part;called from iDraw;return type void type*/
void Police()
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

	//roadDevider
	iSetColor(255, 255, 255);

	for (int i = 0; i < 14; i++)
	{
		if (i<=6)
			iFilledRectangle(687, roadDiv[i], 15, roadDivHeight);
		else
			iFilledRectangle(854, roadDiv[i], 15, roadDivHeight);
	}
		
	
	/*if (mainCar1.carX >= mainCar2.carX && mainCar1.carX <= mainCar2.carX + mainCar2.carWidth)
	{
		mainCar1.carX = rand() % (roadX + roadWidth) + (mainCar2.carX + mainCar2.carWidth);
	}
	if (mainCar1.carX+mainCar1.carWidth >= mainCar2.carX && mainCar1.carX +mainCar1.carWidth <= mainCar2.carX + mainCar2.carWidth)
	{
		mainCar1.carX = rand() % roadX  + (mainCar2.carX-mainCar1.carWidth);
	}*/
	iShowImage(policeCarX, policeCarY, policeCarWidth, policeCarHeight, policeCarPic);
	iShowImage(mainCar1.carX, mainCar1.carY, mainCar1.carWidth, mainCar1.carHeight, mainCarsPic1);
	iShowImage(mainCar2.carX, mainCar2.carY, mainCar2.carWidth, mainCar2.carHeight, mainCarsPic2);

	Point policeCarLeft = { policeCarX, policeCarY + policeCarHeight };
	Point policeCarRight = { policeCarX + policeCarWidth, policeCarY };

	Point mainCar1Left = { mainCar1.carX, mainCar1.carY + mainCar1.carHeight };
	Point mainCar1Right = { mainCar1.carX + mainCar1.carWidth, mainCar1.carY };

	Point mainCar2Left = { mainCar2.carX, mainCar2.carY + mainCar2.carHeight };
	Point mainCar2Right = { mainCar2.carX + mainCar2.carWidth, mainCar2.carY };

	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::bullet left & right co-ordinate logic::::::::::::::::::::::::::::::::::::::://
	Point bulletLeft = { bulletX+12, bulletY + bulletHeight };
	Point bulletRight = { bulletX+bulletWidth-10, bulletY+bulletHeight };



	//:::::::::::::::::::::::::::::::::::::::::::::::::::Car to Car Front clash for car1::::::::::::::::::::::::::::::::::::::::::://
	if (Collision1(policeCarLeft, policeCarRight, mainCar1Left, mainCar1Right)){
		//ShowFire = 1;
		bulletFire = 0;
		
		
		//:::::::::::::::::::::: gameOver if any clash occurs ::::::::::::::::::::::::://
		iPauseTimer(0);
		PlaySound(0, 0, 0);
		GameoverScore = 1;
		MainScore = 0;
		
	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::Car to Car Front clash for car2::::::::::::::::::::::::::::::::::::::::::://
	if (Collision2(policeCarLeft, policeCarRight, mainCar2Left, mainCar2Right)){
		//ShowFire = 1;
		bulletFire = 0;
		
		
		//::::::::::::::::::::::::::::::::::::::::::::::: gameOver if any clash occurs :::::::::::::::::::::::::::::::::::::::::::::::://
		iPauseTimer(0);
		PlaySound(0, 0, 0);
		GameoverScore = 1;
		MainScore = 0;
		

	}

	



	//::::::::::::::::::::::::::::::::::::::::for bullet collision with cars & vanishing cars after showing fire::::::::::::::::::::::::::::::://


	if (Collision3(bulletLeft, bulletRight, mainCar1Left, mainCar1Right))
	{
		iShowImage(mainCar1.carX - 25, mainCar1.carY + 30, 110, 130, fire);
		
		
		if (bulletY > mainCar1.carY)
		{
			
			bulletY = 793;
			CarDamage += 1;
			if (CarDamage % 2 == 0)
			{
				second += 50;
			}
			mainCar1.carY = 794;
			mainCar1.carX = rand() % roadWidth + roadX;

		}
		
		iPauseTimer(0);
		
	}




	if (Collision4(bulletLeft, bulletRight, mainCar2Left, mainCar2Right))
	{
		
		iShowImage(mainCar2.carX - 25, mainCar2.carY + 30, 110, 130, fire);
		
		if (bulletY > mainCar2.carY)
		{
			
			bulletY = 793;
			CarDamage += 1;
			if (CarDamage % 2 == 0)
			{
				second += 50;
			}
			mainCar2.carY = 794;
			mainCar2.carX = rand() % roadWidth + roadX;
		}
		
		iPauseTimer(0);
		
		
	}

}



#endif // myPolice_H_INCLUDED