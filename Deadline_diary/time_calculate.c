#include <time.h>

int smaller_or_greater(char *first, char *second){
    struct tm temp1 = {0};
    struct tm temp2 = {0};

    temp1.tm_hour = strtol(first + 11, NULL, 10);
    temp1.tm_min =  strtol(first + 14, NULL, 10);
    temp1.tm_mday = strtol(first + 8, NULL, 10);
    temp1.tm_mon = strtol(first + 5, NULL, 10) - 1;
    temp1.tm_year = strtol(first, NULL, 10) - 1900;

    temp2.tm_hour = strtol(second + 11, NULL, 10);
    temp2.tm_min =  strtol(second + 14, NULL, 10);
    temp2.tm_mday = strtol(second + 8, NULL, 10);
    temp2.tm_mon = strtol(second + 5, NULL, 10) - 1;
    temp2.tm_year = strtol(second, NULL, 10) - 1900;

    time_t unix_seconds1 = mktime(&temp1);
    time_t unix_seconds2 = mktime(&temp2);

    double actual_time_between = difftime(unix_seconds1, unix_seconds2);
    if (actual_time_between < 0)
        return -1;
    else
        return 1;
}
