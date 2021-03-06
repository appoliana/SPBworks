#pragma once

//The list element
struct Contact;

//The pointer to the least element
struct List;

//The menu with different options
bool menu();

//The function to make the list
Notebook *createNotebook();

//The function deleting the whole list
void deleteNotebook(Notebook *notebook);

//The function printing the whole list
void print(Notebook *notebook);

//Merge sort
void mergeSort(Notebook *notebook, bool choice);