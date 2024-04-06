#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

int get_line_length(char *name);
Event *create_list(char *filename, Event *list);
void write_to_file(char* filename, Event *list);

#endif // FILE_H_INCLUDED
