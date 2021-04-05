#include <iostream>
#include <climits>
#include "Board.hpp"
using namespace std;

ariel::Board::Board(): start_of_row(UINT_MAX),end_of_row(0),start_of_colomn(UINT_MAX),end_of_colomn(0){}

void ariel::Board::post(unsigned int row, unsigned int col, Direction direction, const string &str){

    if(direction == Direction::Horizontal){
        if(this->board.size()<=row){
            this->board.resize(row+1);
        }
        unsigned int size = col+str.size();

        if(this->board.at(row).size() < size){
        this->board.at(row).resize(size,'_');
        }
        for(unsigned int i=0; i<str.size(); i++){
            this->board.at(row).at(col+i) = str.at(i);
        }
        if(row < this->start_of_row){
            this->start_of_row = row;
        }
        if(row > this->end_of_row){
            this->end_of_row = row;
        }
        if(this->start_of_colomn > col){
            this->start_of_colomn = col;
        }
        if(size > this->end_of_colomn){
            this->end_of_colomn = size;
        }           
    }else{
        unsigned int size = row+str.size();
        if(this->board.size()<size){
            this->board.resize(size);
        }
        for(unsigned int i=0;i<str.size();i++){
            if(this->board.at(row+i).size()<=col){
                this->board.at(row+i).resize(col+1,'_');
            }
            this->board.at(row+i).at(col) = str.at(i);
        }
        if(row<this->start_of_row){
            this->start_of_row = row;
        }
        if(size > this->end_of_row){
            this->end_of_row = size;
        }
        if(this->start_of_colomn > col){
            this->start_of_colomn = col;
        }
        if(this->end_of_colomn < col){    
            this->end_of_colomn = col;
        }
    }   
}

string ariel::Board::read(unsigned int row,unsigned int col, Direction direction, unsigned int len){
    if(len == 0){
        return "";
    }
    string result;
    if(direction == ariel::Direction::Horizontal){
        if(row >= this->board.size()){
            for(size_t i = 0; i<len;i++){
                result +='_';
            }
            return result;
        }
        if(this->board.at(row).size()<=col){
            for(size_t i = 0; i<len;i++){
                result +='_';
            }
            return result;
        }
        unsigned int i=0;
        for(;i<len && col+i<this->board.at(row).size();i++){
            result += this->board.at(row).at(col+i);
        }
        if(i<len){
            for(;i<len;i++){
                result += '_';
            }
        }
        return result;
        
    }
    if(row >= this->board.size()){
        for(size_t i = 0; i<len;i++){
            result +='_';
        }
        return result;
    }
    unsigned int i=0;
    for(;i<len && row+i<this->board.size(); i++){
        if(this->board.at(row+i).size() <= col){
            result += '_';
        }else{
            result += this->board.at(row+i).at(col);
        }
    }
    if(i < len){
        for(;i<len;i++){
            result +='_';
        }
    }
        return result;       
}

void ariel::Board::show()const{
    for(unsigned int i=start_of_row; i<end_of_row;i++){
        unsigned int j=start_of_colomn;
        for(;j<end_of_colomn && j < board.at(i).size(); j++){
            cout<<this->board.at(i).at(j);
        }
        if(j<end_of_colomn){
            for(;j<end_of_colomn;j++){
                cout<<'_';
            }
        }
        cout<<endl;
    }
}







