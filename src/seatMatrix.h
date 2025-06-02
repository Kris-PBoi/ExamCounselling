#define MAXLENCLG 50
#define MAXLENPGM 50


struct SeatMatrix
{
    int noOfSeats;
    char collegeCode[MAXLENCLG];
    char programCode[MAXLENPGM];
};
void printMatrix(struct SeatMatrix *matrix);