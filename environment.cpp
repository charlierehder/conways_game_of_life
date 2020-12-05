#include "environment.h"

Environment::Environment() { _width = 0; _height = 0; }

Environment::Environment(int width, int height) {

    _width = width;
    _height = height;

    _cells = new bool*[_width];
    for (int i = 0; i < _width; i++) {
        _cells[i] = new bool[_height];
        for (int j = 0; j < _height; j++) {
            _cells[i][j] = false;
        }
    }

}

Environment::Environment (const Environment &env) {

    _width = env._width;
    _height = env._height;
    
    _cells = new bool*[_width];
    for (int i = 0; i < _width; i++) {
        _cells[i] = new bool[_height];
        for (int j = 0; i < _height; j++) {
            _cells[i][j] = env._cells[i][j];
        }
    }
}

Environment::~Environment() {

    for (int i = 0; i < _width; i++) {
        delete[] _cells[i];
    }

    delete[] _cells;

}

void Environment::placeCell(int x, int y) {

    if (x > _width || y > _height || x < 0 || y < 0) return;

    _cells[x][y] = true;
    
}

void Environment::placeBlock(int x, int y) {

    if (x+1 > _width || y+1 > _height || x < 0 || y < 0) return;

    _cells[x][y] = true;
    _cells[x+1][y] = true;
    _cells[x][y+1] = true;
    _cells[x+1][y+1] = true;

}

void Environment::placeBeeHive(int x, int y) {

    if (x+3 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x+2][y] = true;
    _cells[x][y+1] = true;
    _cells[x+3][y+1] = true;
    _cells[x+1][y+2] = true;
    _cells[x+2][y+2] = true;

}
 
void Environment::placeLoaf(int x, int y) {

    if (x+3 > _width || y+3 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x+2][y] = true;
    _cells[x][y+1] = true;
    _cells[x+3][y+1] = true;
    _cells[x+1][y+2] = true;
    _cells[x+3][y+2] = true;
    _cells[x+2][y+3] = true;

}
 
void Environment::placeBoat(int x, int y) {

    if (x+2 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x][y] = true;
    _cells[x+1][y] = true;
    _cells[x][y+1] = true;
    _cells[x+2][y+1] = true;
    _cells[x+1][y+2] = true;

}

void Environment::placeTub(int x, int y) {

    if (x+2 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x][y+1] = true;
    _cells[x+2][y+1] = true;
    _cells[x+1][y+2] = true;

}

void Environment::placeGlider(int x, int y) {

    if (x+2 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x+2][y+1] = true;
    _cells[x][y+2] = true;
    _cells[x+1][y+2] = true;
    _cells[x+2][y+2] = true;

}

void Environment::placeBlinker(int x, int y) {

    if (x+2 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x+1][y+1] = true;
    _cells[x+1][y+2] = true;
}

void Environment::placeToad(int x, int y) {

    if (x+3 > _width || y+3 > _height || x < 0 || y < 0) return;

    _cells[x+1][y+1] = true;
    _cells[x+2][y+1] = true;
    _cells[x+3][y+1] = true;
    _cells[x][y+2] = true;
    _cells[x+1][y+2] = true;
    _cells[x+2][y+2] = true;

}

void Environment::placeBeacon(int x, int y) {

    if (x+3 > _width || y+3 > _height || x < 0 || y < 0) return;

    _cells[x][y] = true;
    _cells[x][y+1] = true;
    _cells[x+1][y] = true;
    _cells[x+2][y+3] = true;
    _cells[x+3][y+2] = true;
    _cells[x+3][y+3] = true;

}

void Environment::placePulsar(int x, int y) {

    if (x+12 > _width || y+12 > _height || x < 0 || y < 0) return;


    // top left quartile
    _cells[x+2][y] = true;
    _cells[x+3][y] = true;
    _cells[x+4][y] = true;
    _cells[x][y+2] = true;
    _cells[x][y+3] = true;
    _cells[x][y+4] = true;
    _cells[x+2][y+5] = true;
    _cells[x+3][y+5] = true;
    _cells[x+4][y+5] = true;
    _cells[x+5][y+2] = true;
    _cells[x+5][y+3] = true;
    _cells[x+5][y+4] = true;

    // top right quartile
    _cells[x+8][y] = true;
    _cells[x+9][y] = true;
    _cells[x+10][y] = true;
    _cells[x+12][y+2] = true;
    _cells[x+12][y+3] = true;
    _cells[x+12][y+4] = true;
    _cells[x+8][y+5] = true;
    _cells[x+9][y+5] = true;
    _cells[x+10][y+5] = true;
    _cells[x+7][y+2] = true;
    _cells[x+7][y+3] = true;
    _cells[x+7][y+4] = true;

    // bottom left quartile
    _cells[x+2][y+12] = true;
    _cells[x+3][y+12] = true;
    _cells[x+4][y+12] = true;
    _cells[x][y+8] = true;
    _cells[x][y+9] = true;
    _cells[x][y+10] = true;
    _cells[x+2][y+7] = true;
    _cells[x+3][y+7] = true;
    _cells[x+4][y+7] = true;
    _cells[x+5][y+8] = true;
    _cells[x+5][y+9] = true;
    _cells[x+5][y+10] = true;

    // bottom right quartile
    _cells[x+8][y+12] = true;
    _cells[x+9][y+12] = true;
    _cells[x+10][y+12] = true;
    _cells[x+12][y+8] = true;
    _cells[x+12][y+9] = true;
    _cells[x+12][y+10] = true;
    _cells[x+8][y+7] = true;
    _cells[x+9][y+7] = true;
    _cells[x+10][y+7] = true;
    _cells[x+7][y+8] = true;
    _cells[x+7][y+9] = true;
    _cells[x+7][y+10] = true;

}

void Environment::placePentaDecathlon(int x, int y) {

    if (x+2 > _width || y+9 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x+1][y+1] = true;
    _cells[x][y+2] = true;
    _cells[x+2][y+2] = true;
    _cells[x+1][y+3] = true;
    _cells[x+1][y+4] = true;
    _cells[x+1][y+5] = true;
    _cells[x+1][y+6] = true;
    _cells[x][y+7] = true;
    _cells[x+2][y+7] = true;
    _cells[x+1][y+8] = true;
    _cells[x+1][y+9] = true;

}

void Environment::placeRPentomino(int x, int y) {

    if (x+2 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x+2][y] = true;
    _cells[x][y+1] = true;
    _cells[x+1][y+1] = true;
    _cells[x+1][y+2] = true;

}

void Environment::placeDieHard(int x, int y) {

    if (x+7 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x+6][y] = true;
    _cells[x][y+1] = true;
    _cells[x+1][y+1] = true;
    _cells[x+1][y+2] = true;
    _cells[x+5][y+2] = true;
    _cells[x+6][y+2] = true;
    _cells[x+7][y+2] = true;

}

void Environment::placeAcorn(int x, int y) {

    if (x+6 > _width || y+2 > _height || x < 0 || y < 0) return;

    _cells[x+1][y] = true;
    _cells[x][y+2] = true;
    _cells[x+1][y+2] = true;
    _cells[x+3][y+1] = true;
    _cells[x+4][y+2] = true;
    _cells[x+5][y+2] = true;
    _cells[x+6][y+2] = true;

}

void Environment::updateEnvironment() {

    // initialize temp bool array
    bool **new_env = new bool*[_width];
    for (int i = 0; i < _width; i++) {
        new_env[i] = new bool[_height];
    }

    for (int i = 0; i < _width; i++) {
        for (int j = 0; j < _height; j++) {

            // check cell for living and dead neighbors
            // tried to optimize this the best I could but this ugliness ended up being the most efficient 
            // at least so far
            int live_neighbor_count = 0;
            int dead_neighbor_count = 0;

            (i > 0 && j > 0 && _cells[i-1][j-1]) ? live_neighbor_count++ : dead_neighbor_count++;
            (i > 0 && _cells[i-1][j]) ? live_neighbor_count++ : dead_neighbor_count++;
            (i > 0 && j < _height-1 && _cells[i-1][j+1]) ? live_neighbor_count++ : dead_neighbor_count++;

            (j > 0 && _cells[i][j-1]) ? live_neighbor_count++ : dead_neighbor_count++;
            (j < _height-1 && _cells[i][j+1]) ? live_neighbor_count++ : dead_neighbor_count++;

            (i < _width-1 && j > 0 && _cells[i+1][j-1]) ? live_neighbor_count++ : dead_neighbor_count++;
            (i < _width-1 && _cells[i+1][j]) ? live_neighbor_count++ : dead_neighbor_count++;
            (i < _width-1 && j < _height-1 && _cells[i+1][j+1]) ? live_neighbor_count++ : dead_neighbor_count++;

            /* conway rules from wikipedia...
            * "These rules, which compare the behavior of the automaton to real life, can be condensed into the following:
            *
            *   1. Any live cell with two or three live neighbours survives.
            *   2. Any dead cell with three live neighbours becomes a live cell.
            *   3. All other live cells die in the next generation. Similarly, all other dead cells stay dead."  
            */
            if (_cells[i][j] && (live_neighbor_count == 2 || live_neighbor_count == 3)) {
                new_env[i][j] = true;

            } else if (!_cells[i][j] && live_neighbor_count == 3) {
                new_env[i][j] = true;

            } else {
                new_env[i][j] = false;
            }
        }
    }

    for (int i = 0; i < _width; i++) {
        delete[] _cells[i];
    }
    delete[] _cells;

    // update 2d bool array to latest iteration
    _cells = new_env;

}


