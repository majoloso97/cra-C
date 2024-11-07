#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string compare_scores(string p1, string p2);
int score_string(string str);
int get_char_value(char c);

int main(void) {
    int score_player1;
    int score_player2;
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    score_player1 = score_string(player1);
    score_player2 = score_string(player2);
    if (score_player1 > score_player2) {
        printf("Player 1 wins!");
        return 0;
    }
    if (score_player1 < score_player2) {
        printf("Player 2 wins!");
        return 0;
    }
    printf("Tie!");
    return 0;
}

int score_string(string str) {
    int score = 0;
    for (int i = 0, n = strlen(str); i < n; i++) {
        score += get_char_value(str[i]);
    }
    return score;
}

int get_char_value(char c) {
    int char_key = toupper(c) - 'A';
    int scores[26];
    scores[0] = 1;
    scores[1] = 3;
    scores[2] = 3;
    scores[3] = 2;
    scores[4] = 1;
    scores[5] = 4;
    scores[6] = 2;
    scores[7] = 4;
    scores[8] = 1;
    scores[9] = 8;
    scores[10] = 5;
    scores[11] = 1;
    scores[12] = 3;
    scores[13] = 1;
    scores[14] = 1;
    scores[15] = 3;
    scores[16] = 10;
    scores[17] = 1;
    scores[18] = 1;
    scores[19] = 1;
    scores[20] = 1;
    scores[21] = 4;
    scores[22] = 4;
    scores[23] = 8;
    scores[24] = 4;
    scores[25] = 10;

    if (char_key < 26 && char_key >= 0) {
        return scores[char_key];
    }
    return 0;
}
