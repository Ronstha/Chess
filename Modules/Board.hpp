//Board Class here
#include "Pieces.hpp"
// #include "Moves.hpp"
#include <string>
ChessPiece get_piece(char a){
    ChessPiece temp;
    if(a<97){
        temp.set_color(0);
        a+=32;
    }else{
        
        temp.set_color(1);
    }
    switch (a)
    {
    case 'p':
        temp.set_rank(1);
        break;
    case 'r':
        temp.set_rank(2);
        break;
    case 'n':
        temp.set_rank(3);
        break;
    case 'b':
        temp.set_rank(4);
        break;
    case 'q':
        temp.set_rank(5);
        break;
    case 'k':
        temp.set_rank(6);
        break;
    
    default:
        break;
    }
    // temp.display_string();
    return temp;

}
class Board{
    ChessPiece chessBoard[8][8];
    ChessPiece captured[2][16];
     friend class ChessPiece;
    // friend class Engine;
    public:
      Board(){
        parse_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
        // parse_fen("rnbqkbnr/1ppppppp/8/p7/8/4PQ2/PPPP1PPP/RNB1KBNR");
      }
      void parse_fen(std:: string fen){
        int x=0;
        int y=0;
        for (int i=0;i<fen.length();i++){
            if(fen[i]=='/'){
                x+=1;
                y=0;
            }
            else if((fen[i]-48)>0 && (fen[i]-48)<9){
                y+=(fen[i]-48);
                
            }
            else{
                // std::cout << x <<" "<<y ;
                chessBoard[x][y]=get_piece(fen[i]);
                chessBoard[x][y].setPosition(x,y);
                y+=1;
            }
        }

        


      }
      void print_board(){
           std:: cout<<std::endl<<std::endl;
        int i,j;
        std::cout<<"  0 1 2 3 4 5 6 7"<< std::endl;
        for(i=0;i<8;i++){
            std::cout <<i <<" ";
            for( j=0;j<8;j++){
                chessBoard[i][j].display_string();
            }          
            std:: cout << std::endl;
        }        
      }
    //   void print_moves(int m,int n){
    //    std:: cout<<std::endl<<std::endl;
    //     chessBoard[m][n].generateLegalMoves(*this);

    //     chessBoard[m][n].moves;
    //     int i,j;
    //     for(i=0;i<8;i++){
    //         for( j=0;j<8;j++){
    //             chessBoard[i][j].display_string();
    //             for(int l=0;l<chessBoard[m][n].totalmoves;l++){
    //                 if(chessBoard[m][n].moves[l].x==i && chessBoard[m][n].moves[l].y==j){
    //                     std :: cout <<"\b\bx ";
    //                     break;
    //                 }
    //             }
    //         }          
    //         std:: cout << std::endl;
    //     }        
    //   }
      int capture_insertIndex(int color){
        for(int i=0;i<16;i++){
            if(captured[color][i].rank==0){
                return i;
            }
        }
        return 15;
      }
      Box get_king_position(int color){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                    if((chessBoard[i][j].rank==6)&&(chessBoard[i][j].color==color)){
                        return chessBoard[i][j].position;
                    }
            }            
            
        }
        return Box();
      }
      ChessPiece get_chesspiece(int x,int y){
        return chessBoard[x][y];

      }
      int move_piece(ChessPiece pc,Box b,bool legal=true){
        if(legal){
        int isLegal=0;
            for(int i=0;i<pc.totalmoves;i++){
                if(pc.moves[i]==b){
                    isLegal=1;
                    break;
                }
            }
        
            if(!isLegal) return 2;
        }
        ChessPiece capturedpiece=chessBoard[b.x][b.y];
        if(capturedpiece.rank>0){
            captured[!pc.color][this->capture_insertIndex(!pc.color)]=capturedpiece;
                        
        }
  
        chessBoard[pc.position.x][pc.position.y]=ChessPiece ();        
        pc.position=b;
        chessBoard[b.x][b.y]=pc;
        if(legal){
          
          return this->check_checkmate(!pc.color);

        }
        else{
          return this->check_checkmate(pc.color);

        }
      



      }
      bool check_checkmate(int player){

        Box king=this->get_king_position(player);
         for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(chessBoard[i][j].color!=player){
                    chessBoard[i][j].generatepseudoMoves(*this);
                 for(int k=0;k<chessBoard[i][j].totalmoves;k++){
                    if(chessBoard[i][j].moves[k]==king){
                     
                        return 1;
                    }
                 }   
                }
            }            
            
        }
        
        return 0;
      }
      void generateMoves(int player){
       for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(this->chessBoard[i][j].color==player){

                   this->chessBoard[i][j].generateLegalMoves(*this);
                }
            }    
      }
      }
      int countMoves(int player){
        int moves=0;
       for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(this->chessBoard[i][j].color==player){

                  moves+=chessBoard[i][j].totalmoves;
                }
            }    

      }
      return moves;
      }
};
