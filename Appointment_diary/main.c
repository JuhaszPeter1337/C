#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "event.h"
#include "file.h"
#include "time_calculate.h"

// Refactor

int main(void) {
    bool run = true;
    int choice, filter_choice, searching_choice, modifying_choice;

    // Define Event object
    Event *events = NULL;
    events = create_list("events.txt", events);

    while(run){
        options();
        printf("\nGive me a number from 1 to 8!\n");
        scanf("%d", &choice);
        getchar();

        char name[50], time[50], location[50], description[50];

        switch (choice) {
            case 1:
                printf("\nAll events:\n");
                printf("-----------\n");

                print_events(events);

                break;
            case 2:
                printf("\nAdding element:\n");
                printf("---------------\n");

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

                printf("\nGive me the current name of the event!\n");
                fgets(name, sizeof(name), stdin);
                name[strlen(name) - 1] = '\0';

                printf("\nGive me the current time of the event!\n");
                fgets(time, sizeof(time), stdin);
                time[strlen(time) - 1] = '\0';

                printf("\nGive me the current location of the event!\n");
                fgets(location, sizeof(location), stdin);
                location[strlen(location) - 1] = '\0';

                switch (modifying_choice){
                    case 1:
                        printf("\nGive me the new name of the event!\n");
                        fgets(mire, sizeof(mire), stdin);
                        mire[strlen(mire) - 1] = '\0';

                        item = modify_event(events, name, time, location, "name", mire);

                        if (item == 0)
                            printf("\nThe record does not exists!\n\n");

                        break;
                    case 2:
                        printf("\nGive me the new time of the event!\n");
                        fgets(mire, sizeof(mire), stdin);
                        mire[strlen(mire) - 1] = '\0';

                        item = modify_event(events, name, time, location, "date", mire);

                        if (item == 0)
                            printf("\nThe record does not exists!\n\n");

                        break;
                    case 3:
                        printf("\nGive me the new location of the event!\n");
                        fgets(mire, sizeof(mire), stdin);
                        mire[strlen(mire) - 1] = '\0';

                        item = modify_event(events, name, time, location, "location", mire);

                        if (item == 0)
                            printf("\nThe record does not exists!\n\n");

                        break;
                    case 4:
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
