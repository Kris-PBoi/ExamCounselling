#include "application.h"
#include "seatMatrix.h"

#define MAXAPPS 1000
#define MAXSEATMATRIX 1000

//Error Codes
enum ErrorCode
{
    SUCCESS = 0,
    APPL_FILE_ERROR = 1,
    SEAT_MATRIX_ERROR = 2,
    NOSEAT = -1
};

struct CounsellingMain
{
    struct Application appList[MAXAPPS];
    struct SeatMatrix seatMatrix[MAXSEATMATRIX];
    int appCount;
    int matrixCount;
};
enum ErrorCode loadSeatMatrix(struct CounsellingMain *cMainPtr, char *seatMatrixFile);
enum ErrorCode loadApplication(struct CounsellingMain *cMainPtr, char *studApplFile);
enum ErrorCode seatAllocation(struct CounsellingMain *cMainPtr);
enum ErrorCode saveSeatAllocation(struct CounsellingMain *cMainPtr, char *allocationFile);
enum ErrorCode sortAppl(struct CounsellingMain *cMainPtr);
void loadTestData(struct CounsellingMain *cMainPtr);
void applTestPrint(struct CounsellingMain *cMainPtr);
enum ErrorCode allocateSeat(struct CounsellingMain *cMainPtr, char* institute, char* program);
int updateAvailableSeats(struct CounsellingMain *cMainPtr, char* institute, char* program);

