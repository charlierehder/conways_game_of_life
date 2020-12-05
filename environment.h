/*
* This environment is essentially a wrapper around a 2d array of bools
* that provides just enought extra functionality to be worth it
*
* Each coordinate is a cell in the simulation with its T/F value 
* indicating whether it is "dead" or "alive". An instance of the 
* environment has the ability to update itself by one "step" in time
* as the simulation moves forward
*
*/
class Environment 
{
    public:

    // width of environment
    int _width;

    // height of envrionment
    int _height;

    // 2d array of cells that represents the environment
    bool **_cells; 

    // default constructor
    Environment();

    // parameterized constructor
    Environment(int width, int height);

    // deep copy constructor
    Environment (const Environment &env);

    // destructor
    ~Environment();

    /* The atomic structure of the Conway simulation, building block of all the structures below
    * Places 1x1 cell at provided coordinate
    */
    void placeCell(int x, int y);

    /* ..... Still Lifes ..... */

    /* Block: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_block_with_border.svg
    * Places 2x2 block at provided coordinates
    */
    void placeBlock(int x, int y);

    /* Bee-hive: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_beehive.svg
    * Places 4x3 bee-hive at provided coordinates
    */
    void placeBeeHive(int x, int y);

    /* Loaf: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_loaf.svg
    * Places 4x4 loaf at provided coordinates
    */ 
    void placeLoaf(int x, int y);

    /* Boat: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_boat.svg
    * Places 3x3 boat at provided coordinates
    */ 
    void placeBoat(int x, int y);

    /* Tub: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_flower.svg
    * Places 3x3 tub at provided coordinates
    */
    void placeTub(int x, int y);

    /* ..... Spaceships ..... */

    /* Glider: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_animated_glider.gif
    * Places 3x3 glider at proveded coordinates
    */ 
    void placeGlider(int x, int y);

    /* ..... Oscillators ..... */

    /* Blinker: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_blinker.gif
    * Places 3x3 blinker at provided coordinates
    */
    void placeBlinker(int x, int y);

    /* Toad: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_toad.gif
    * Places 4x4 toad at provided coordinates
    */
    void placeToad(int x, int y);

    /* Beacon: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_beacon.gif
    * Places 4x4 beacon at provided coordinates
    */
    void placeBeacon(int x, int y);

    /* Pulsar: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_pulsar.gif
    * Places 13x13 pulsar at provided coordinates
    * This was a little annoying to hard code
    */
    void placePulsar(int x, int y);

    /* Penta-decathlon: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:I-Column.gif
    * Places 10x3 penta-decathlon at provided coordinates
    */
    void placePentaDecathlon(int x, int y);

    /* ..... Methuselahs ..... */
    /* Patterns which evolve for long periods before stabilizing */

    /* R-pentomino: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_fpento.svg
    * Places 3x3 r-pentomino at provided coordinates
    */
    void placeRPentomino(int x, int y);

    /* Die-hard: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_diehard.svg
    * Places 8x3 die-hard at provided coordinates
    */
    void placeDieHard(int x, int y);

    /* Acorn: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life#/media/File:Game_of_life_acorn.svg
    * Places 7x3 acorn at provided coordinates
    */
    void placeAcorn(int x, int y);

    // returns next iteration of the environment based
    // on input list of cells
    void updateEnvironment();

};