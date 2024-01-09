from queue import PriorityQueue

class Board:
    def __init__(self, n):
        self.n = n
        self.queens = []
        self.heuristic = 0
        self.calculate_heuristic()

    def calculate_heuristic(self):
        for i in range(len(self.queens)):
            for j in range(i + 1, len(self.queens)):
                if self.queens[i] == self.queens[j]:  # same column
                    self.heuristic += 1
                offset = j - i
                if self.queens[i] == self.queens[j] - offset or self.queens[i] == self.queens[j] + offset:
                    self.heuristic += 1

    def __lt__(self, other):
        return self.heuristic < other.heuristic

class NQueens:
    def __init__(self, n):
        self.n = n
        self.solution = []

    # uses best first search algo 
    def solve(self):

        start = Board(self.n)

        q = PriorityQueue()
        q.put(start)

        while not q.empty():
            board = q.get()
            if len(board.queens) == self.n and board.heuristic == 0: #reached goal
                self.solution.append(board.queens)
                #print(board.queens)
                
            for i in range(self.n):  # checks if  col i is empty
                if i not in board.queens:
                    new_board = Board(self.n)
                    new_board.queens = board.queens + [i]
                    new_board.calculate_heuristic()
                    q.put(new_board)

        if len(self.solution) > 0:
            return True
        return False

    def print_solution(self):
        count = 0
        for solution in self.solution:
            if count < 3:
                count += 1
                for i in range(n):
                    for j in range(n):
                        if solution[i] == j:   # jth Q is present in ith col
                            print("Q",end=" ")
                        else:
                            print("X",end=" ")
                    print()
                print()

if __name__ == "__main__":
    n = int(input("Enter the number of queens: "))
    n_queens = NQueens(n)
    if n_queens.solve():
        n_queens.print_solution()
    else:
        print("No solution found")