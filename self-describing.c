#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getCount(int integer, char *test)
{
    int counter = 0;
    for (int i = 0; i < strlen(test); i++)
    {

        char currentChar = test[i];

        int charAsInt = currentChar - '0';

        if (integer == charAsInt)
        {
            counter++;
        }
    }


    return counter;
}
int isSelfDescribing(char *test)

{

    test[strcspn(test, "\n")] = 0;


    int isSelfDescribing = 0;
    for (int integer = 0; integer < strlen(test); integer++)
    {
        char currentChar = test[integer];
        int currentCharAsInt = currentChar - '0';
        int noOfInteger = getCount(integer, test);

        if (noOfInteger == currentCharAsInt)
        {
            isSelfDescribing = 1;
        }
        else
        {
            isSelfDescribing = 0;
            break;
        }
    }

    return isSelfDescribing;
}
int main()
{

    FILE *file = fopen("self.in", "r");
    int totalTests;
    char currentLine[100];
    char allTests[1000][100];
    int index = 0;
    int lineCounter = 0;


    if (file == NULL)
    {
        printf("Invalid file");
    }

    while (fgets(currentLine, 50, file) != NULL)
    {

        if (index == 0)
        {
            totalTests = atoi(currentLine);
            index++;
            continue;
        }
        else
        {
            strcpy(allTests[lineCounter], currentLine);
            lineCounter++;
        }

        index++;
    }

    for (int i = 0; i < totalTests; i++)
    {
        int result = isSelfDescribing(allTests[i]);
        if (result == 1)
        {
            printf("\n%s is self describing", allTests[i]);
        }else if (result == 0){
            printf("\n%s is NOT self describing", allTests[i]);

        }
    }

    return 0;
}