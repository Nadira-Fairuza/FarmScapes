#include "bitmap_loader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
@@ - 23, 6 + 24, 7 @@
#define STATE_CREDITS 3
#define STATE_LOADING 4
#define STATE_TOWN 5
#define STATE_LEVEL_2 6

int gameState = STATE_MENU;
int loadingTimer = 0;
@@ - 44, 10 + 46, 26 @@ int level2Unlocked = 0, level3Unlocked = 0;
#include "loading.h"
#include "updatecropgrowth.h"
#include "drawlevel1.h"
#include "animalgrowth.h"  // Included first so MAX_ANIMALS_PER_TYPE is defined
#include "drawlevel2.h"
#include "drawTown.h"

int playerGold = 0;

// --- ANIMAL STATE VARIABLES FOR LEVEL 2 ---
int henCount = 0, cowCount = 0, sheepCount = 0;
struct Animal hens[MAX_ANIMALS_PER_TYPE];
struct Animal cows[MAX_ANIMALS_PER_TYPE];
struct Animal sheep[MAX_ANIMALS_PER_TYPE];

int countFeed = 5;
int countEgg = 0, countMilk = 0, countWool = 0;
int feedBuyPrice = 5;
int eggSellPrice = 15, milkSellPrice = 30, woolSellPrice = 45;
int henBuyPrice = 30, cowBuyPrice = 100, sheepBuyPrice = 70;
int selectedRanchTool = 1; // 1 = Feed, 2 = Collect
int isRanchMarketOpen = 0;

// CROP PRICES (MAX PROFIT = $5 EACH)
int riceBuyPrice = 5, riceSellPrice = 10;
int tomatoBuyPrice = 15, tomatoSellPrice = 20;
@@ - 92, 6 + 110, 7 @@ void iDraw() {
	else if (gameState == STATE_LOADING) drawLoading();
	else if (gameState == STATE_TOWN) drawTown();
	else if (gameState == STATE_LEVEL_1) drawLevel1();
	else if (gameState == STATE_LEVEL_2) drawLevel2();
	else if (gameState == STATE_SETTINGS) drawSettings();
	else if (gameState == STATE_CREDITS) drawCredits();
}
@@ - 130, 7 + 149, 7 @@ void iMouse(int button, int state, int mx, int my) {
	return;
}
		}
		// 4. LEVEL 1 STATE
		// 4. LEVEL 1 STATE (Completely untouched behavior)
		else if (gameState == STATE_LEVEL_1) {
			if (showCapWarning) {
				showCapWarning = 0;
				@@ - 313, 6 + 332, 108 @@ void iMouse(int button, int state, int mx, int my) {
				}
			}
		}

		// 5. LEVEL 2 STATE (Ranch Mouse Controls)
		else if (gameState == STATE_LEVEL_2) {
			// Market Button
			if (mx >= 430 && mx <= 530 && my >= 552 && my <= 586) {
				isRanchMarketOpen = !isRanchMarketOpen;
				return;
			}
			// Back to Town Button
			else if (mx >= 545 && mx <= 655 && my >= 552 && my <= 586) {
				gameState = STATE_TOWN;
				return;
			}
			// Menu Button
			else if (mx >= 670 && mx <= 780 && my >= 552 && my <= 586) {
				gameState = STATE_MENU;
				return;
			}

			// Ranch Market Overlay Interactions
			if (isRanchMarketOpen) {
				if (mx >= 600 && mx <= 680 && my >= 90 && my <= 120) {
					isRanchMarketOpen = 0;
					return;
				}
				// Sell Produce
				if (mx >= 320 && mx <= 385 && my >= 395 && my <= 417 && countEgg > 0) {
					countEgg--; playerGold += eggSellPrice;
				}
				else if (mx >= 320 && mx <= 385 && my >= 345 && my <= 367 && countMilk > 0) {
					countMilk--; playerGold += milkSellPrice;
				}
				else if (mx >= 320 && mx <= 385 && my >= 295 && my <= 317 && countWool > 0) {
					countWool--; playerGold += woolSellPrice;
				}
				// Buy Feed & Animals
				else if (mx >= 610 && mx <= 675 && my >= 395 && my <= 417 && playerGold >= feedBuyPrice) {
					playerGold -= feedBuyPrice; countFeed++;
				}
				else if (mx >= 610 && mx <= 675 && my >= 345 && my <= 367 && playerGold >= henBuyPrice) {
					for (int i = 0; i < MAX_ANIMALS_PER_TYPE; i++) {
						if (!hens[i].isAlive) { playerGold -= henBuyPrice; hens[i].isAlive = 1; henCount = (i + 1 > henCount) ? i + 1 : henCount; break; }
					}
				}
				else if (mx >= 610 && mx <= 675 && my >= 295 && my <= 317 && playerGold >= cowBuyPrice) {
					for (int i = 0; i < MAX_ANIMALS_PER_TYPE; i++) {
						if (!cows[i].isAlive) { playerGold -= cowBuyPrice; cows[i].isAlive = 1; cowCount = (i + 1 > cowCount) ? i + 1 : cowCount; break; }
					}
				}
				else if (mx >= 610 && mx <= 675 && my >= 245 && my <= 267 && playerGold >= sheepBuyPrice) {
					for (int i = 0; i < MAX_ANIMALS_PER_TYPE; i++) {
						if (!sheep[i].isAlive) { playerGold -= sheepBuyPrice; sheep[i].isAlive = 1; sheepCount = (i + 1 > sheepCount) ? i + 1 : sheepCount; break; }
					}
				}
				return;
			}