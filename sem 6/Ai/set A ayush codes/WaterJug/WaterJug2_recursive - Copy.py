import turtle

def draw_jug(x, y, capacity, current):
    # Draw the outline of the jug
    turtle.penup()
    turtle.goto(x, y)
    turtle.pendown()
    turtle.setheading(0)
    turtle.circle(20, 180)
    turtle.fd(40)
    turtle.circle(20, 180)
    turtle.fd(40)
    turtle.circle(20, 180)
    turtle.fd(40)
    turtle.left(90)
    turtle.fd(80)
    turtle.left(90)
    turtle.fd(120)
    turtle.left(90)
    turtle.fd(80)
    turtle.left(90)
    turtle.fd(40)
    
    # Fill the jug to the appropriate level
    turtle.penup()
    turtle.goto(x, y)
    turtle.setheading(0)
    turtle.fd(20)
    turtle.right(90)
    turtle.fd(40)
    turtle.pendown()
    turtle.begin_fill()
    turtle.fd(40)
    turtle.left(90)
    turtle.fd(80 * current / capacity)
    turtle.left(90)
    turtle.fd(40)
    turtle.left(90)
    turtle.fd(80 * current / capacity)
    turtle.end_fill()
    turtle.penup()
    
    # Write the capacity and current level of the jug
    turtle.goto(x + 60, y - 20)
    turtle.write(f"{current}/{capacity}", font=("Arial", 10, "normal"))

def draw_state(state, capacities):
    turtle.clear()
    draw_jug(-100, 0, capacities[0], state[0])
    draw_jug(100, 0, capacities[1], state[1])
    turtle.update()

def next_states(state, capacities):
    a, b = state
    ca, cb = capacities
    next_moves = []
    # fill jug a
    next_moves.append((ca, b))
    # fill jug b
    next_moves.append((a, cb))
    # empty jug a
    next_moves.append((0, b))
    # empty jug b
    next_moves.append((a, 0))
    # pour a to b until b is full or a is empty
    amt = min(a, cb-b)
    next_moves.append((a-amt, b+amt))
    # pour b to a until a is full or b is empty
    amt = min(ca-a, b)
    next_moves.append((a+amt, b-amt))
    return next_moves

def bfs_water_jug(start, goal, capacities, visited):
    if start == goal:
        draw_state(start, capacities)
        return True
    q = []
    q.append(start)
    visited.add(start)
    while q:
        curr_state = q.pop(0)
        draw_state(curr_state, capacities)
        for next_state in next_states(curr_state, capacities):
            if next_state not in visited:
                q.append(next_state)
                visited.add(next_state)
                if next_state == goal:
                    draw_state(next_state, capacities)
                    return True
    return False

# Taking input from the user
capacities = tuple(map(int, input("Enter the capacities of the jugs separated by a space (e.g. 3 5): ").split()))
start_state = tuple(map(int, input("Enter the initial state of the jugs separated by a space (e.g. 0 0): ").split()))
goal_state = tuple(map(int, input("Enter the goal state of the jugs separated by a space (e.g. 4 2): ").split()))
