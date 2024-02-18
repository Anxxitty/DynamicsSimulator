import pygame
import time
from reader import Reader

# Program initialization
scale = int(input("scale? "))
pygame.init()
pygame.display.set_caption("Dynamics Simulator Visualizer")
screen = pygame.display.set_mode((1280, 720))
running = True
initialTimestamp = time.time_ns() / 1000000
tennis_ball = pygame.transform.scale(pygame.image.load("tennis-ball.png"), (int(75*scale/200),int(50*scale/200)))

while running:
    with Reader.openWithName("output.csv") as file:

        previousTimestamp = time.time_ns() / 1000000
        deltaTime = 0
        color = [0, 0, 0]

        for line in file:

            if not running:
                break

            csvDeltaTime = float(line[0])
            x = float(line[1])
            y = float(line[2])

            while deltaTime < csvDeltaTime:
                deltaTime = time.time_ns() / 1000000 - previousTimestamp

            screen.fill("black")
            pygame.draw.rect(screen, "green", (0, 720-scale, scale, scale))
            screen.blit(tennis_ball, (x*scale, 720 - y*scale))
            pygame.display.flip()

            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False

pygame.quit()