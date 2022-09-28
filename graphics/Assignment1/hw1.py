from OpenGL.GL import *
from OpenGL.GLUT import *
import numpy as np


class Polygon:
    def __init__(self):
        self.mat = np.eye(4)

    def draw(self):
        raise NotImplementedError


# TODO: define your polygons here
class Triangle(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        glBegin(GL_TRIANGLES)

        # * VERTEX 1
        glColor3f(0, 0.1, 0)
        glVertex2f(200, 300)

        # * VERTEX 2
        glColor3f(-0.1, -0.1, 0)
        glVertex2f(400, 300)

        # * VERTEX 3
        glColor3f(0.1, -0.1, 0)
        glVertex2f(300, 400)
        glEnd()


class Rectangle(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        glBegin(GL_QUADS)

        # * VERTEX 1
        glColor3f(-0.1, 0.1, 0)
        glVertex2f(100, 100)

        # * VERTEX 2
        glColor3f(-0.1, 0.1, 0)
        glVertex2f(200, 100)

        # * VERTEX 3
        glColor3f(-0.1, 0.1, 0)
        glVertex2f(200, 200)

        # * VERTEX 4
        glColor3f(-0.1, 0.1, 0)
        glVertex2f(100, 200)
        glEnd()


class Ellipse(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        pass


class Viewer:
    def __init__(self):
        pass

    def display(self):
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glClearColor(0, 0, 0, 1)

        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
        self.iterate()
        glColor3f(1.0, 0.0, 3.0)

        # TODO: visualize your polygons here
        t = Triangle()
        t.draw()

        # r = Rectangle()
        # r.draw()

        # e = Ellipse()
        # e.draw()

        glutSwapBuffers()

    def iterate(foo):
        glViewport(0, 0, 800, 600)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        glOrtho(0.0, 800, 0.0, 600, 0.0, 1.0)
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()

    def keyboard(self, key, x, y):
        print(f"keyboard event: key={key}, x={x}, y={y}")
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
