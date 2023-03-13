import pygame

# Initialize the game engine
pygame.init()

# Set the window size
window_size = (500, 500)

# Create the window
window = pygame.display.set_mode(window_size)

# Set the title of the window
pygame.display.set_caption("Movement Game")

# Set the background color of the window
background_color = (255, 255, 255)

# Set the clock for the game
clock = pygame.time.Clock()

# Load the player image
player_image = pygame.image.load("player.jpg")

# Get the player rectangle
player_rect = player_image.get_rect()

# Set the initial position of the player
player_rect.x = window_size[0] // 2
player_rect.y = window_size[1] // 2

# Set the speed of the player
player_speed = 5

# Define the buttons
buttons = [
    pygame.Rect(10, 10, 50, 50),
    pygame.Rect(70, 10, 50, 50),
    pygame.Rect(10, 70, 50, 50),
    pygame.Rect(70, 70, 50, 50),
]

# Define the button text
button_text = ["UP", "DOWN", "LEFT", "RIGHT"]

# Define the button colors
button_colors = [(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0)]

# Run the game loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Check if the player clicked on a button
    mouse_pos = pygame.mouse.get_pos()
    for i, button in enumerate(buttons):
        if button.collidepoint(mouse_pos):
            if pygame.mouse.get_pressed()[0]:
                if i == 0:
                    player_rect.y -= player_speed
                elif i == 1:
                    player_rect.y += player_speed
                elif i == 2:
                    player_rect.x -= player_speed
                else:
                    player_rect.x += player_speed

    # Clear the window
    window.fill(background_color)

    # Draw the buttons
    for i, button in enumerate(buttons):
        pygame.draw.rect(window, button_colors[i], button)
        label = pygame.font.Font(None, 20).render(button_text[i], True, (0, 0, 0))
        window.blit(label, (button.x + 10, button.y + 10))

    # Draw the player
    window.blit(player_image, player_rect)

    # Update the window
    pygame.display.update()

    # Set the clock tick rate
    clock.tick(60)

# Quit the game engine
pygame.quit()