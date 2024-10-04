#pragma once

#include <iostream>
#include <vector>

namespace System {
	struct Block {
		int x;
		int y;
		bool flag;
		bool hovered;
		bool isOpened;
		int value;
	};

	const int EMPTY = 0;
	const int MINE = -1;

	bool gameOver = false;

	int xStep[8] = { 0,0,1,1,1,-1,-1,-1 };
	int yStep[8] = { 1,-1,0,1,-1,0,1,-1 };

	int boomXStep[4] = { 0,1,0,-1 };
	int boomYStep[4] = { 1,0,-1,0 };

	long long initTime = 0;
	std::vector<std::vector<Block>> map(10,std::vector<Block>(10));
	class MineSweepSystem {
	public:
		void InitMap() {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					map[i][j] = Block{ i,j,false,false,false,EMPTY };
				}
			}
			for (int i = 0; i < 10; i++) {
				int randomX, randomY;
				do {
					randomX = Util::GetRangeRandom(0, 8);
					randomY = Util::GetRangeRandom(0, 8);
				} while (map[randomX][randomY].value == MINE);

				map[randomX][randomY].value = MINE;


				for (int i = 0; i < 8; i++) {
					int xNode = randomX + xStep[i];
					int yNode = randomY + yStep[i];
					if (xNode >= 0 && xNode <= 9 && yNode >= 0 && yNode <= 9) {
						if (map[xNode][yNode].value != -1) {
							map[xNode][yNode].value += 1;
						}

					}
				}
			}
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++) {
					std::cout << map[i][j].value << "  ";
				}
				std::cout << std::endl;
			}
		}
		void OpenBlock(int x, int y) {
			if (map[x][y].isOpened) {
				return;
			}
			map[x][y].isOpened = true;
			map[x][y].flag = false;
			if (map[x][y].value == -1) {
				GameOver();
				return;
			}
			if (map[x][y].value == 0) {
				Boom(x,y);
			}
		}
		void MarkFlag(int x, int y) {
			if (map[x][y].isOpened) {
				return;
			}
			map[x][y].flag = !map[x][y].flag;
		}
		void Boom(int x,int y) {
			for (int i = 0; i < 4; i++) {
				int nextX = boomXStep[i] + x;
				int nextY = boomYStep[i] + y;
				if (nextX >= 0 && nextX <= 9 && nextY >= 0 && nextY <= 9) {
					if (map[nextX][nextY].value != -1) {
						OpenBlock(nextX, nextY);
					}

				}
			}
		}
		void GameOver() {
			gameOver = true;
			initTime = Utility::GetMillsTime();
		}

	};
}
