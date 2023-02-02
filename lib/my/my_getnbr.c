/*
** EPITECH PROJECT, 2022
** poollib
** File description:
** poollib
*/

int	my_getnbr(char *str)
{
    int i = 0;
    int n = 0;

    if (str[0] && str[0] == '-') {
        i++;
    }
    while (str[i]) {
        if ((str[i] < '0' || str[i] > '9')) {
            return (0);
        }
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    if (str[0] == '-') {
        return (-1 * n);
    } else {
        return (n);
    }
}
