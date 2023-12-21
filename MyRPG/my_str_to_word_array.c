/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-guillaume.lemoine
** File description:
** my_str_to_word_array
*/

#include "include/my.h"

int check_alpha(char ch)
{
    if (ch == '\n')
        return 0;
    return 1;
}

int calc_words(char const *str)
{
    int i = 0;
    int words = 1;
    int still = 0;

    while (str[i] != '\0') {
        if (check_alpha(str[i]) && still)
            still = 0;
        if (check_alpha(str[i]) == 0 && still == 0) {
            words++;
            still = 1;
        }
        i++;
    }
    return words;
}

char **my_str_to_word_array(char *str)
{
    int words = calc_words(str);
    char **array = malloc(sizeof(char *) * (words + 1));
    char *token = strtok(str, "\n");
    int i = 0;

    for (i = 0; token; i++) {
        array[i] = my_strdup(token);
        token = strtok(NULL, "\n");
    }
    array[i] = NULL;
    return array;
}
