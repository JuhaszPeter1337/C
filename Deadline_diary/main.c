#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
            printf("The item is already in the list!\n\n");
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

void modify_event(Event *list, char *name, char *date, char *location, char *mit, char *mire){
    for (Event *move = list; move != NULL; move = move->next){
        if (strcmp(move->name, name) == 0 && strcmp(move->time, date) == 0 && strcmp(move->location, location) == 0){
            if (strcmp(mit, "name") == 0)
                move->name = mire;
            else if (strcmp(mit, "date") == 0)
                move->time = mire;
            else if (strcmp(mit, "location") == 0)
                move->location = mire;
            else if (strcmp(mit, "description") == 0)
                move->description = mire;
            else
                printf("The given input was incorrect!\n\n");
        }
    }
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
    printf("Event(s) of year %s in ascending order:\n", year);
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
    printf("Event(s) of month %s/%s in ascending order:\n", year, month);
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
    printf("Event(s) of day %s/%s/%s in ascending order:\n", year, month, day);
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
}

void freeList(Event *list){
    Event *move = list;
    do {
        Event *tmp = move->next;
        free(move);
        move = tmp;
    } while (move != NULL);
}

int main(void) {
    /*
    int result = smaller_or_greater("2024/04/10 17:15", "2024/04/10 17:16");
    if (result == 1)
        printf("Az elso a nagyobb!\n\n");
    else
        printf("Az elso a kisebb!\n\n");
    */

    // Define Event object
    Event *events = NULL;

    // Create linked list from file
    events = create_list("events.txt", events);
    //print_events(events);

    // Add new element to linked list
    /*
    events = add_event(events, "Csuklo kontroll", "2024/04/10 17:15", "Budapest, 1095, Mester utca 45-49.", "Ferencvarosi szakrendelo");
    print_events(events);
    */

    // Delete event
    /*
    events = delete_event(events, "KEG Kocsmakviz", "2024/04/07 19:00", "Budapest, 1114, Orlay u. 1.");
    print_events(events);
    */

    // Modify event attribute
    /*
    print_events(events);
    modify_event(events, "Csuklo kontroll", "2024/04/10 17:15", "Budapest, 1095, Mester utca 45-49.", "name", "Csuklo kontrol");
    print_events(events);
    */

    // Print list by attribute
    /*
    Event *filtered_list;
    filtered_list = print_list_by_year(events, "2024");
    print_events(filtered_list);
    */

    /*
    Event *filtered_list;
    filtered_list = print_list_by_month(events, "2024", "04");
    print_events(filtered_list);
    */

    Event *filtered_list;
    filtered_list = print_list_by_day(events, "2024", "04", "10");
    print_events(filtered_list);

    // Search function testing section
    /*
    searchFunctionPtr fptr = search_by_name;
    Event *search_event = fptr(events, "KEG Kocsmakviz");
    if (search_event == NULL)
        printf("The element does not exist!\n");
    else
        print_events(search_event);
    fptr = search_by_date;
    search_event = fptr(events, "2024/04/12 16:20");
    if (search_event == NULL)
        printf("The element does not exist!\n");
    else
        print_events(search_event);
    fptr = search_by_location;
    search_event = fptr(events, "Budapest, 1095, Mester utca 45-49.");
    if (search_event == NULL)
        printf("The element does not exist!\n");
    else
        print_events(search_event);
    */

    // Write into file
    /*
    write_to_file("events.txt", events);
    */

    // Release the linked list
    freeList(events);
    return 0;
}
