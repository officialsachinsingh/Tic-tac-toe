#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // Tic-Tac-Toe board

// Function to initialize the board
void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the board
void display_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int is_game_over() {
    int i, j;

    // Check rows and columns for a win
    for (i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return 1;
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return 1;
    }

    // Check diagonals for a win
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return 1;
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return 1;

    // Check if the board is full (draw)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-')
                return 0; // Game is not over yet
        }
    }
    return 2; // Draw
}

// Function to check if the move is valid
int is_valid_move(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return 0; // Invalid position
    if (board[row][col] != '-')
        return 0; // Position already occupied
    return 1; // Valid move
}

// Function to make a move
void make_move(char player) {
    int row, col;
    printf("Player %c's turn. Enter row and column (0-2): ", player);
    scanf("%d %d", &row, &col);
    if (!is_valid_move(row, col)) {
        printf("Invalid move. Please try again.\n");
        make_move(player);
    } else {
        board[row][col] = player;
    }
}

int main() {
    char player = 'X';
    int game_status;

    initialize_board();
    display_board();

    while (1) {
        make_move(player);
        display_board();
        game_status = is_game_over();
        if (game_status == 1) {
            printf("Player %c wins!\n", player);
            break;
        } else if (game_status == 2) {
            printf("It's a draw!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
