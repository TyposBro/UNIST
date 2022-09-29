from glob import glob
from turtle import position
from OpenGL.GL import *
from OpenGL.GL import shaders
from OpenGL.GLUT import *
from OpenGL.GLU import *
import numpy as np
from math import cos, sin, pi


class Polygon:
    def __init__(self):
        self.mat = np.eye(4)

    def draw(self):
        raise NotImplementedError


# TODO: define your polygons here


shaderProgram = None


class Triangle(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        glBegin(GL_TRIANGLES)
        glColor3f(0.2, 0.6, 0.8)
        glVertex2f(0, 0.1)
        glVertex2f(-0.1, -0.1)
        glVertex2f(0.1, -0.1)
        glEnd()


class Rectangle(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        glBegin(GL_QUADS)
        glColor3f(0.2, 0.6, 0.8)
        glVertex2f(-0.1, 0.1)
        glVertex2f(0.1, 0.1)
        glVertex2f(0.1, -0.1)
        glVertex2f(-0.1, -0.1)
        glEnd()


class Ellipse(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        i = None
        triangleAmount = 20
        glColor3f(0.2, 0.6, 0.8)
        x1 = 320
        y1 = 240
        r1 = 75
        x = 100
        y = 100
        glBegin(GL_TRIANGLE_FAN)
        glVertex2f(100, 100)  # center of circle
        for i in range(0, triangleAmount+1):
            print(i)
            glVertex2f(
                1.4 * (x + (100 * cos(i * 2*pi / triangleAmount))),
                1.111 * (y + (100 * sin(i * 2*pi / triangleAmount)))
            )
        glEnd()


class Viewer:
    key = None
    x = None
    y = None

    def __init__(self):
        pass

    def display(self):
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glClearColor(0, 0, 0, 1)
        # glClearColor(1.0, 1.0, 1.0, 0.0)
        glMatrixMode(GL_MODELVIEW)

        # TODO: visualize your polygons here

        if self.key == b"1":
            # * TRIANGLE
            t = Triangle()
            t.draw()

        elif self.key == b"2":
            r = Rectangle()
            r.draw()

        elif self.key == b"3":
            e = Ellipse()
            e.draw()

            glFlush()

        glutSwapBuffers()

    def keyboard(self, key, x, y):
        print(f"keyboard event: key={key}, x={x}, y={y}")
        self.x = x
        self.y = y
        self.key = key

        if glutGetModifiers() & GLUT_ACTIVE_SHIFT:
            print("shift pressed")
        if glutGetModifiers() & GLUT_ACTIVE_ALT:
            print("alt pressed")
        if glutGetModifiers() & GLUT_ACTIVE_CTRL:
            print("ctrl pressed")

        glutPostRedisplay()

    def special(self, key, x, y):
        print(f"special key event: key={key}, x={x}, y={y}")

        glutPostRedisplay()

    def mouse(self, button, state, x, y):
        # button macros: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
        print(
            f"mouse press event: button={button}, state={state}, x={x}, y={y}")

        glutPostRedisplay()

    def motion(self, x, y):
        print(f"mouse move event: x={x}, y={y}")

        glutPostRedisplay()

    def run(self):
        glutInit()
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
        glutInitWindowSize(800, 600)
        glutInitWindowPosition(0, 0)
        glutCreateWindow("CS471 Computer Graphics #1")

        glutDisplayFunc(self.display)

        glutKeyboardFunc(self.keyboard)
        glutSpecialFunc(self.special)
        glutMouseFunc(self.mouse)
        glutMotionFunc(self.motion)

        glutMainLoop()


if __name__ == "__main__":
    viewer = Viewer()
    viewer.run()
