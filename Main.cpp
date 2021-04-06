#include <vector>
#include <string>
#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"

int main(){
ariel::Board board;
board.post(100,100,ariel::Direction::Vertical,"buy a car");
board.post(103,97,ariel::Direction::Horizontal,"selling a house");
board.show();
board.post(105,102,ariel::Direction::Horizontal,"rent apartments");
board.post(100,105,ariel::Direction::Vertical,"English courses");
board.post(110,100,ariel::Direction::Horizontal,"programming lessons");
board.show();
}