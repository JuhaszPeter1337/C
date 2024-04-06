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

            char *values[4];

            for (int i = 0; i < 4 && splitted_line != NULL; i++){
                int length = get_line_length(splitted_line);
                values[i] = (char*) malloc(sizeof(char) * (length + 1));
                if (splitted_line[length - 1] == '\n')
                    splitted_line[length - 1] = '\0';
                strcpy(values[i], splitted_line);
                splitted_line = strtok(NULL, "|");
            }

            event->name = (char*) malloc(sizeof(char) * (strlen(values[0]) + 1));
            strcpy(event->name, values[0]);

            event->time = (char*) malloc(sizeof(char) * (strlen(values[1]) + 1));
            strcpy(event->time, values[1]);

            event->location = (char*) malloc(sizeof(char) * (strlen(values[2]) + 1));
            strcpy(event->location, values[2]);

            event->description = (char*) malloc(sizeof(char) * (strlen(values[3]) + 1));
            strcpy(event->description, values[3]);

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
