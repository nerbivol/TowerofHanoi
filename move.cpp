#include "move.h"

Move::Move(int start, int finish):
    from(start),
    to(finish){};

Move::Move():
    from(0),to(0){};
