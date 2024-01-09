max_player, min_player = 'x', 'o'

def evaluate_board(board):
    if all([board[i][j] == ' ' for i in range(3) for j in range(3)]):
        return 0

    if ['x']*3 in board:
        return 10

    if ['o']*3 in board:
        return -10

    for col in range(3):
        if len(set([board[row][col] for row in range(3)])) == 1 and board[1][col] != ' ':
            return 10 if board[1][col] == 'x' else -10

    if len(set([board[i][i] for i in range(3)])) == 1 and board[1][1] != ' ':
        return 10 if board[1][1] == 'x' else -10

    if len(set([board[i][2-i] for i in range(3)])) == 1 and board[1][1] != ' ':
        return 10 if board[1][1] == 'x' else -10

    return 0

def is_game_over(board):
    if evaluate_board(board) == 10 or evaluate_board(board) == -10:
        print("X won" if evaluate_board(board) == 10 else "O won")
        print(board)
        return True

    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                return False

    return True

def minimax(board, depth, is_max):
    score = evaluate_board(board)

    if score == 10 or score == -10:
        return score

    if is_game_over(board):
        return 0

    if is_max:
        best_score = -1000
        for i in range(3):
            for j in range(3):
                if board[i][j] == ' ':
                    board[i][j] = max_player
                    best_score = max(best_score, minimax(board, depth+1, not is_max))
                    board[i][j] = ' '
        return best_score
    else:
        best_score = 1000
        for i in range(3):
            for j in range(3):
                if board[i][j] == ' ':
                    board[i][j] = min_player
                    best_score = min(best_score, minimax(board, depth+1, not is_max))
                    board[i][j] = ' '
        return best_score

def find_best_move(board, is_max):
    best_val = -1000 if is_max else 1000
    best_move = (-1, -1)
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                board[i][j] = max_player if is_max else min_player
                move_val = minimax(board, 0, not is_max)
                board[i][j] = ' '
                if (is_max and move_val > best_val) or (not is_max and move_val < best_val):
                    best_move = (i, j)
                    best_val = move_val
    return best_move

def print_board(board):
    print()
    for i in range(3):
        for j in range(3):
            if j == 2:
                print(f" {board[i][j]} ")
            else:
                print(f" {board[i][j]} ", end='|')
        if i != 2:
            print("---+---+---")
    print()
    
if __name__ == "__main__":
    board = [
        [' ', ' ', ' '],
        [' ', ' ', ' '],
        [' ', ' ', ' ']
    ]
    print_board(board)
    print("Hello User! Welcome")

    choice = -1
    while choice not in ['x', 'o']:
        print("Play as [x/o]: ", end='')
        choice = input()
    if choice == 'x':
        user, pc = 'x', 'o'
        is_max = False
    else:
        user, pc = 'o', 'x'
        is_max = True

    choice = -1
    while choice not in ['y', 'n']:
        print("Do you want to make the first move? [y/n]: ", end='')
        choice = input()
    turn = "user"

    if choice == 'n':
        board[0][0] = pc
        print_board(board)

    turn = "user"

    while not is_game_over(board):
        if turn == "user":
            print("Enter the position to place", user)
            position_x, position_y = map(int, input().split(" "))
            board[position_x][position_y] = user
        else:
            best_move = find_best_move(board, is_max)
            board[best_move[0]][best_move[1]] = pc
            
        turn = "user" if turn == "pc" else "pc"
        print_board(board)