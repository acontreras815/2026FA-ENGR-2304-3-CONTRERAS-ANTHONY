// 2026FA-ENGR-2304-3-CONTRERAS-ANTHONY-P06

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DATA 1000

int loadData(const char filename[], double data[]);
void displayData(const double data[], int count);
double calculateMean(const double data[], int count);
double calculateStdDev(const double data[], int count, double mean);
void createReport(const double data[], int count);
void searchData(const double data[], int count);

int main()
{
    double data[MAX_DATA];
    int count = 0;
    int choice;
    char filename[100];

    printf("Enter the data file name: ");
    scanf("%99s", filename);

    count = loadData(filename, data);

    if (count == 0)
    {
        printf("No data could be read from the file.\n");
        return 1;
    }

    do
    {
        printf("\n--- Data Analysis Menu ---\n");
        printf("1. Display data\n");
        printf("2. Analyze data\n");
        printf("3. Create report\n");
        printf("4. Search for a value\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            displayData(data, count);
        }

        else if (choice == 2)
        {
            double mean = calculateMean(data, count);
            double stdDev = calculateStdDev(data, count, mean);

            double min = data[0];
            double max = data[0];
            double sum = 0.0;

            int i;

            for (i = 0; i < count; i++)
            {
                sum += data[i];

                if (data[i] < min)
                    min = data[i];

                if (data[i] > max)
                    max = data[i];
            }

            printf("\n--- Statistical Analysis ---\n");
            printf("Number of values: %d\n", count);
            printf("Sum: %.3f\n", sum);
            printf("Mean: %.3f\n", mean);
            printf("Minimum: %.3f\n", min);
            printf("Maximum: %.3f\n", max);
            printf("Standard Deviation: %.3f\n", stdDev);
        }

        else if (choice == 3)
        {
            createReport(data, count);
        }

        else if (choice == 4)
        {
            searchData(data, count);
        }

        else if (choice == 5)
        {
            printf("Exiting program.\n");
        }

        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}

int loadData(const char filename[], double data[])
{
    FILE *file;
    char line[500];
    char *token;

    int count = 0;

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Unable to open file: %s\n", filename);
        return 0;
    }

    while (fgets(line, sizeof(line), file) != NULL && count < MAX_DATA)
    {
        token = strtok(line, ", \t\n\r");

        while (token != NULL && count < MAX_DATA)
        {
            data[count] = atof(token);
            count++;

            token = strtok(NULL, ", \t\n\r");
        }
    }

    fclose(file);

    printf("%d values loaded successfully.\n", count);

    return count;
}

void displayData(const double data[], int count)
{
    int i;

    printf("\n--- Data ---\n");

    for (i = 0; i < count; i++)
    {
        printf("%d: %.3f\n", i + 1, data[i]);
    }
}

double calculateMean(const double data[], int count)
{
    double sum = 0.0;
    int i;

    for (i = 0; i < count; i++)
    {
        sum += data[i];
    }

    return sum / count;
}

double calculateStdDev(const double data[], int count, double mean)
{
    double total = 0.0;
    int i;

    for (i = 0; i < count; i++)
    {
        total += (data[i] - mean) * (data[i] - mean);
    }

    return sqrt(total / count);
}

void createReport(const double data[], int count)
{
    FILE *report;

    double mean = calculateMean(data, count);
    double stdDev = calculateStdDev(data, count, mean);

    double min = data[0];
    double max = data[0];
    double sum = 0.0;

    int i;

    for (i = 0; i < count; i++)
    {
        sum += data[i];

        if (data[i] < min)
            min = data[i];

        if (data[i] > max)
            max = data[i];
    }

    report = fopen("report.txt", "w");

    if (report == NULL)
    {
        printf("Could not create report file.\n");
        return;
    }

    fprintf(report, "DATA ANALYSIS REPORT\n");
    fprintf(report, "--------------------\n");

    fprintf(report, "Number of values: %d\n", count);
    fprintf(report, "Sum: %.3f\n", sum);
    fprintf(report, "Mean: %.3f\n", mean);
    fprintf(report, "Minimum: %.3f\n", min);
    fprintf(report, "Maximum: %.3f\n", max);
    fprintf(report, "Standard Deviation: %.3f\n", stdDev);

    fprintf(report, "\nDATA VALUES\n");

    for (i = 0; i < count; i++)
    {
        fprintf(report, "%d: %.3f\n", i + 1, data[i]);
    }

    fclose(report);

    printf("Report created successfully as report.txt\n");
}

void searchData(const double data[], int count)
{
    double searchValue;

    int found = 0;
    int i;

    printf("Enter a value to search for: ");
    scanf("%lf", &searchValue);

    for (i = 0; i < count; i++)
    {
        if (fabs(data[i] - searchValue) < 0.0005)
        {
            printf("Value found at position %d.\n", i + 1);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Value was not found.\n");
    }
}