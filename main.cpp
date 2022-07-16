#include <iostream>
#include <math.h>
class Board;
class Engine;
class Piece;
class Box;
#include "Modules/Engine.hpp"
using namespace std;



int main(){
    cout << "BEGIN"<< endl;
    Engine e;
    e.game_loop();
    cout << "ENDED"<< endl;

}