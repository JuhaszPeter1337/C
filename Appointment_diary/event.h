#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

typedef struct Event{
    char *name;
    char *time;
    char *location;
    char *description;
    struct Event *next;
} Event;

typedef Event* (*searchFunctionPtr)(Event*, char*);

Event *create_event(char *name, char *time, char *location, char *description);

int match(Event *item, char *name, char *time, char *location);

Event *add_event(Event *list, char *name, char *time, char *location, char *description);

Event *delete_event(Event *list, char *name, char *date, char *location);

Event *search_by_name(Event *list, char *name);
Event *search_by_date(Event *list, char *date);
Event *search_by_location(Event *list, char *location);

int modify_event(Event *list, char *name, char *date, char *location, char *mit, char *mire);

void print_events(Event *list);

Event *print_list_by_year(Event *list, char *year);
Event *print_list_by_month(Event *list, char *year, char *month);
Event *print_list_by_day(Event *list, char *year, char *month, char *day);

void freeList(Event *list);

#endif // EVENT_H_INCLUDED
