#include<stdio.h>
#include "counsellingMain.h"
enum ErrorCode loadApplication(struct CounsellingMain *cMainPtr, char *studApplFile)
{
    //printf("load Application called with %s\n", studApplFile);
    FILE *appFile = fopen(studApplFile, "r");
    struct Application app;
    char line[500];
    int appCounter = 0;

    if(appFile == NULL)
    {
        printf("FILE not found\n");
    }
    else
    {
        while(fgets(line,500,appFile) != NULL)
        {
            sscanf(line, "%d %d %s %s %s %s %s %s", &app.appNo, &app.rank, app.prefList[0].collegeCode, app.prefList[0].programCode, app.prefList[1].collegeCode, app.prefList[1].programCode, app.prefList[2].collegeCode, app.prefList[2].programCode);
            app.prefCount = 3;
            appCounter++;
            cMainPtr->appList[appCounter-1] = app;
        }
        cMainPtr->appCount = appCounter;
    }
    fclose(appFile);
    return SUCCESS;
}
void printAppl(struct Application *app)
{
    printf("%d %d %s %s %s %s %s %s\n", app->appNo, app->rank, app->prefList[0].collegeCode, app->prefList[0].programCode, app->prefList[1].collegeCode, app->prefList[1].programCode, app->prefList[2].collegeCode, app->prefList[2].programCode);
}
// int main()
// {
//     char *fileName = "/mnt/c/Users/kris_/OneDrive/Desktop/PES/Sem2/C/ExamCounselling/docs/Application.csv";
//     struct CounsellingMain cMain;

//     loadApplication(&cMain, fileName);
//     for(int i = 0; i < cMain.appCount; i++)
//     {
//         printAppl(&(cMain.appList[i]));
//     }
// }