#include "application.h"
#include "seatMatrix.h"

#define MAXAPPS 1000
#define MAXSEATMATRIX 1000

//Error Codes
#define SUCCESS 0
#define APPL_FILE_ERROR 1
#define SEAT_MATRIX_ERROR 2
#define NOSEAT -1

struct CounsellingMain
{
    struct Application appList[MAXAPPS];
    struct SeatMatrix seatMatrix[MAXSEATMATRIX];
    int appCount;
    int matrixCount;
};
int loadSeatMatrix(struct CounsellingMain *cMainPtr, char seatMatrixFile[50]);
int loadApplication(struct CounsellingMain *cMainPtr, char studApplFile[50]);
int seatAllocation(struct CounsellingMain *cMainPtr);
int saveSeatAllocation(struct CounsellingMain *cMainPtr, char allocationFile[20]);
int sortAppl(struct CounsellingMain *cMainPtr);
void loadTestData(struct CounsellingMain *cMainPtr);
void applTestPrint(struct CounsellingMain *cMainPtr);
int allocateSeat(struct CounsellingMain *cMainPtr, char* institute, char* program);
int updateAvailableSeats(struct CounsellingMain *cMainPtr, char* institute, char* program);

