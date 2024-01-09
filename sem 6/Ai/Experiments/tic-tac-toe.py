# Define the players
PLAYER_X = "X"
PLAYER_O = "O"
EMPTY = "-"

# Define the board size
BOARD_SIZE = 3

# Print the board
def print_board(board):
    for row in board:
        print(" ".join(row))

# Check if the current state is a terminal state
def is_terminal(board):
    # Check rows
    for i in range(BOARD_SIZE):
        if board[i][0] == board[i][1] == board[i][2] != EMPTY:
            return True

    # Check columns
    for j in range(BOARD_SIZE):
        if board[0][j] == board[1][j] == board[2][j] != EMPTY:
            return True

    # Check diagonals
    if board[0][0] == board[1][1] == board[2][2] != EMPTY:
        return True
    if board[0][2] == board[1][1] == board[2][0] != EMPTY:
        return True

    # Check for a draw
    if all(board[i][j] != EMPTY for i in range(BOARD_SIZE) for j in range(BOARD_SIZE)):
        return True

    return False

# Determine the best move using a simple strategy
def get_best_move(board):
    # Find the first available empty cell and use it as the move
    for i in range(BOARD_SIZE):
        for j in range(BOARD_SIZE):
            if board[i][j] == EMPTY:
                return i, j

# Play the game
def play_game():
    board = [[EMPTY] * BOARD_SIZE for _ in range(BOARD_SIZE)]
    current_player = PLAYER_X

    while True:
        print("Current board:")
        print_board(board)

        if current_player == PLAYER_X:
            row, col = get_best_move(board)
            print(f"Player {current_player} chooses row {row}, col {col}")
        else:
            while True:
                try:
                    row = int(input("Enter the row (0-2): "))
                    col = int(input("Enter the column (0-2): "))
                    if 0 <= row < BOARD_SIZE and 0 <= col < BOARD_SIZE and board[row][col] == EMPTY:
                        break
                    else:
                        print("Invalid move! Try again.")
                except ValueError:
                    print("Invalid input! Try again.")

        board[row][col] = current_player

        if is_terminal(board):
            print("Current board:")
            print_board(board)
            if any(board[i][j] == PLAYER_X for i in range(BOARD_SIZE) for j in range(BOARD_SIZE)):
                print(f"Player {PLAYER_X} wins!")
            elif any(board[i][j] == PLAYER_O for i in range(BOARD_SIZE) for j in range(BOARD_SIZE)):
                print(f"Player {PLAYER_O} wins!")
            else:
                print("It's a draw!")
            break

        current_player = PLAYER_O if current_player == PLAYER_X else PLAYER_X

# Start the game
play_game()
