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
