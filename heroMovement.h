#ifndef HEROMOVEMENT_INCLUDED
#define HEROMOVEMENT_INCLUDED
#include "variables.h"
#include<iostream>

void Jump(){
	
	if (firing){
	iShowBMP2(shurikenX-90, shurikenY-70, f[0], 0);
	}
	
	

	if (jumpUp)
	{

		if (reverseStand){

			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herorevjump[0], 0);
			
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, heroattack[fireIndex], 0);
		}
		else{
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herojump[0], 0);
		}
	


	}


	else
	{
		if (reverseStand){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herorevjump[1], 0);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, heroattack[fireIndex], 0);
		}
		else{
			iShowBMP2(heroCoordinateX, heroCoordinateY + heroCoordinateJump, herojump[1], 0);
		}
	}

}

void Character(){
	if (firing){
		iShowBMP2(shurikenX-90, shurikenY-70, f[0], 0);
		
	}

	if (!standPosition){
		if (reverseStand)
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, herorevwalk[heroReverseIndex], 0);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroattack[fireIndex], 0);
		}
		else
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, herowalk[heroIndex], 0);
		}

		standCounter++;
		if (standCounter >= 10){
			standCounter = 0;
			standPosition = true;
			heroIndex = 0;
		}
	}
	else
	{
		if (reverseStand)
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroidle[1], 0);
		}
		else if (heroFire){
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroattack[fireIndex], 0);
		}
		else
		{
			iShowBMP2(heroCoordinateX, heroCoordinateY, heroidle[0], 0);
		}

	}
}


void jumpchange(){

	if (jump){

		if (jumpUp){

			heroCoordinateJump += 10;
			if (heroCoordinateJump >= JUMPLIMIT){

				jumpUp = false;

			}
		}
		else{
			heroCoordinateJump -= 10;

			if (heroCoordinateJump < 0){

				jump = false;

				heroCoordinateJump = 0;
			}
		}
	}


}


void fire_shuriken(){
	if (firing){
		for (int i = 0; i < 200; i++){
			shurikenX++;
			if (shurikenX>screenWidth){
				firing = false;
				shurikenX = heroCoordinateX + 100000000000000000;

			}
		}
	}
}
void fireCharacter(){
	if (heroFire){
		fireIndex++;
		if (fireIndex >= 2){
			fireIndex = 0;
			heroFire = false;
		}
	}

}



#endif