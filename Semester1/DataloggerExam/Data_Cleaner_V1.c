#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    //Open and read raw data file, sort the information and put them in the corrosponding arrays:
    int maxDataStringLength = 50;
    char* rawDataFileName = "C:\\Users\\jpive\\Documents\\programtest\\DATALOG.TXT";
    char* cleanDataFileName = "C:\\Users\\jpive\\Documents\\programtest\\CleanData.txt";

    FILE* rawDataFile = fopen(rawDataFileName, "r");
    if (rawDataFile == NULL) {
        perror("Error opening raw data file");
        return(-1);
    }
    int numberOfDataPoints = numberOfLines(rawDataFileName);
    int* tempIN = (float*)malloc(numberOfDataPoints * sizeof(float));
    int* humIN = (float*)malloc(numberOfDataPoints * sizeof(float));
    int* tempOUT = (float*)malloc(numberOfDataPoints * sizeof(float));
    int* humOUT = (float*)malloc(numberOfDataPoints * sizeof(float));
    int* light = (float*)malloc(numberOfDataPoints * sizeof(float));
    char** date = (char**)malloc(numberOfDataPoints * maxDataStringLength * sizeof(char));
    for (int i = 0; i < numberOfDataPoints; i++) {
        date[i] = (char*)malloc(maxDataStringLength * sizeof(char));
    }
    char** time = (char**)malloc(numberOfDataPoints * maxDataStringLength * sizeof(char));
    for (int i = 0; i < numberOfDataPoints; i++) {
        time[i] = (char*)malloc(maxDataStringLength * sizeof(char));
    }

    int subStringNumber = 0;
    int dataLineNumber = 0;
    int run = 1;
    char bufferString[50];

    while (run) {
        if (fgets(bufferString, maxDataStringLength, rawDataFile) != NULL) {
            char* token = strtok(bufferString, ",");
            while (token != NULL) {
                if (subStringNumber == 0) {
                    strcpy(date[dataLineNumber], token);
                }
                else if (subStringNumber == 1) {
                    strcpy(time[dataLineNumber], token);
                }
                else if (subStringNumber == 2) {
                    tempIN[dataLineNumber] = atof(token);
                }
                else if (subStringNumber == 3) {
                    humIN[dataLineNumber] = atof(token);
                }
                else if (subStringNumber == 4) {
                    tempOUT[dataLineNumber] = atof(token);
                }
                else if (subStringNumber == 5) {
                    humOUT[dataLineNumber] = atof(token);
                }
                else if (subStringNumber == 6) {
                    light[dataLineNumber] = atof(token);
                }
                token = strtok(NULL, ",");
                subStringNumber++;
            }
        }
        else {
            run = 0;
        }
        dataLineNumber++;
        subStringNumber = 0;
    }
    fclose(rawDataFile);

    FILE* cleanDataFile = fopen(cleanDataFileName, "w");
    for (int i = 0; i < numberOfDataPoints; i++) {
        if (strstr(time[i], "10:0")) {
            fprintf(cleanDataFile, "%s,%s,%d,%d,%d,%d,%d,\n", date[i], time[i], tempIN[i], humIN[i], tempOUT[i], humOUT[i], light[i]);
        }
        else if(strstr(time[i], "20:0")) {
            fprintf(cleanDataFile, "%s,%s,%d,%d,%d,%d,%d,\n", date[i], time[i], tempIN[i], humIN[i], tempOUT[i], humOUT[i], light[i]);
        }
        else if (strstr(time[i], "30:0")) {
            fprintf(cleanDataFile, "%s,%s,%d,%d,%d,%d,%d,\n", date[i], time[i], tempIN[i], humIN[i], tempOUT[i], humOUT[i], light[i]);
        }
        else if (strstr(time[i], "40:0")) {
            fprintf(cleanDataFile, "%s,%s,%d,%d,%d,%d,%d,\n", date[i], time[i], tempIN[i], humIN[i], tempOUT[i], humOUT[i], light[i]);
        }
        else if (strstr(time[i], "50:0")) {
            fprintf(cleanDataFile, "%s,%s,%d,%d,%d,%d,%d,\n", date[i], time[i], tempIN[i], humIN[i], tempOUT[i], humOUT[i], light[i]);
        }
        else if (strstr(time[i], "0:0")) {
            fprintf(cleanDataFile, "%s,%s,%d,%d,%d,%d,%d,\n", date[i], time[i], tempIN[i], humIN[i], tempOUT[i], humOUT[i], light[i]);
        }
    }
    fclose(cleanDataFile);


    //Free run time memory arrays:
    free(date);
    free(time);
    free(tempIN);
    free(humIN);
    free(tempOUT);
    free(humOUT);
    free(light);

    return(0);
}

//Function for counting the number of lines of data in the raw data file:
int numberOfLines(char* dataFileName) {
    FILE* fp;
    fp = fopen(dataFileName, "r");
    char str[60];
    int runs = 1;
    int numberOfLines = 0;
    while (runs) {
        if (fgets(str, 60, fp) != NULL) {
            numberOfLines++;
        }
        else {
            runs = 0;
        }
    }
    fclose(fp);
    return numberOfLines;
}
