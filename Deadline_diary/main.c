#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define LINE_LENGTH 100

// Menu
// Refactor
// Split into files

typedef struct Event{
    char *name;
    char *time;
    char *location;
    char *description;
    struct Event *next;
} Event;

typedef Event* (*searchFunctionPtr)(Event*, char*);

int get_line_length(char *name){
    int length = strlen(name);
    return length;
}

Event *create_list(char *filename, Event *list){
    FILE *fp = fopen(filename, "r");
    Event *start = list;
    if (fp == NULL){
        perror("The file cannot be opened!\n");
        return NULL;
    }
    else{
        char line[LINE_LENGTH];
        while (fgets(line, LINE_LENGTH, fp) != NULL) {
            Event *event = (Event*) malloc(sizeof(Event));

            char *splitted_line = strtok(line, "|");

            int length = get_line_length(splitted_line);
            event->name = (char*) malloc(sizeof(char) * (length + 1));
            strcpy(event->name, splitted_line);

            splitted_line = strtok(NULL, "|");

            length = get_line_length(splitted_line);
            event->time = (char*) malloc(sizeof(char) * (length + 1));
            strcpy(event->time, splitted_line);

            splitted_line = strtok(NULL, "|");

            length = get_line_length(splitted_line);
            event->location = (char*) malloc(sizeof(char) * (length + 1));
            strcpy(event->location, splitted_line);

            splitted_line = strtok(NULL, "|");

            length = get_line_length(splitted_line);
            event->description = (char*) malloc(sizeof(char) * (length + 1));
            if (splitted_line[length - 1] == '\n')
                splitted_line[length - 1] = '\0';
            strcpy(event->description, splitted_line);

            event->next = start;
            start = event;
        }
    }
    fclose(fp);
    return start;
}

Event *add_event(Event *list, char *name, char *time, char *location, char *description){
    for (Event *move = list; move != NULL; move = move->next){
        if (strcmp(move->name, name) == 0 && strcmp(move->time, time) == 0 && strcmp(move->location, location) == 0){
            printf("\nThe item is already in the list!\n\n");
            return list;
        }
    }
    Event *new_event = (Event*) malloc(sizeof(Event));

    new_event->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(new_event->name, name);

    new_event->time = (char*) malloc(sizeof(char) * (strlen(time) + 1));
    strcpy(new_event->time, time);

    new_event->location = (char*) malloc(sizeof(char) * (strlen(location) + 1));
    strcpy(new_event->location, location);

    new_event->description = (char*) malloc(sizeof(char) * (strlen(description) + 1));
    strcpy(new_event->description, description);

    new_event->next = list;

    return new_event;
}

Event *search_by_name(Event *list, char *name){
    Event *new_list = NULL;
    for (Event *move = list; move != NULL; move = move->next){
        if (strcmp(move->name, name) == 0)
            new_list = add_event(new_list, move->name, move->time, move->location, move->description);
    }
    return new_list;
}

Event *search_by_date(Event *list, char *date){
    Event *new_list = NULL;
    for (Event *move = list; move != NULL; move = move->next){
        if (strcmp(move->time, date) == 0)
            new_list = add_event(new_list, move->name, move->time, move->location, move->description);
    }
    return new_list;
}

Event *search_by_location(Event *list, char *location){
    Event *new_list = NULL;
    for (Event *move = list; move != NULL; move = move->next){
        if (strcmp(move->location, location) == 0)
            new_list = add_event(new_list, move->name, move->time, move->location, move->description);
    }
    return new_list;
}

Event *delete_event(Event *list, char *name, char *date, char *location){
    Event *move = list;
    Event *move_behind = NULL;

    if (list == NULL)
        return NULL;
    while (move != NULL){
        if (strcmp(move->name, name) == 0 && strcmp(move->time, date) == 0 && strcmp(move->location, location) == 0) {
            Event *delete_item = move;
            move = move->next;
            if (move_behind == NULL)
                list = move;
            else
                move_behind->next = move;
            free(delete_item);
        }
        else{
            move_behind = move;
            move = move->next;
        }
    }
    return list;
}

int modify_event(Event *list, char *name, char *date, char *location, char *mit, char *mire){
    int found = 0;
    for (Event *move = list; move != NULL; move = move->next){
        if (strcmp(move->name, name) == 0 && strcmp(move->time, date) == 0 && strcmp(move->location, location) == 0){
            found = 1;
            if (strcmp(mit, "name") == 0)
                strcpy(move->name, mire);
            else if (strcmp(mit, "date") == 0)
                strcpy(move->time, mire);
            else if (strcmp(mit, "location") == 0)
                strcpy(move->location, mire);
            else if (strcmp(mit, "description") == 0)
                strcpy(move->description, mire);
        }
    }
    return found;
}

void print_events(Event *list){
    for (Event *move = list; move != NULL; move = move->next){
        printf("Event name: %s\nEvent time: %s\nEvent location: %s\nEvent description: %s\n", move->name, move->time, move->location, move->description);
        printf("\n");
    }
}

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

Event *print_list_by_year(Event *list, char *year){
    printf("\nEvent(s) of year %s in ascending order:\n", year);
    printf("-----------------------------------------\n");
    Event *new_list = NULL;
    for (Event *move = list; move != NULL; move = move->next){
        char *substr = (char*) malloc(sizeof(char) * 2);
        strncpy(substr, move->time, 4);
        substr[4] = '\0';
        if (strcmp(substr, year) == 0){
            if (new_list == NULL || smaller_or_greater(move->time, new_list->time) == -1){
                new_list = add_event(new_list, move->name, move->time, move->location, move->description);
            }
            else{
                Event *new_unit = (Event*) malloc(sizeof(Event));

                new_unit->name = (char*) malloc(sizeof(char) * (strlen(move->name) + 1));
                strcpy(new_unit->name, move->name);
                new_unit->time = (char*) malloc(sizeof(char) * (strlen(move->time) + 1));
                strcpy(new_unit->time, move->time);
                new_unit->location = (char*) malloc(sizeof(char) * (strlen(move->location) + 1));
                strcpy(new_unit->location, move->location);
                new_unit->description = (char*) malloc(sizeof(char) * (strlen(move->description) + 1));
                strcpy(new_unit->description, move->description);

                Event *item = new_list;
                Event *item_behind = NULL;

                while (item != NULL && smaller_or_greater(move->time, item->time) == 1){
                    item_behind = item;
                    item = item->next;
                }
                new_unit->next = item;
                item_behind->next = new_unit;
            }
        }
    }
    return new_list;
}

Event *print_list_by_month(Event *list, char *year, char *month){
    printf("\nEvent(s) of month %s/%s in ascending order:\n", year, month);
    printf("---------------------------------------------\n");
    Event *new_list = NULL;
    for (Event *move = list; move != NULL; move = move->next){
        char *substr = (char*) malloc(sizeof(char) * 2);
        strncpy(substr, move->time, 7);
        substr[7] = '\0';
        char date[10];
        strcpy(date, year);
        strcat(date, "/");
        strcat(date, month);
        if (strcmp(substr, date) == 0){
            if (new_list == NULL || smaller_or_greater(move->time, new_list->time) == -1){
                new_list = add_event(new_list, move->name, move->time, move->location, move->description);
            }
            else{
                Event *new_unit = (Event*) malloc(sizeof(Event));

                new_unit->name = (char*) malloc(sizeof(char) * (strlen(move->name) + 1));
                strcpy(new_unit->name, move->name);
                new_unit->time = (char*) malloc(sizeof(char) * (strlen(move->time) + 1));
                strcpy(new_unit->time, move->time);
                new_unit->location = (char*) malloc(sizeof(char) * (strlen(move->location) + 1));
                strcpy(new_unit->location, move->location);
                new_unit->description = (char*) malloc(sizeof(char) * (strlen(move->description) + 1));
                strcpy(new_unit->description, move->description);

                Event *item = new_list;
                Event *item_behind = NULL;

                while (item != NULL && smaller_or_greater(move->time, item->time) == 1){
                    item_behind = item;
                    item = item->next;
                }
                new_unit->next = item;
                item_behind->next = new_unit;
            }
        }
    }
    return new_list;
}

Event *print_list_by_day(Event *list, char *year, char *month, char *day){
    printf("\nEvent(s) of day %s/%s/%s in ascending order:\n", year, month, day);
    printf("----------------------------------------------\n");
    Event *new_list = NULL;
    for (Event *move = list; move != NULL; move = move->next){
        char *substr = (char*) malloc(sizeof(char) * 2);
        strncpy(substr, move->time, 10);
        substr[10] = '\0';
        char date[15];
        strcpy(date, year);
        strcat(date, "/");
        strcat(date, month);
        strcat(date, "/");
        strcat(date, day);
        if (strcmp(substr, date) == 0){
            if (new_list == NULL || smaller_or_greater(move->time, new_list->time) == -1){
                new_list = add_event(new_list, move->name, move->time, move->location, move->description);
            }
            else{
                Event *new_unit = (Event*) malloc(sizeof(Event));

                new_unit->name = (char*) malloc(sizeof(char) * (strlen(move->name) + 1));
                strcpy(new_unit->name, move->name);
                new_unit->time = (char*) malloc(sizeof(char) * (strlen(move->time) + 1));
                strcpy(new_unit->time, move->time);
                new_unit->location = (char*) malloc(sizeof(char) * (strlen(move->location) + 1));
                strcpy(new_unit->location, move->location);
                new_unit->description = (char*) malloc(sizeof(char) * (strlen(move->description) + 1));
                strcpy(new_unit->description, move->description);

                Event *item = new_list;
                Event *item_behind = NULL;

                while (item != NULL && smaller_or_greater(move->time, item->time) == 1){
                    item_behind = item;
                    item = item->next;
                }
                new_unit->next = item;
                item_behind->next = new_unit;
            }
        }
    }
    return new_list;
}

void write_to_file(char* filename, Event *list){
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
        perror("The file cannot be opened!\n");
    else{
        for (Event *move = list; move != NULL; move = move->next)
            fprintf(fp, "%s|%s|%s|%s\n", move->name, move->time, move->location, move->description);
    }
    fclose(fp);
    printf("Writing to the file was successful!\n\n");
}

void freeList(Event *list){
    Event *move = list;
    do {
        Event *tmp = move->next;
        free(move);
        move = tmp;
    } while (move != NULL);
}

void options(){
    printf("Choose from these options and write one number!\n\n");
    char *options_array[] = {"Print all events", "Add element to linked list", "Delete element from linked list",
                            "Modify event attribute", "Print list by attribute", "Search by attribute", "Write into file", "Exit"};
    int array_length = sizeof(options_array) / sizeof(options_array[0]);
    for (int i = 0; i < array_length; i++)
        printf("%i. %s\n", i + 1, options_array[i]);
}

void options_for_searching(){
    printf("\nChose from the searching options and write on number!\n\n");
    char *options_array[] = {"Search by name", "Search by date", "Search by location"};
    int array_length = sizeof(options_array) / sizeof(options_array[0]);
    for (int i = 0; i < array_length; i++)
        printf("%i. %s\n", i + 1, options_array[i]);
}

void options_for_filtering(){
    printf("\nChose from the filtering options and write on number!\n\n");
    char *options_array[] = {"Year filter", "Month filter", "Day filter"};
    int array_length = sizeof(options_array) / sizeof(options_array[0]);
    for (int i = 0; i < array_length; i++)
        printf("%i. %s\n", i + 1, options_array[i]);
}

void options_for_modifying(){
    printf("Chose from the modifying options and write on number!\n\n");
    char *options_array[] = {"Name attribute", "Time attribute", "Location attribute", "Description attribute"};
    int array_length = sizeof(options_array) / sizeof(options_array[0]);
    for (int i = 0; i < array_length; i++)
        printf("%i. %s\n", i + 1, options_array[i]);
}

int main(void) {
    bool run = true;
    int choice, filter_choice, searching_choice, modifying_choice;

    // Define Event object
    Event *events = NULL;
    events = create_list("events.txt", events);

    while(run){
        options();
        printf("\nGive me a number from 1 to 7!\n");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\nAll events:\n");
                printf("-----------\n");

                print_events(events);

                break;
            case 2:
                printf("\nAdding element:\n");
                printf("---------------\n");

                char name[50], time[50], location[50], description[50];

                printf("Give me the event name! ");
                fgets(name, sizeof(name), stdin);
                printf("Give me the event time! ");
                fgets(time, sizeof(time), stdin);
                printf("Give me the event location! ");
                fgets(location, sizeof(location), stdin);
                printf("Give me the event description! ");
                fgets(description, sizeof(description), stdin);

                name[strlen(name) - 1] = '\0';
                time[strlen(time) - 1] = '\0';
                location[strlen(location) - 1] = '\0';
                description[strlen(description) - 1] = '\0';

                events = add_event(events, name, time, location, description);

                break;
            case 3:
                printf("\nDeleting element:\n");
                printf("---------------\n");

                printf("Give me the event name! ");
                fgets(name, sizeof(name), stdin);
                printf("Give me the event time! ");
                fgets(time, sizeof(time), stdin);
                printf("Give me the event location! ");
                fgets(location, sizeof(location), stdin);

                name[strlen(name) - 1] = '\0';
                time[strlen(time) - 1] = '\0';
                location[strlen(location) - 1] = '\0';
                description[strlen(description) - 1] = '\0';

                events = delete_event(events, name, time, location);

                break;
            case 4:
                printf("\nModifying element:\n");
                printf("------------------\n");

                options_for_modifying();

                printf("\nGive me a number from 1 to 4!\n");
                scanf("%d", &modifying_choice);
                getchar();

                char mire[50];

                int item;

                switch (modifying_choice){
                    case 1:
                        printf("\nGive me the current name of the event!\n");
                        fgets(name, sizeof(name), stdin);
                        name[strlen(name) - 1] = '\0';

                        printf("\nGive me the current time of the event!\n");
                        fgets(time, sizeof(time), stdin);
                        time[strlen(time) - 1] = '\0';

                        printf("\nGive me the current location of the event!\n");
                        fgets(location, sizeof(location), stdin);
                        location[strlen(location) - 1] = '\0';

                        printf("\nGive me the new name of the event!\n");
                        fgets(mire, sizeof(mire), stdin);
                        mire[strlen(mire) - 1] = '\0';

                        item = modify_event(events, name, time, location, "name", mire);

                        if (item == 0)
                            printf("\nThe record does not exists!\n\n");

                        break;
                    case 2:
                        printf("\nGive me the current name of the event!\n");
                        fgets(name, sizeof(name), stdin);
                        name[strlen(name) - 1] = '\0';

                        printf("\nGive me the current time of the event!\n");
                        fgets(time, sizeof(time), stdin);
                        time[strlen(time) - 1] = '\0';

                        printf("\nGive me the current location of the event!\n");
                        fgets(location, sizeof(location), stdin);
                        location[strlen(location) - 1] = '\0';

                        printf("\nGive me the new time of the event!\n");
                        fgets(mire, sizeof(mire), stdin);
                        mire[strlen(mire) - 1] = '\0';

                        item = modify_event(events, name, time, location, "date", mire);

                        if (item == 0)
                            printf("\nThe record does not exists!\n\n");

                        break;
                    case 3:
                        printf("\nGive me the current name of the event!\n");
                        fgets(name, sizeof(name), stdin);
                        name[strlen(name) - 1] = '\0';

                        printf("\nGive me the current time of the event!\n");
                        fgets(time, sizeof(time), stdin);
                        time[strlen(time) - 1] = '\0';

                        printf("\nGive me the current location of the event!\n");
                        fgets(location, sizeof(location), stdin);
                        location[strlen(location) - 1] = '\0';

                        printf("\nGive me the new location of the event!\n");
                        fgets(mire, sizeof(mire), stdin);
                        mire[strlen(mire) - 1] = '\0';

                        item = modify_event(events, name, time, location, "location", mire);

                        if (item == 0)
                            printf("\nThe record does not exists!\n\n");

                        break;
                    case 4:
                        printf("\nGive me the current name of the event!\n");
                        fgets(name, sizeof(name), stdin);
                        name[strlen(name) - 1] = '\0';

                        printf("\nGive me the current time of the event!\n");
                        fgets(time, sizeof(time), stdin);
                        time[strlen(time) - 1] = '\0';

                        printf("\nGive me the current location of the event!\n");
                        fgets(location, sizeof(location), stdin);
                        location[strlen(location) - 1] = '\0';

                        printf("\nGive me the new description of the event!\n");
                        fgets(mire, sizeof(mire), stdin);
                        mire[strlen(mire) - 1] = '\0';

                        item = modify_event(events, name, time, location, "description", mire);

                        if (item == 0)
                            printf("\nThe record does not exists!\n\n");

                        break;
                }

                break;
            case 5:
                options_for_filtering();

                printf("\nGive me a number from 1 to 3!\n");
                scanf("%d", &filter_choice);
                getchar();

                Event *filtered_list;

                char year[50], month[50], day[50];

                switch (filter_choice){
                    case 1:
                        printf("\nGive me the year you are looking for!\n");
                        fgets(year, sizeof(year), stdin);
                        year[strlen(year) - 1] = '\0';

                        filtered_list = print_list_by_year(events, year);
                        print_events(filtered_list);

                        break;
                    case 2:
                        printf("\nGive me the year you are looking for!\n");
                        fgets(year, sizeof(year), stdin);
                        year[strlen(year) - 1] = '\0';

                        printf("\nGive me the month you are looking for!\n");
                        fgets(month, sizeof(month), stdin);
                        month[strlen(month) - 1] = '\0';

                        filtered_list = print_list_by_month(events, year, month);
                        print_events(filtered_list);

                        break;
                    case 3:
                        printf("\nGive me the year you are looking for!\n");
                        fgets(year, sizeof(year), stdin);
                        year[strlen(year) - 1] = '\0';

                        printf("\nGive me the month you are looking for!\n");
                        fgets(month, sizeof(month), stdin);
                        month[strlen(month) - 1] = '\0';

                        printf("\nGive me the day you are looking for!\n");
                        fgets(day, sizeof(day), stdin);
                        day[strlen(day) - 1] = '\0';

                        filtered_list = print_list_by_day(events, year, month, day);
                        print_events(filtered_list);

                        break;
                }

                break;
            case 6:
                options_for_searching();

                printf("\nGive me a number from 1 to 3!\n");
                scanf("%d", &searching_choice);
                getchar();

                searchFunctionPtr fptr;

                switch (searching_choice){
                    case 1:
                        fptr = search_by_name;
                        printf("\nGive me the name you are looking for!\n");

                        fgets(name, sizeof(name), stdin);
                        name[strlen(name) - 1] = '\0';

                        Event *search_event = fptr(events, name);
                        if (search_event == NULL)
                            printf("\nThe element does not exist!\n");
                        else{
                            printf("\nThe searched element:\n");
                            printf("---------------------\n");
                            print_events(search_event);
                        }

                        break;
                    case 2:
                        fptr = search_by_date;
                        printf("\nGive me the time you are looking for!\n");

                        fgets(time, sizeof(time), stdin);
                        time[strlen(time) - 1] = '\0';

                        search_event = fptr(events, time);
                        if (search_event == NULL)
                            printf("\nThe element does not exist!\n");
                        else{
                            printf("\nThe searched element:\n");
                            printf("---------------------\n");
                            print_events(search_event);
                        }

                        break;
                    case 3:
                        fptr = search_by_location;

                        printf("\nGive me the location you are looking for!\n");

                        fgets(location, sizeof(location), stdin);
                        location[strlen(location) - 1] = '\0';

                        search_event = fptr(events, location);
                        if (search_event == NULL)
                            printf("\nThe element does not exist!\n");
                        else{
                            printf("\nThe searched element:\n");
                            printf("---------------------\n");
                            print_events(search_event);
                        }

                        break;
                }

                break;
            case 7:
                printf("\Printing the events into file:\n");
                printf("-------------------------------\n");

                write_to_file("events.txt", events);

                break;
            case 8:
                printf("\nThis application is about to exit!\n");

                freeList(events);

                run = false;

                break;
        }
    }

    return 0;
}
