void ChessPiece :: knight (int ix,int iy,Board &b){
    if(this->rank!=3) return;
    int x=this->position.x+ix;
    int y=this->position.y+iy;
 
    if(x>=0 && x<8 && y>=0 && y<8){
        //exist in board
       if (b.chessBoard[x][y].rank==0||(b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color)){
    
        moves[totalmoves]=Box(x,y);
      
        totalmoves+=1;
       }
    }
}
void ChessPiece :: rook (int ix,int iy,Board &b){
    if(this->rank!=2 && this->rank!=5) return;
    int x=this->position.x;
    int y=this->position.y;
    while ((iy==0 && x!=int(((ix+1)*7)/2))||(ix==0 && y!=int(((iy+1)*7)/2)))
    {
        x+=ix;
        y+=iy;
        if(b.chessBoard[x][y].rank==0 || ( b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color)){
              moves[totalmoves]=Box(x,y);
              // moves[totalmoves].display();
        totalmoves+=1;
        if(b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color)break;
        }
        else{
            break;
        }
    }
    
    
}

void ChessPiece :: bishop (int ix,int iy,Board &b){
    if(this->rank!=4 && this->rank!=5) return;
     int x=this->position.x;
    int y=this->position.y;
    // std::cout<<x;

    while(x!=int(((ix+1)*7)/2) && y!=int(((iy+1)*7)/2)){
        x+=ix;
        y+=iy;
        // std::cout<<x;
        if(b.chessBoard[x][y].rank==0 || ( b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color)){
 moves[totalmoves]=Box(x,y);
        totalmoves+=1;
        if(b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color)break;
        }
        else{
            break;
        }
    }

}
void ChessPiece :: generatepseudoMoves(Board &b){
    totalmoves=0;
    int x,y;
  
  switch (this->rank){
    case 1:
        if(this->position.x==0 || this->position.x==7){
            break;
        }
       //pawn  
      
       //forward movement
       x=this->position.x-1+(2*this->color);
       y=this->position.y;
       if(b.chessBoard[x][y].rank==0){
        moves[totalmoves]=Box(x,y);
        totalmoves+=1;
       }

       if(this->position.x==(6-(this->color*5))){
        x=this->position.x-2+(4*this->color);
        y=this->position.y;
       if(b.chessBoard[x][y].rank==0){
        moves[totalmoves]=Box(x,y);
        totalmoves+=1;
       }
       }

       //left // right
       y=this->position.y-1;
       if((b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color)||b.enpasant==Box(x,y)){
        moves[totalmoves]=Box(x,y);
        totalmoves+=1;
       }
       y=this->position.y+1;
       if((b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color)||b.enpasant==Box(x,y) ){
        moves[totalmoves]=Box(x,y);
        totalmoves+=1;
       }
      break;
    case 2:
    //rook
  
  //up movement
this->rook(1,0,b);

  //down movement
this->rook(-1,0,b);
  
  //left movement
this->rook(0,-1,b);
  
  //right movement
this->rook(0,1,b);
      break;
    case 3:
    //knight
    //2forward left
        this->knight(2,-1,b);
    //2forward right
        this->knight(2,1,b);
    //2backward right
        this->knight(-2,-1,b);
    //2backward left
        this->knight(-2,1,b);
    //2right forward
        this->knight(1,2,b);
    //2right backward
        this->knight(-1,2,b);
    //2left forward
        this->knight(1,-2,b);
    //2left backward
        this->knight(-1,-2,b);


    
      break;
    case 4:
    //bishop

    //forward right
        this->bishop(1,1,b);
    //forward left
        this->bishop(1,-1,b);
    //backward right
        this->bishop(-1,1,b);
    //backward left
        this->bishop(-1,-1,b);


      break;
    case 5:
    //queen
      //up movement
this->rook(1,0,b);

  //down movement
this->rook(-1,0,b);
  
  //left movement
this->rook(0,-1,b);
  
  //right movement
this->rook(0,1,b);
    //forward right
        this->bishop(1,1,b);
    //forward left
        this->bishop(1,-1,b);
    //backward right
        this->bishop(-1,1,b);
    //backward left
        this->bishop(-1,-1,b);




      break;
    case 6:
    //king
 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            x=this->position.x-1+i;
            y=this->position.y-1+j;
            if(x>=0 && x<8 && y>=0 && y<8){
    if(b.chessBoard[x][y].rank!=0 && b.chessBoard[x][y].color!=this->color ){
        moves[totalmoves]=Box(x,y);
        totalmoves+=1;
       }
            }
            
        }
    }
    

    


      break;
    default:
      break;
  }  

}
void ChessPiece :: removeMoves(int pos){
  this->totalmoves-=1;
  this->moves[pos]=this->moves[this->totalmoves];
  

}
void ChessPiece :: generateLegalMoves(Board &b){
  Board temp;
 
  this->generatepseudoMoves(b);
  int total=this->totalmoves;
  for(int k=0;k<total;k++){
    temp=b;
  
    if(temp.move_piece(*this,this->moves[k],false)){
      this->removeMoves(k);
    }

    
  }


}