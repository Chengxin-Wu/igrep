//
//  main.c
//  igrap
//
//  Created by Chengxin Wu on 9/10/20.
//  Copyright © 2020 Chengxin Wu. All rights reserved.
//
//Name: Chengxin Wu
//Semester:
//it can search a string in a txt file.
//-i will ignore the case of the string argument.
//-n will print the line number, then colon in front of the found text.
//-h print a usage message and then immediately exit

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

//it will search the word or centence whitout case of the string argument. like flag -i
void iGrep_i(char line[], char *word)
{
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
        char line2[MAX_LINE_LENGTH];
        strcpy(line2, line);
        char *c = &line2[0];
        while (*c != '\0') { // until end of string
            *c = toupper(*c);
            c++;
            }
        if (strstr(line2,word) != NULL)
        {
            printf("%s",line);
        }
    }
}

//it will search the word or centence and print the line number,
//then colon in front of the found text. like flag n
void iGrep_n(char line[], char *word)
{
    int row = 1;
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
        if (strstr(line,word) != NULL)
        {
            printf("%d,%s",row,line);
        }
        row = row + 1;
    }
}

// it will search the word or centence without case of the string argument
//and print the line number,
//then colon in front of the found text . like flag n
void iGrep_i_n(char line[], char *word)
{
    int row = 1;
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
        char line2[MAX_LINE_LENGTH];
        strcpy(line2, line);
        char *c = &line2[0];
        while (*c != '\0') { // until end of string
            *c = toupper(*c);
            c++;
            }
        if (strstr(line2,word) != NULL)
        {
            printf("%d,%s", row,line);
        }
        row = row + 1;
    }
}

//it will print the line whichc contain the target string.
void iGRep(char line[],char *word)
{
    while (fgets(line, MAX_LINE_LENGTH, stdin))
    {
        if (strstr(line,word) != NULL)
        {
            printf("%s",line);
        }
    }
}


bool Igrep_I = false;
bool Igrep_N = false;
bool Igrep_H = false;

int main(int argc, char **argv)
{
    char line[MAX_LINE_LENGTH];
    char *word;
    for(int i = 0; i < argc; i++ )
    {
        char *a = argv[i];
        if (strncmp(a, "-i", 2) == 0)
        {
            Igrep_I = true;
        }
        else if (strncmp(a, "-n", 2) == 0)
        {
            Igrep_N = true;
        }
        else if (strncmp(a, "-h", 2) == 0)
        {
            Igrep_H = true;
        }
        else if (strncmp(a, "-" , 1) != 0)
        {
            word = argv[i];
        }
        else
        {
            printf("wrong flag\n");
            exit(1);
        }
    }
    
    if (Igrep_H == true)
    {
        printf("you can use -i and -n\n");
        exit(0);
    }
    if(Igrep_I == true && Igrep_N == true)
    {
        char *c = &word[0];
        while(*c != '\0')
        {
            *c = toupper(*c);
            c++;
        }
        iGrep_i_n(line,word);
    }
    else if(Igrep_N == true && Igrep_I == false)
    {
        iGrep_n(line,word);
    }
    else if(Igrep_I == true && Igrep_N == false)
    {
        char *c = &word[0];
        while(*c != '\0')
        {
            *c = toupper(*c);
            c++;
        }
        iGrep_i(line,word);
    }
    else if(Igrep_H == false && Igrep_N == false && Igrep_I == false)
    {
        iGRep(line,word);
    }
}
