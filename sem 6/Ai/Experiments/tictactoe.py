#Initializing empty board 
board = [
    ["-","-","-"], 
    ["-","-","-"],
    ["-","-","-"]] 

#Values of different ending positions which will help in determining value 
#of nodes of the decision tree

value_dict = {
    "X": 1,
    "tie": 0,
    "O": -1
}

def print_board_state(board):
    # Description - prints the current snapshot of the board to the console 
    
    # Arguments :-
    # board - a nested list which is the current snapshot of the board

    #Returns :-
    # nothing

    print("\n#########################\n")
    for row in board:
        print(row[0],row[1],row[2])
    print("\n#########################\n")


def winner(board):
    #Description - determines the winner of the current board or if it is Still not  clear who will win

    # Arguments :-
    # board - a nested list which is the current snapshot of the board

    #Returns :-
    # "X" - if X wins 
    # "O" - if O wins 
    # "tie" - if game is a tie 
    # "continue" - if the game has still not ended

    #horizontal win
    for i in range(len(board)):
        if board[i][0] == board[i][1] and board[i][1] == board[i][2]:
            if board[i][0] == "X":
                return "X"
            if board[i][0] == "O":
                return "O"

    #vertical win
    for i in range(len(board[0])):
        if board[0][i] == board[1][i] and board[1][i] == board[2][i]:
            if board[0][i] == "X":
                return "X"
            if board[0][i] == "O":
                return "O"

    #diagonal win 1
    if board[0][0] == board[1][1] and board[1][1] == board[2][2]:
            if board[0][0] == "X":
                return "X"
            if board[0][0] == "O":
                return "O"

    #diagonal win 2
    if board[2][0] == board[1][1] and board[1][1] == board[0][2]:
            if board[2][0] == "X":
                return "X"
            if board[2][0] == "O":
                return "O"

    #continue 
    for row in board:
        for cell in row:
            if cell == "-":
                return "continue"

    #tie
    return "tie"


def minimax(board, is_this_AIs_turn):
    #Description - Implementation of the minimax algorithm

    #Arguments :-
    #board - a nested list which is the current snapshot of the board
    #is_this_AIs_turn - a boolean which is true if AI is the current Player

    #Returns :-
    #the value of the current node 

    winner_player = winner(board)

    #if we reached the end of the tree
    if winner_player != "continue":
        return value_dict[winner_player]
    
    #if this is AIs turn i.e the maximizing players turn
    if is_this_AIs_turn:
        score = - 2               #anything smaller than min score
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "-":
                    board[i][j] = "X"
                    curr_score = minimax(board,False)
                    board[i][j] = "-"
                    score = max(score, curr_score)
        return score
    else:
        score =  2               #anything bigger than max score
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "-":
                    board[i][j] = "O"
                    curr_score = minimax(board,True)
                    board[i][j] = "-"
                    score = min(score, curr_score)
        return score

                

def ais_move(board):
    #Description - determines the next move of the AI

    #Arguments :-
    #board - a nested list which is the current snapshot of the board

    #Returns :-
    #an array with 2 items representing the coordinates of the cell 

    score = - 2               #anything smaller than min score
    x = -1                    #the row no. of cell which AI chosses for best move
    y = -1                    #the column no. of cell which AI chosses for best move

    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == "-":
                board[i][j] = "X"
                curr_score = minimax(board,False)
                board[i][j] = "-"
                if curr_score > score:
                    score = curr_score
                    x = i 
                    y = j
    return [x, y]




def game(board):
    #Description - the main function of the program which runs the game on the console

    #Arguments :-
    #board - a nested list which is the current snapshot of the board

    #Returns :-
    #nothing

    print("Welcome to Tic Tac Toe")

    will_play = input("Will you play with me? y/N  ")

    if(will_play.upper() == "Y"):

        #printing the initial empty board
        print("")
        print("Initial Empty Board-")
        print_board_state(board)
        print("")

        #playing the game until it ends
        while winner(board) == "continue":

            location = input("Enter space seperated row[0-2] and column[0-2] no (0-indexed) of the cell you want to choose: ")
            location = location.strip()
            while True:
                try:
                    space_pos = location.find(" ")
                    x = int(location[ : space_pos])
                    y = int(location[space_pos + 1 : ])

                    #if player makes an illegal move i.e chooses a cell which is already filled
                    if board[x][y] != "-" or space_pos == -1:
                        location = input("Please enter valid input for example '1 2'(Note: the entered cell should be empty): ")
                        continue

                    board[x][y] = "O"
                    break
                
                #if the player enters wrong or out of bounds cell location
                except:
                    location = input("Please enter valid input for example '1 2'(Note: the entered cell should be empty): ")
                    location = location.strip()


            print("")
            print("After your Move-")
            print_board_state(board)
            print("")

            #checking if the game has ended after the player's move
            if winner(board) == "O": 
                print("Congratulations! YOU WON")
                break

            elif winner(board) == "X": 
                print("HAHAHA! I WON")
                break

            elif winner(board) == "tie": 
                print("OOPS! It's a TIE")
                break

            #AI playing it's move
            AIs_turn = ais_move(board)
            x = AIs_turn[0]
            y = AIs_turn[1]
            board[x][y] = "X"

            print("After my Move-")
            print_board_state(board)
            print("")

            #checking if the game has ended after the AI's move
            if winner(board) == "O": 
                print("Congratulations! YOU WON")
                break

            elif winner(board) == "X": 
                print("HAHAHA! I WON")
                break

            elif winner(board) == "tie": 
                print("OOPS! It's a TIE")
                break

          
#calling the main function to start the game
game(board)


