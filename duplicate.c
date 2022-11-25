#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


// Check if a word is a number.
bool isANumber(char word[])

{
    bool isANumber = false;

    int num = atoi(word); 

    char numLength[20];

    sprintf(numLength, "%d", num); 

    if (strlen(word) == strlen(numLength))
    {

        isANumber = true;
    }

    return isANumber;
}

// Check if a name exceeds 10 characters.
int checkName(char element[100], char (*elements)[100], int size)
{
    int longName = 0;

    for (int i = 0; i < size; ++i)
    {

        char currentFileName[100];
        char eachFileName[100];

        strcpy(currentFileName, element);
        strcpy(eachFileName, elements[i]);

        char *name = strtok(currentFileName, " ");

        if (strlen(name) > 10){
            longName = 1;
        }
    }

    if (longName == 1){
        printf("\nRecheck your file. It seems there is a file name that exceeds 10 characters");
    }

}


// To check if a string (element) is inside a string array (elements). 
// It return true if present. Otherwise, returns false.
int isPresent(char element[100], char (*elements)[100], int size)
{
    int isPresent = 0;

    

    for (int i = 0; i < size; ++i)
    {
        if (!strcmp(elements[i], element))
        {
            isPresent = 1;
        }
    }

    return isPresent;
}

// Fill in the currentGroupedFiles witth what is in the file.
void readIntoCurrentGroupedFiles(char stringArray[100][100], int startingPoint, int count, char (*currentGroupedFiles)[100])
{

    int index = 0;
    for (int i = startingPoint + 1; i <= (startingPoint + count); i++)
    {

        strcpy(currentGroupedFiles[index], stringArray[i]);

        index++;
    }
}

// Get the Id from a file. A file has a file name along with its ID.
void getActualId(char *element, char *id)
{
    char string[50];

    strcpy(string, element);

    char *currentId = strrchr(string, ' ');

    strcat(id, currentId);


}

// Gets all the IDS and prints them out.
void getIDs(char (*elements)[100], int size)
{

    char checkedFiles[size][100];
    int index = 0;
    char id[20] = "";

    for (int i = size - 1; i >= 0; i--)
    {
        char currentFile[100];
        strcpy(currentFile, elements[i]);
       
        strtok(currentFile, " ");


        checkName(currentFile, checkedFiles, size);
        int _isPresent = isPresent(currentFile, checkedFiles, size);

        if (!_isPresent)
        {
            getActualId(elements[i], id);
            strcpy(checkedFiles[index], currentFile);
        }

        index++;
    }

        printf("\nID: %s",id );

}

int main()
{
    FILE *file = fopen("files.in", "r");
    if (file == NULL)
    {
        printf("Invalid file");
    }

    char currentLine[100];

    char fileContentArray[100][100];

    int lineIndex = 0;

    while (fgets(currentLine, 50, file) != NULL)
    {
        if (lineIndex == 0){
            lineIndex++;
            continue;
        }

        currentLine[strcspn(currentLine, "\n")] = 0;
        strcpy(fileContentArray[lineIndex], currentLine);

        lineIndex++;
    }

    for (int i = 0; i < lineIndex + 1; i++)
    {
        int isNumber = isANumber(fileContentArray[i]);
        
        if (isNumber)
        {
      
            int length = atoi(fileContentArray[i]);
            char  currentGroupedFiles[length][100];
            readIntoCurrentGroupedFiles(fileContentArray, i, atoi(fileContentArray[i]), currentGroupedFiles);


            int size = sizeof(currentGroupedFiles) / sizeof(*currentGroupedFiles);

            getIDs(currentGroupedFiles, size);


        }
    }

    fclose(file);

    return 0;
}