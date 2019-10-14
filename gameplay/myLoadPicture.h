#ifndef myLoadPicture_H_INCLUDED
#define myLoadPicture_H_INCLUDED
#include"myVariables.h"

/*loads all the pictures in this game;called from iMain;return type void*/
void loadPicture()
{

	menu = iLoadImage("menu2.png");
	play = iLoadImage("play.png");
	about = iLoadImage("about.png");
	controls = iLoadImage("controls.png");
	rank = iLoadImage("rank.png");
	back = iLoadImage("backButton.png");
	home = iLoadImage("home.png");
	gameOver = iLoadImage("gameOver.png");
	bullet = iLoadImage("bullet.png");
	fire = iLoadImage("fire.png");
	
	
	policeCarPic = iLoadImage("Cars/police2.png");
	mainCarPic = iLoadImage("Cars/mainCar.png");
	mainCarsPic1 = iLoadImage("Cars/mainCar2.png");
	mainCarsPic2 = iLoadImage("Cars/mainCar2.png");
	policeCarPic1 = iLoadImage("Cars/police.png");
	policeCarPic2 = iLoadImage("Cars/police.png");
	showMyScore = iLoadImage("rect.png");

	for (int i = 0; i < 12; i++)
	{
		building[i] = iLoadImage(buildingPic[i]);
	}

	for (int i = 0; i < 20; i++)
	{
		tree[i] = iLoadImage(treePic[i]);
	}

	for (int i = 0; i < 8; i++)
	{
		rock[i] = iLoadImage(rockPic[i]);
	}

	for (int k = 0; k < 5; k++)
	{
		Cover[k] = iLoadImage(CoverPic[k]);
	}


}

	







#endif // myLoadPicture_H_INCLUDED