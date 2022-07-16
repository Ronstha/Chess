///Chess Engine Class Here
/*
GAMESTATE
0-ENDED
1-RUNNING
2-SELECTION
*/
#include "Board.hpp"
#include "Moves.hpp"

class Engine{
    Board b;
    char gameState;
    char playerTurn;
    char check;
    public:
        Engine(){
            gameState=1;
            playerTurn=0;
            check=0;
      
     

        }   
        void game_loop(){
            while(this->gameState!=0){
                if(playerTurn==0){
                    std::cout << "White's Turn" << std :: endl;
                }              
                else{
                    std::cout << "Black's Turn" << std :: endl;

                }
                if(this->check==1){
                    std::cout << "CHECKMATE!!!!" << std :: endl;
                    
                }
                b.print_board();
                b.generateMoves(this->playerTurn);
                if(b.countMoves(this->playerTurn)==0){
                        this->gameState=0;
                    if(this->check){
                        if(this->playerTurn==0){
                            std:: cout << "BLACK WINS!!";
                        }
                        else{
                            std:: cout << "WHITE WINS!!";

                        }
                    }
                    else{
                            std:: cout << "STALEMATE";
                    }
                    break;

                }

                this->piece_selection();
                this->switch_turn();



            }

        }
        void switch_turn(){
            this->playerTurn=!playerTurn;            
        }

        void piece_selection(){
                this->gameState=2;
                 ChessPiece pice;
                int x,y;
                int prom;
                bool available;
                Box current;
                while (this->gameState==2)
                {
                std::cout << "SELECT PIECE:" << std :: endl;
                std::cin>>x>>y;
                if((x>=0 && x<8)&&(y>=0 && y<8)){         
                 pice= b.get_chesspiece(x,y);
                 if((pice.rank>0)&&(pice.color==this->playerTurn)){
                    if(pice.totalmoves==0){
                    std :: cout<<"No Move Available"<<std::endl;

                        continue;
                    }
                   std :: cout<<"Available Moves:"<<pice.totalmoves<<std::endl;
                   
                   for(int i=0;i<pice.totalmoves;i++){
                        pice.moves[i].display();
                   }
                while(x<8 && y<8){
                    std::cout << "ENTER MOVE(to deselct enter [9 9]):" << std :: endl;
                    std::cin>>x>>y;
                     if((x>=0 && x<8)&&(y>=0 && y<8)){      
                        current=Box(x,y);
                        available=false;
                          for(int i=0;i<pice.totalmoves;i++){
                            if(current==pice.moves[i]){
                                available=true;
                                break;
                            }
                        
                   }
                   if(available){
                    this->check=b.move_piece(pice,current);
                    if(pice.rank==1 && (current.x==0|current.x==7)){
                        std::cout << "PROMOTE PAwN:"<<std::endl<<"1.Rook 2.Knight 3.Bishop 4.Queen"<<std::endl;
                        while (1)
                        {
                            std::cin>> prom;
                            if (prom>0 && prom<5){
                                b.get_chesspiece(current.x,current.y).promoteTo(prom);
                                break;
                            }
                            else{
                                  std::cout << "INVALID INPUT"<<std::endl;
                            }
                        }
                        
                    }
                    this->gameState=1;
                    break;
                   }
                   else{
                       std::cout << "INVALID MOVES" << std :: endl;
                   }
                     }


                }
                   
                  



                 }
              
                }
                else{
                    std::cout << "INVALID SELECTION" << std :: endl;
                    
                }
                }
                
                
            
        }

};