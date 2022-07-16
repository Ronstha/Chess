///Chess Engine Class Here
#include "Board.hpp"
#include "Moves.hpp"
class Engine{
    Board b;
    char gameState=1;
    char playerTurn=0;
    char check=0;
    public:
        Engine(){
            b.print_board();
            b.print_moves(1,1);

        }   

    

};