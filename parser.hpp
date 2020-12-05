#include "environment.h"
#include <iostream>
#include <string.h>
#include <fstream>

Environment *fileToEnv(std::string filename) {

    std::string line;
    std::ifstream file(filename);

    if (file) {

        // parse out initial height and width from first line
        std::getline(file, line, ',');
        int width = std::stoi( line );
        std::getline(file, line);
        int height = std::stoi( line );

        Environment *env = new Environment(width, height);

        while (getline(file, line)) {

            int x = stoi(line.substr(0, line.find(',')));
            int y  = stoi(line.substr(line.find(',') + 1, line.find(':')));

            std::string pattern = line.substr(line.find(':') + 1, line.find('\n'));

            if (!strcmp(pattern.c_str(), "BLK")) {
                env->placeBlock(x, y);

            } else if (!strcmp(pattern.c_str(), "BHV")) {
                env->placeBeeHive(x, y);

            } else if (!strcmp(pattern.c_str(), "LOF")) {
                env->placeLoaf(x, y);

            } else if (!strcmp(pattern.c_str(), "BOT")) {
                env->placeBoat(x, y);

            } else if (!strcmp(pattern.c_str(), "TUB")) {
                env->placeTub(x, y);

            } else if (!strcmp(pattern.c_str(), "BLR")) {
                env->placeBlinker(x, y);

            } else if (!strcmp(pattern.c_str(), "TOD")) {
                env->placeToad(x, y);

            } else if (!strcmp(pattern.c_str(), "BCN")) {
                env->placeBeacon(x, y);

            } else if (!strcmp(pattern.c_str(), "PLR")) {
                env->placePulsar(x, y);

            } else if (!strcmp(pattern.c_str(), "PDT")) {
                env->placePentaDecathlon(x, y);

            } else if (!strcmp(pattern.c_str(), "GLD")) {
                env->placeGlider(x, y);

            } else if (!strcmp(pattern.c_str(), "RPT")) {
                env->placeRPentomino(x ,y);

            } else if (!strcmp(pattern.c_str(), "DHD")) {
                env->placeDieHard(x, y);

            } else if (!strcmp(pattern.c_str(), "ACN")) {
                env->placeAcorn(x, y);

            } else {
                env->placeCell(x, y);   
            }

        }

        return env;

    } else {
        return NULL;
    }
}