#pragma once
#include "Direction.hpp"
#include <vector>
#include <string>


namespace ariel{

    class Board
    {
    private:
        std::vector<std::vector<char>> board;
        uint start_of_row;
        uint start_of_colomn;
        uint end_of_colomn; 
    public:
        Board();
        void post(unsigned int r,unsigned int c, Direction d,const std::string &str);
        std::string read(unsigned int r,unsigned int c, Direction d, unsigned int len);
        void show() const;
    };
    
}