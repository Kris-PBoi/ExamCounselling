#include<stdio.h>
#include<string.h>
#include "counsellingMain.h"
int loadSeatMatrix(struct CounsellingMain *cMainPtr, char *seatMatrixFile)
{
    //printf("load seat matrix called with %s\n", seatMatrixFile);
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
    fclose(matrFile);
}
void printMatrix(struct SeatMatrix *matrix)
{
    printf("%s %s %d\n", matrix->collegeCode, matrix->programCode, matrix->noOfSeats);
}
// int main(int argc, char**argv)
// {
//     char *fileName = argv[1];
//     struct CounsellingMain cMain;

//     loadSeatMatrix(&cMain, fileName);
//     for(int i = 0; i < cMain.matrixCount; i++)
//     {
//         printMatrix(&(cMain.seatMatrix[i]));
//     }
// }