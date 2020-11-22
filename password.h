typedef struct options {
    int bubbleman;
    int airman;
    int quickman;
    int woodman;
    int crashman;
    int flashman;
    int metalman;
    int heatman;
    int etanks;
    int debug;
} options;

unsigned int generatePassword(struct options* config);
