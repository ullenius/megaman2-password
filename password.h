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
} options;

void generatePassword(struct options* config);
