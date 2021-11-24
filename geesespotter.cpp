#include "geesespotter_lib.h"
#include <iostream>

char *createBoard(std::size_t xdim, std::size_t ydim) {

    char *a_array = new char [xdim * ydim];

    for (int x{}; x < xdim*ydim; x++) {
        a_array[x] = 0;
    }
    return a_array;
}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim) {
    for (int x{}; x < xdim*ydim; x++) {
        if (board[x] == 9) {
            
        }
    }
    
    bool isCorner = false;
    bool isMiddle = false;
    for (int x{0}; x < xdim*ydim; x++) {
        // Is there a goose?
        if (board[x] == 0b00001001) {
            // Top Left Corner
            if (x == 0) {
                isCorner = true;
                if (board[x + 1] == 0) {
                board[x + 1] = board [x + 1] + 1;
                }
                if (board[x + xdim] == 0) {
                    board[x + xdim] = board [x + xdim] + 1;
                }
                if (board[x + 1 + xdim] == 0) {
                board[x + 1 + xdim] = board [x + 1 + xdim] + 1;
                }
            }
            // Top Right Corner 
            if (x == xdim - 1) {
                isCorner = true;
                if (board[x - 1] == 0) {
                board[x - 1] = board [x - 1] + 1;
                }
                if (board[x + xdim] == 0) {
                    board[x + xdim] = board [x + xdim] + 1;
                }
                if (board[x - 1 + xdim] == 0) {
                board[x - 1 + xdim] = board [x - 1 + xdim] + 1;
                }
            }
            // Bottom Left Corner
            if (x == xdim*ydim - xdim) {
                isCorner = true;
                if (board[x + 1] == 0) {
                board[x + 1] = board [x + 1] + 1;
                }
                if (board[x - xdim] == 0) {
                    board[x - xdim] = board [x - xdim] + 1;
                }
                if (board[x + 1 - xdim] == 0) {
                board[x + 1 - xdim] = board [x + 1 - xdim] + 1;
                }
            }
            // Bottom Right Corner
            if (x == xdim*ydim - 1) {
                isCorner = true;
                if (board[x - 1] == 0) {
                board[x - 1] = board [x - 1] + 1;
                }
                if (board[x - xdim] == 0) {
                    board[x - xdim] = board [x - xdim] + 1;
                }
                if (board[x - 1 - xdim] == 0) {
                board[x - 1 - xdim] = board [x - 1 - xdim] + 1;
                }
            }
            // Middle of the Board
            if (x%xdim != 0 || (x+1)%xdim != 0 || (x > xdim && x < xdim*ydim)) {
            for (int y{xdim + 1}; y < (xdim*ydim) - xdim; y++) {
                isMiddle = true;
                // Only modify if adjacent value = 0
                if (board[y] == 0) {
                    // Only works for squares in the middle. Does not work for edges 
                    // Is it directly to the right or left?
                    if (y == x - 1 || y == x + 1) {
                        board[y] = board[y] + 1;
                    }
                    // Is it directly above or below?
                    if (y == x - xdim || y == x + xdim) {
                        board[y] = board[y] + 1;
                    }
                    // Is it above and to the left or right?
                    if (y == x - xdim - 1 || y == x - xdim + 1) {
                        board[y] = board[y] + 1;
                    }
                    // Is it below and to the left or right?
                    if (y == x + xdim - 1 || y == x + xdim + 1) {
                        board[y] = board[y] + 1;
                    }
                }       
            }
        }
                    // Left edges
                    if ((isCorner == false && isMiddle == false) && x%xdim == 0) {
                    if (board[x + 1] == 0) {
                        board[x + 1] = board [x + 1] + 1;
                    }
                    if (board[x + xdim] == 0) {
                        board[x + xdim] = board[x + xdim] + 1;
                    }
                    if (board[x - xdim == 0]) {
                        board[x - xdim] = board[x - xdim] + 1;
                    }
                    if (board[x + 1 + xdim] == 0) {
                    board[x + 1 + xdim] = board[x + 1 + xdim] + 1;
                    }
                    if (board[x + 1 - xdim] == 0) {
                        board[x + 1 - xdim] = board[x + 1 - xdim] + 1;
                    }
                    }
                    // Right edges
                    if ((isCorner == false && isMiddle == false) && (x+1)%xdim == 0) {
                    if (board[x - 1] == 0) {
                        board[x - 1] = board [x - 1] + 1;
                    }
                    if (board[x + xdim] == 0) {
                        board[x + xdim] = board[x + xdim] + 1;
                    }
                    if (board[x - xdim == 0]) {
                        board[x - xdim] = board[x - xdim] + 1;
                    }
                    if (board[x - 1 + xdim] == 0) {
                    board[x - 1 + xdim] = board[x - 1 + xdim] + 1;
                    }
                    if (board[x - 1 - xdim] == 0) {
                        board[x - 1 - xdim] = board[x - 1 - xdim] + 1;
                    }
                    }
                    // Top edges
                    if ((isCorner == false && isMiddle == false) && (x > 0 && x < xdim - 1)) {
                    if (board[x + 1] == 0) {
                        board[x + 1] = board [x + 1] + 1;
                    }
                    if (board[x - 1] == 0) {
                        board[x - 1] = board[x - 1] + 1;
                    }
                    if (board[x + xdim] == 0) {
                        board[x + xdim] = board[x + xdim] + 1;
                    }
                    if (board[x + 1 + xdim] == 0) {
                        board[x + 1 + xdim] = board[x + 1 + xdim] + 1;
                    }
                    if (board[x - 1 + xdim] == 0) {
                        board[x - 1 + xdim] = board[x - 1 + xdim] + 1;
                    }
                    }
                    // Bottom edges
                    if ((isCorner == false && isMiddle == false) && (x > xdim*ydim - xdim + 1 && x < xdim*ydim - 1)) {
                    if (board[x + 1] == 0) {
                        board[x + 1] = board [x + 1] + 1;
                    }
                    if (board[x - 1] == 0) {
                        board[x - 1] = board[x - 1] + 1;
                    }
                    if (board[x - xdim == 0]) {
                        board[x - xdim] = board[x - xdim] + 1;
                    }
                    if (board[x + 1 - xdim] == 0) {
                        board[x + 1 - xdim] = board[x + 1 - xdim] + 1;
                    }
                    if (board[x - 1 - xdim] == 0) {
                        board[x - 1 - xdim] = board[x - 1 - xdim] + 1;
                    }
                    }
        }
    }
}


void hideBoard(char *board, std::size_t xdim, std::size_t ydim) {
    for (int x{}; x < xdim*ydim; x++) {
        board[x] = board[x] | 0x20;
    } 
}

void cleanBoard(char *board) {
    delete [] board;
    board = nullptr;
    
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim) {
    for (int x{1}; x <= xdim*ydim; x++) {
        // Marked condition
        if ((board[x-1] & 0x10) == 0x10) {
            std::cout << 'M';
        }
        // Hidden condition
        else if ((board[x-1] & 0x20) == 0x20) {
            std::cout << '*';
        }
        // Display number
        else {
            std::cout << char (board[x-1] + 48);
        }
        if (x%xdim == 0) {
            std::cout << std::endl;
        }
    }
}

int reveal(char* board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
    int result{};
    // Is there a goose?
    // Is it marked?
    if (board[xloc + yloc*xdim] & 0x10 == 0x10) {
        result = 1;
    }
    // Is it revealed?
    else if (board[xloc + yloc*xdim] & 0b11110000 == 0x0) {
        result = 2;
    }
    // Is it hidden?
    if ((board[xloc + yloc*xdim] & 0x20) == 0x20) {
        if (board[xloc + yloc*xdim] == 0b00001001) {
            result = 9;
            return result;
        }
        if ((board[xloc + yloc*xdim] ^ 0x20) > 0) {
            board[xloc + yloc*xdim] = board[xloc + yloc*xdim] & ~0x20;
        }
        else if ((board[xloc + yloc*xdim] ^ 0x20) == 0) {
            // Top Left Corner
            if(xloc == 0 && yloc == 0) {
                board[(xloc + yloc*xdim) + 1] = board[(xloc + yloc*xdim) + 1] & ~0x20;
                board[(xloc + yloc*xdim) + xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) + 1 + xdim] = board[(xloc + yloc*xdim) + 1 + xdim] & ~0x20;
            }
            // Top Right Corner
            if (xloc == xdim - 1 && yloc == 0) {
                board[(xloc + yloc*xdim) - 1] = board[(xloc + yloc*xdim) - 1] & ~0x20; 
                board[(xloc + yloc*xdim) + xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 + xdim] = board[(xloc + yloc*xdim) - 1 + xdim] & ~0x20;
            }
            // Bottom Left Corner
            if (xloc == 0 && yloc == ydim - 1) {
                board[(xloc + yloc*xdim) + 1 - xdim] = board[(xloc + yloc*xdim) + 1 - xdim] & ~0x20; 
                board[(xloc + yloc*xdim) - xdim] = board[(xloc + yloc*xdim) - xdim] & ~0x20;
                board[(xloc + yloc*xdim) + 1] = board[(xloc + yloc*xdim) + 1] & ~0x20;
            }
            // Bottom Right Corner 
            if (xloc == xdim - 1 && yloc == ydim - 1 ) {
                board[(xloc + yloc*xdim) - 1] = board[(xloc + yloc*xdim) - 1] & ~0x20; 
                board[(xloc + yloc*xdim) - xdim] = board[(xloc + yloc*xdim) - xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 - xdim] = board[(xloc + yloc*xdim) - 1 - xdim] & ~0x20;
            }
            // Left edges
            if (xloc == 0 && (yloc > 0 && yloc < ydim - 1)) {
                board[(xloc + yloc*xdim) + 1] = board[(xloc + yloc*xdim) + 1] & ~0x20; 
                board[(xloc + yloc*xdim) + xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) + 1 + xdim] = board[(xloc + yloc*xdim) + 1 - xdim] & ~0x20;
                board[(xloc + yloc*xdim) + 1 - xdim] = board[(xloc + yloc*xdim) + 1 - xdim] & ~0x20;
            }
            // Right edges
            if (xloc == xdim - 1 && (yloc > 0 && yloc < ydim - 1)) {
                board[(xloc + yloc*xdim) - 1] = board[(xloc + yloc*xdim) - 1] & ~0x20; 
                board[(xloc + yloc*xdim) + xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 + xdim] = board[(xloc + yloc*xdim) - 1 + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 - xdim] = board[(xloc + yloc*xdim) - 1 - xdim] & ~0x20;
            }
            // Top edges
            if (yloc == 0 && (xloc > 0 && xloc < xdim - 1)) {
                board[(xloc + yloc*xdim) + 1] = board[(xloc + yloc*xdim) + 1] & ~0x20; 
                board[(xloc + yloc*xdim) - 1] = board[(xloc + yloc*xdim) - 1] & ~0x20;
                board[(xloc + yloc*xdim) + xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) + 1 + xdim] = board[(xloc + yloc*xdim) + 1 + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 + xdim] = board[(xloc + yloc*xdim) - 1 + xdim] & ~0x20;
            }
            // Bottom edges
            if (yloc == ydim - 1 && (xloc > 0 && xloc < xdim - 1)) {
                board[(xloc + yloc*xdim) + 1] = board[(xloc + yloc*xdim) + 1] & ~0x20; 
                board[(xloc + yloc*xdim) - 1] = board[(xloc + yloc*xdim) - 1] & ~0x20;
                board[(xloc + yloc*xdim) - xdim] = board[(xloc + yloc*xdim) - xdim] & ~0x20;
                board[(xloc + yloc*xdim) + 1 - xdim] = board[(xloc + yloc*xdim) + 1 - xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 - xdim] = board[(xloc + yloc*xdim) - 1 - xdim] & ~0x20;
            }
            // Middle Case 
            else {
                board[(xloc + yloc*xdim) + 1] = board[(xloc + yloc*xdim) + 1] & ~0x20; 
                board[(xloc + yloc*xdim) - 1] = board[(xloc + yloc*xdim) - 1] & ~0x20;
                board[(xloc + yloc*xdim) + xdim] = board[(xloc + yloc*xdim) + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - xdim] = board[(xloc + yloc*xdim) - xdim] & ~0x20;  
                board[(xloc + yloc*xdim) + 1 + xdim] = board[(xloc + yloc*xdim) + 1 + xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 + xdim] = board[(xloc + yloc*xdim) - 1 + xdim] & ~0x20;
                board[(xloc + yloc*xdim) + 1 - xdim] = board[(xloc + yloc*xdim) + 1 - xdim] & ~0x20;
                board[(xloc + yloc*xdim) - 1 - xdim] = board[(xloc + yloc*xdim) - 1 - xdim] & ~0x20;       
            }
            board[xloc + yloc*xdim] = board[xloc + yloc*xdim] & ~0x20;
        }
    }
    // Reveal
    /*else if (board[xloc + yloc*xdim] & 0x20 == 0x20) {
        std::cout << char ((board[xloc + yloc*xdim] ^ 0x20) + 48);
        result = 0;
        if ((char(board[xloc + yloc*xdim]) ^ 0x20) + 48 == 0) {
            if (board[xloc + yloc*xdim] == 0x00) {
                std::cout <<    
                    
            }
        }
        }
    }*/
    // Otherwise
    else {
        result = 0;    
    }
    return result;
}

int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc) {
    
    // Is it hidden?
     if (board[xloc + yloc*xdim] & 0x20 == 0x20) {
        board[xloc + yloc*xdim] = board[xloc + yloc*xdim] ^ 0x10;
        return 0;
    }
    else{
        return 2;
    }
}

bool isGameWon(char *board, std::size_t xdim, std::size_t ydim) {
    // Check if unhidden or goose
    bool isGameWon{true};
    for (int x{}; x < xdim*ydim; x++) {
        // Is there a square that is hidden and is not a goose?
        if ((board[x] & 0x20 == 0x20) && board[x] != 0b00001001) {
            return false;
            // Exit immediately
            break;
        }
        // Is it marked and is not a goose?
        if ((board[x] & 0x10) == 0x10 && board[x] != 0b00001001) {
            return false;
            // Exit immediately
            break;
        }
    }

    return true;
}