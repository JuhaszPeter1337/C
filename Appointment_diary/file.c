#include <stdio.h>
#include "event.h"

#define LINE_LENGTH 100

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
