

#ifndef VILLIAN3_INCLUDED
#define VILLIAN3_INCLUDED
#include "variables.h"
#include "scores.h"

villian villian31[numbersOfVillian3];
villian boss[bossnumber];
int level_count_f = 0;

/*void villian31Movement(){
	for (int i = 0; i < numbersOfVillian3; i++){
		if (villian31[i].villian_show){
			iShowBMP2(villian31[i].villianX, villian31[i].villianY, level_3_sideattack[villian31[i].villian_index], 255);

		}
	}
}
*/
void bossMovement(){
	for (int i = 0; i < bossnumber; i++){
		if (boss[i].villian_show){
			iShowBMP2(boss[i].villianX, boss[i].villianY, level_3_villianattack[boss[i].villian_index], 0);

		}
	}
}

void setVillianVariables31(){
	int sum = 350;
	for (int i = 0; i < numbersOfVillian3; i++){
		villian31[i].villianX = screenWidth + sum;
		villian31[i].villianY = rand()%100;
		villian31[i].villian_index = rand() %5;
		villian31[i].villian_show = true;
		sum += 500;
	}
}

void setBossVariables(){
	int sum = 350;
	for (int i = 0; i < bossnumber; i++){
		boss[i].villianX = screenWidth + sum;
		boss[i].villianY = rand() % 100;
		boss[i].villian_index = rand() % 5;
		boss[i].villian_show = true;
		sum += 300;
	}
}

void villian31Show(){
	if (level == 3){
		if (!pause){
			for (int i = 0; i < numbersOfVillian3; i++){
				villian31[i].villianX -= 55;
				int sum = 0;
				if (villian31[i].villianX <= 0){
					villian31[i].villianX = screenWidth + sum;
					sum += 500;
				}
				villian31[i].villian_index++;

				if (villian31[i].villian_index >= 6){
					villian31[i].villian_index = 0;
				}
				if ((shurikenX >= villian31[i].villianX && shurikenX <= villian31[i].villianX + 82 || shurikenX + 68 >= villian31[i].villianX && shurikenX + 68 <= villian31[i].villianX + 82) && (shurikenY >= villian31[i].villianY && shurikenY <= villian31[i].villianY + 115 || shurikenY + 50 >= villian31[i].villianY && shurikenY + 50 <= villian31[i].villianY + 115)){
					
					level_count_f++;
						villian31[i].villian_show = false;
						score = score + 1;
	
				}
				if (villian31[i].villian_show){
					if (villian31[i].villianX >= heroCoordinateX&&villian31[i].villianX <= heroCoordinateX + 82)
					{
						attacked++;
						if (attacked == 3)
						{
							life2++;
							attacked = 0;
						}
						if (!pause){
							if (life2 >= 6){
								life2 = 0;
								//level = 0;
								gameState = 5;
							}
						}
					}
				}
			}
		}
	}
}

void bossShow(){
	if (level == 3){
		if (!pause){
			for (int i = 0; i < bossnumber; i++){
				boss[i].villianX -= 15;
				int sum = 0;
				if (boss[i].villianX <= 0){
					boss[i].villianX = screenWidth + sum;
					sum += 350;
				}
				boss[i].villian_index++;

				if (boss[i].villian_index >= 6){
					boss[i].villian_index = 0;
				}
				if ((shurikenX >= boss[i].villianX && shurikenX <= boss[i].villianX + 82 || shurikenX + 68 >= boss[i].villianX && shurikenX + 68 <= boss[i].villianX + 82) && (shurikenY >= boss[i].villianY && shurikenY <= boss[i].villianY + 115 || shurikenY + 50 >= boss[i].villianY && shurikenY + 50 <= boss[i].villianY + 115)){
					
					level_count_f++;
						boss[i].villian_show = false;
						score = score + 1;
			
				}
				if (boss[i].villian_show){
					if (boss[i].villianX >= heroCoordinateX&&boss[i].villianX <= heroCoordinateX + 82)
					{
						attacked++;
						if (attacked == 3)
						{
							life2++;
							attacked = 0;
						}
						if (!pause){
							if (life2 >= 6){
								life2 = 0;
								//level = 0;
								gameState = 5;
							}
						}
					}
				}
			}
		}
	}
}

#endif
