#ifndef MYHEADER_H_INCLUDED
#define MYHEADER_H_INCLUDED
#include"myVariables.h"


struct mainCars{

	int carX = roadX+ rand() % (roadWidth-25);
	//-carWidth - 10
	int carY = height;
	int carWidth = 62;
	int carHeight = 120;

}mainCar1, mainCar2,policeCar1,policeCar2;


/*moves down and repeat all objects in the background as well as road;called from iMain;a parameter of iSetTimer;return type void*/
void mainCarsChange()
{

	for (int i = 0; i < 14; i++)
	{
		roadDiv[i] -= roadSpeed;
	}

	for (int i = 0; i < 14; i++)
	{
		if (roadDiv[i] + roadDivHeight <= 0){
			roadDiv[i] = height;
		}
	}

	for (int i = 0; i < 12; i++)
	{
		buildingY[i] -= roadSpeed;
	}

	for (int i = 0; i < 12; i++)
	{
		if (buildingY[i] + buildingHeight <= 0)
		{
			buildingY[i] = height;
		}
	}


	for (int i = 0; i < 20; i++)
	{
		treeY[i] -= roadSpeed;
	}

	for (int i = 0; i < 20; i++)
	{
		if (treeY[i] + treeHeight[i] <= 0)
		{
			treeY[i] = height;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		rockY[i] -= roadSpeed;
	}
	for (int i = 0; i < 8; i++)
	{
		if (rockY[i] + rockHeight[i] <= 0)
		{
			rockY[i] = height;
		}
	}



	if (policeCarX+policeCarWidth >= roadX + roadWidth){
		policeCarX = roadX + roadWidth-policeCarWidth;
	}
	if (policeCarX <= roadX){
		policeCarX = roadX;
	}




	if (mainCarX + mainCarWidth >= roadX + roadWidth){
		mainCarX = roadX + roadWidth - mainCarWidth;
	}
	if (mainCarX <= roadX){
		mainCarX = roadX;
	}



	if (policeCar1.carY + policeCar1.carHeight <= 0)
	{
		policeCar1.carX = 521 + rand() % (501 - policeCar1.carWidth);
		
		policeCar1.carY = height;
	}
	else
		policeCar1.carY -= mainCarSpeed1;


	if (policeCar1.carY + policeCar1.carHeight + 10 == policeCar2.carY - 10)
		policeCar1.carY -= mainCarSpeed1 - 15;

	if (policeCar2.carY + policeCar2.carHeight <= 0)
	{
		policeCar2.carX = 521+rand() % (501-policeCar2.carWidth);
		policeCar2.carY = height;
	}
	else
		policeCar2.carY -= mainCarSpeed2;

	if (policeCar2.carY +policeCar2.carHeight+ 10 == policeCar1.carY -10)
		policeCar2.carY -= mainCarSpeed1 - 15;



	//Yellow Car logic
	
	
	if (mainCar1.carY + mainCar1.carHeight <= 0)
	{
		
		mainCar1.carX = 521 + rand() % (501-mainCar1.carWidth);
	    mainCar1.carY = height;
	}
	else
		mainCar1.carY -= mainCarSpeed1;

	if (mainCar1.carY+mainCar1.carHeight + 10 == mainCar2.carY-10)
		mainCar1.carY -= mainCarSpeed1 - 15;

		

	if (mainCar2.carY + mainCar2.carHeight <= 0)
	{
		mainCar2.carX = 521 + rand() % (501-mainCar2.carWidth);
	    mainCar2.carY = height;

	}
	else
		mainCar2.carY -= mainCarSpeed2;

	if (mainCar2.carY +mainCar2.carHeight+ 10 == mainCar1.carY -10)
	{
		mainCar2.carY -= mainCarSpeed1 - 10;
	}
		

}




#endif // MYHEADER_H_INCLUDED