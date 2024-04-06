#include <stdlib.h>
#include "event.h"

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

Event *create_event(char *name, char *time, char *location, char *description){
    Event *new_unit = (Event*) malloc(sizeof(Event));

    new_unit->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(new_unit->name, name);
    new_unit->time = (char*) malloc(sizeof(char) * (strlen(time) + 1));
    strcpy(new_unit->time, time);
    new_unit->location = (char*) malloc(sizeof(char) * (strlen(location) + 1));
    strcpy(new_unit->location, location);
    new_unit->description = (char*) malloc(sizeof(char) * (strlen(description) + 1));
    strcpy(new_unit->description, description);

    return new_unit;
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
                Event *new_unit = create_event(move->name, move->time, move->location, move->description);

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
                Event *new_unit = create_event(move->name, move->time, move->location, move->description);

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
                Event *new_unit = create_event(move->name, move->time, move->location, move->description);

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

void freeList(Event *list){
    Event *move = list;
    do {
        Event *tmp = move->next;
        free(move);
        move = tmp;
    } while (move != NULL);
}
