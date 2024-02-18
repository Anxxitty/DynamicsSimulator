import pygame
import pygame_widgets
from pygame_widgets.slider import Slider
import time
from reader import Reader

# Program initialization
scale = 80           # 10px/m
object_size = 0.06   # 10cm * 10cm
WIDTH = 1280
HEIGHT = 720
ORIGIN = (int(WIDTH/2-scale/2), int(HEIGHT))


pygame.init()
pygame.display.set_caption("Dynamics Simulator Visualizer")
screen = pygame.display.set_mode((WIDTH, HEIGHT))
running = True
initialTimestamp = time.time_ns() / 1000000


scale_slider = Slider(screen, 10, 10, 100, 10, min=5, max=1000, step=5)
scale_slider.setValue(scale)

object_size_slider = Slider(screen, 10, 30, 100, 10, min=0.05, max=10, step=0.05)
object_size_slider.setValue(object_size)

origin_x_slider = Slider(screen, 10, 50, 100, 10, min=0, max=WIDTH, step=10)
origin_x_slider.setValue(ORIGIN[0])
origin_y_slider = Slider(screen, 10, 70, 100, 10, min=0, max=HEIGHT, step=10)
origin_y_slider.setValue(HEIGHT - ORIGIN[1])

initial_object_image = pygame.image.load("object.png")
moving_object = pygame.transform.scale(initial_object_image, (int(object_size*scale), int(object_size*scale)))

while running:
    with Reader.openWithName("output.csv") as file:
        previousTimestamp = time.time_ns() / 1000000
        deltaTime = 0
        scale = scale_slider.getValue()
        object_size = object_size_slider.getValue()
        ORIGIN = (int(origin_x_slider.getValue()), int(HEIGHT - origin_y_slider.getValue()))

        for line in file:
            events = pygame.event.get()
            for event in events:
                if event.type == pygame.QUIT:
                    running = False

            if not running:
                break

            csvDeltaTime = float(line[0])
            x = int(ORIGIN[0] + float(line[1]) * scale)
            y = int(ORIGIN[1] - float(line[2]) * scale)

            while deltaTime < csvDeltaTime:
                deltaTime = time.time_ns() / 1000000 - previousTimestamp

            screen.fill((135, 179, 250))
            pygame.draw.rect(screen, "green", (ORIGIN[0], ORIGIN[1] - scale, scale, scale))
            moving_object = pygame.transform.scale(initial_object_image, (int(object_size*scale), int(object_size*scale)))
            screen.blit(moving_object, (x, y))

            pygame_widgets.update(events)
            pygame.display.flip()

pygame.quit()
