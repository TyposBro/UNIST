from OpenGL.GL import *
from OpenGL.GLUT import *


def display():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glClearColor(0, 0, 0, 1)

    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()

    glBegin(GL_TRIANGLES)
    glColor4f(1, 0, 0, 1)
    glVertex2f(0, 1)
    glColor4f(0, 1, 0, 1)
    glVertex2f(-1, -1)
    glColor4f(0, 0, 1, 1)
    glVertex2f(1, -1)
    glEnd()

    glutSwapBuffers()


if __name__ == "__main__":
    glutInit()
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
    glutInitWindowSize(800, 600)
    glutInitWindowPosition(0, 0)
    glutCreateWindow(b"CS471 Computer Graphics")

    glutDisplayFunc(display)

    glutMainLoop()
