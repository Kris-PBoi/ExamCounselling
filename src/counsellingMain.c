#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "counsellingMain.h"
int main(int argc, char *argv[])
{
    struct CounsellingMain cMain;
    char allocationFile[20];
    
    cMain.appCount = 0;

    strcpy(allocationFile, "allocationFile.txt");
    printf("Main function called with argc %d.\n", argc);
    if(argc != 3)
    {
        printf("usage: %s <seatmatrixFile> <applicationFile>\n", argv[0]);
        return 1;
    }
    for(int i = 0; i < argc; i++)
    {
        printf("argv %s.\n", argv[i]);
    }
    char *seatMatrixFile = argv[1];
    char *applicationFile = argv[2];
    loadApplication(&cMain, applicationFile);
    loadSeatMatrix(&cMain, seatMatrixFile);
    //loadTestData(&cMain);
    
    printf("Before sorting by rank: \n");
    applTestPrint(&cMain);
    sortAppl(&cMain);
    printf("After sorting by rank: \n");
    applTestPrint(&cMain);
    
    seatAllocation(&cMain);
    saveSeatAllocation(&cMain, allocationFile);
       
    printf("Counselling done successfully\n");
}
int seatAllocation(struct CounsellingMain *cMainPtr)
{
    printf("Seat Allocation called\n");
    for(int i = 0; i < cMainPtr->appCount; i++)
    {
        struct Application* app = &(cMainPtr->appList[i]); 
        int seatFound = 0;
        for(int j = 0; j < app->prefCount; j++)
        {
            if(allocateSeat(cMainPtr, app->prefList[j].collegeCode,
                app->prefList[j].programCode) == SUCCESS)
            {
                seatFound = 1;
                //save preference index that is allocated
                app->allocations[app->allocationCount++] = j;
            }
        }
        if(seatFound == 0) printf("No seat allocated for %d\n", app->appNo);
        else printf("Seat allocated for %d\n", app->appNo);
    }
    return SUCCESS;
}
int allocateSeat(struct CounsellingMain *cMainPtr, char* collegeCode, char* programCode)
{
    for(int i = 0; i < cMainPtr->matrixCount; i++)
    {
        if(!strcmp(cMainPtr->seatMatrix[i].collegeCode, collegeCode)
         && !strcmp(cMainPtr->seatMatrix[i].programCode, programCode)
          && cMainPtr->seatMatrix[i].noOfSeats > 0)
        {
            cMainPtr->seatMatrix[i].noOfSeats--;
            return SUCCESS;
        }
    }
    return NOSEAT;
}
int updateAvailableSeats(struct CounsellingMain *cMainPtr, char* collegeCode, char* programCode)
{
    for(int i = 0; i < cMainPtr->matrixCount; i++)
    {
        if(!strcmp(cMainPtr->seatMatrix[i].collegeCode, collegeCode)
         && !strcmp(cMainPtr->seatMatrix[i].programCode, programCode))
        {
            return(cMainPtr->seatMatrix[i].noOfSeats);
        }
    }
}
int saveSeatAllocation(struct CounsellingMain *cMainPtr, char *allocationFile)
{
    printf("Seat Allocation saved to %s\n", allocationFile);
    FILE *allocatedFile = fopen(allocationFile, "w");
    char line[500];
    if(allocatedFile == NULL)
    {
        printf("FILE not found\n");
    }
    else
    {
        for(int i = 0; i < cMainPtr->appCount; i++)
        {
        struct Application* app = &(cMainPtr->appList[i]); 
            for(int j = 0; j < app->allocationCount; j++)
            {
                int prefindex = app->allocations[j];
                fprintf(allocatedFile, "%d %d %s %s", app->appNo, app->rank, app->prefList[prefindex].collegeCode, app->prefList[prefindex].programCode);
                printf("%d %d %s %s", app->appNo, app->rank, app->prefList[prefindex].collegeCode, app->prefList[prefindex].programCode);
            }
            fprintf(allocatedFile, "\n");
            printf("\n");
        }
    }
}
int sortAppl(struct CounsellingMain *cMainPtr)
{
    int pos;
    struct Application temp;
    for(int i = 0; i < cMainPtr->appCount; i++)
    {
        pos = i;
        for(int j = i + 1; j < cMainPtr->appCount; j++)
        {
            if(cMainPtr->appList[pos].rank > cMainPtr->appList[j].rank) pos = j;
        }
        if(pos != i)
        {
            temp = cMainPtr->appList[pos]; 
            cMainPtr->appList[pos] = cMainPtr->appList[i];
            cMainPtr->appList[i] = temp; 
        }
    }
    return SUCCESS;
}
void loadTestData(struct CounsellingMain *cMainPtr)
{
    printf("Loading test data: \n");
    cMainPtr->appCount = 3;
    cMainPtr->appList[0].appNo = 0;
    cMainPtr->appList[0].prefCount = 2;
    strcpy(cMainPtr->appList[0].prefList[0].collegeCode, "IIITB");
    cMainPtr->appList[0].prefList[0].prefNo = 0;
    strcpy(cMainPtr->appList[0].prefList[0].programCode, "Btech-CS");

    strcpy(cMainPtr->appList[0].prefList[1].collegeCode, "NIT");
    cMainPtr->appList[0].prefList[1].prefNo = 1;
    strcpy(cMainPtr->appList[0].prefList[1].programCode, "Btech-ECE");
    cMainPtr->appList[0].rank = 25;


    cMainPtr->appList[1].appNo = 1;
    cMainPtr->appList[1].prefCount = 3;
    strcpy(cMainPtr->appList[1].prefList[0].collegeCode, "PES");
    cMainPtr->appList[1].prefList[0].prefNo = 0;
    strcpy(cMainPtr->appList[1].prefList[0].programCode, "Btech-ECE");

    strcpy(cMainPtr->appList[1].prefList[1].collegeCode, "BITS");
    cMainPtr->appList[1].prefList[1].prefNo = 1;
    strcpy(cMainPtr->appList[1].prefList[1].programCode, "BSc-Maths");

    strcpy(cMainPtr->appList[1].prefList[2].collegeCode, "VIT");
    cMainPtr->appList[1].prefList[2].prefNo = 2;
    strcpy(cMainPtr->appList[1].prefList[2].programCode, "Btech-AIML");
    cMainPtr->appList[1].rank = 74;


    cMainPtr->appList[2].appNo = 2;
    cMainPtr->appList[2].prefCount = 1;
    strcpy(cMainPtr->appList[2].prefList[0].collegeCode, "IIT-Bombay");
    cMainPtr->appList[2].prefList[0].prefNo = 0;
    strcpy(cMainPtr->appList[2].prefList[0].programCode, "Btech-ECE");
    cMainPtr->appList[2].rank = 40;

}
void applTestPrint(struct CounsellingMain *cMainPtr)
{
    for(int i = 0; i < cMainPtr->appCount; i++)
    {
        printAppl(&(cMainPtr->appList[i]));
    }
    printf("-----------------------------------------------------------------\n");
}