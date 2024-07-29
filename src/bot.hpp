#ifndef BOT
#define BOT

#include <string>
#include <map>
#include "search.hpp"
#include "position.hpp"
#include "move.hpp"

namespace engine
{
    static const std::map<MoveFlag, char> PROM_TO_CHAR = {
        {KNIGHT_PROM, 'n'},
        {KNIGHT_PROM_CAPTURE, 'n'},
        {BISHOP_PROM, 'b'},
        {BISHOP_PROM_CAPTURE, 'b'},
        {ROOK_PROM, 'r'},
        {ROOK_PROM_CAPTURE, 'r'},
        {QUEEN_PROM, 'q'},
        {QUEEN_PROM_CAPTURE, 'q'},
    };

    std::string moveToUci(Move move);

    class Bot
    {
    private:
        Position pos;
        SearchManager searchMan;

    public:
        Bot();

        Position getPosition();
        void setPosition(std::string fen);
        void makeTurn(std::string move);
        std::string chooseMove();
    };
}

#endif
