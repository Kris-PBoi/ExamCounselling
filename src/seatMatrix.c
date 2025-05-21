#include<stdio.h>
#include "counsellingMain.h"
int loadSeatMatrix(struct CounsellingMain *cMainPtr, char seatMatrixFile[50])
{
    printf("load seat matrix called with %s\n", seatMatrixFile);
    FILE *matrFile = fopen(seatMatrixFile, "r");
    struct SeatMatrix matrix;
    char line[500];
    int matCounter = 0;

    if(matrFile == NULL)
    {
        printf("FILE not found\n");
    }
    else
    {
        while(fgets(line,500,matrFile) != NULL)
        {
            sscanf(line, "%s %s %d", matrix.collegeCode, matrix.programCode, &matrix.noOfSeats);
            matCounter++;
            cMainPtr->seatMatrix[matCounter-1] = matrix;
        }
        cMainPtr->matrixCount = matCounter;
    }
}
void printMatrix(struct SeatMatrix *matrix)
{
    printf("%s %s %d\n", matrix->collegeCode, matrix->programCode, matrix->noOfSeats);
}
int main()
{
    char *fileName = "/mnt/c/Users/kris_/OneDrive/Desktop/PES/Sem2/C/ExamCounselling/docs/SeatMatrix.csv";
    struct CounsellingMain cMain;

    loadSeatMatrix(&cMain, fileName);
    for(int i = 0; i < cMain.matrixCount; i++)
    {
        printMatrix(&(cMain.seatMatrix[i]));
    }
}