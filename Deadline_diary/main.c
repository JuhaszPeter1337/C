#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 100

typedef struct Event{
    char *name;
    char *time;
    char *place;
    char *description;
    struct Event *next;
} Event;

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
            event->place = (char*) malloc(sizeof(char) * (length + 1));
            strcpy(event->place, splitted_line);

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

Event *add_event(Event *list, char *name, char *time, char *place, char *description){
    Event *new_event = (Event*) malloc(sizeof(Event));

    new_event->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(new_event->name, name);

    new_event->time = (char*) malloc(sizeof(char) * (strlen(time) + 1));
    strcpy(new_event->time, time);

    new_event->place = (char*) malloc(sizeof(char) * (strlen(place) + 1));
    strcpy(new_event->place, place);

    new_event->description = (char*) malloc(sizeof(char) * (strlen(description) + 1));
    strcpy(new_event->description, description);

    new_event->next = list;

    return new_event;
}

void print_events(Event *list){
    for (Event *move = list; move != NULL; move = move->next){
        printf("Event name: %s\nEvent time: %s\nEvent place: %s\nEvent description: %s\n", move->name, move->time, move->place, move->description);
        printf("\n");
    }
}

Event *search_by_name(Event *list, char *name){
    for (Event *move = list; move != NULL; move = move->next){
        if (strcmp(move->name, name) == 0)
            return move;
    }
    return NULL;
}

void write_to_file(char* filename, Event *list){
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
        perror("The file cannot be opened!\n");
    else{
        for (Event *move = list; move != NULL; move = move->next)
            fprintf(fp, "%s|%s|%s|%s\n", move->name, move->time, move->place, move->description);
    }
    fclose(fp);
}

int main(void) {
    Event *events = NULL;
    events = create_list("esemenyek.txt", events);
    events = add_event(events, "Csuklo kontroll", "2024.04.10. 17:15", "Budapest, 1095, Mester utca 45-49.", "Ferencvarosi szakrendelo");
    print_events(events);
    Event *event = search_by_name(events, "KEG Kocsmakviz");
    if (event == NULL)
        printf("The element does not exist!\n");
    else
        printf("Event name: %s\nEvent time: %s\nEvent place: %s\nEvent description: %s\n", event->name, event->time, event->place, event->description);
    write_to_file("esemenyek.txt", events);
    return 0;
}
