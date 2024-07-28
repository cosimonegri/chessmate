#ifndef PERFT
#define PERFT

#include <iostream>
#include <cstdint>
#include "position.hpp"
#include "generator.hpp"

namespace engine
{

    uint64_t perft(Position &pos, int depth, bool root = true)
    {
        if (depth == 0)
        {
            return 1;
        }

        MoveList moveList = MoveList();
        generateMoves(pos, moveList);

        if (depth == 1 && !root)
            return moveList.size;

        uint64_t count = 0;
        for (size_t i = 0; i < moveList.size; i++)
        {
            pos.makeTurn(moveList.moves[i]);
            uint64_t newCount = perft(pos, depth - 1, false);
            pos.unmakeTurn();

            count += newCount;
            if (root)
                std::cout << moveList.moves[i] << ": " << newCount << std::endl;
        }

        if (root)
        {
            std::cout << std::endl
                      << "Total: " << count << std::endl;
        }
        return count;
    }
}

#endif
