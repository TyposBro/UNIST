from glob import glob
from turtle import position
from OpenGL.GL import *
from OpenGL.GL import shaders
from OpenGL.GLUT import *
from OpenGL.GLU import *
import numpy as np


class Polygon:
    def __init__(self):
        self.mat = np.eye(4)

    def draw(self):
        raise NotImplementedError


# TODO: define your polygons here

VERTEX_SHADER = '''
#version 330

in vec4 position;
void main(){
    gl_Position = position;
}
'''

FRAGNMENT_SHADER = '''
#version 330

void main(){
    gl_FragColor = vec4(0.2f, 0.6f, 0.8f, 1.0f);
}
'''
shaderProgram = None


def initialize():
    global VERTEX_SHADER
    global FRAGNMENT_SHADER
    global shaderProgram

    vertexshader = shaders.compileShader(VERTEX_SHADER, GL_VERTEX_SHADER)
    fragmentshader = shaders.compileShader(
        FRAGNMENT_SHADER, GL_FRAGMENT_SHADER)

    shaderProgram = shaders.compileProgram(vertexshader, fragmentshader)
    triangle = [0.0, 0.1, 0.0, -0.1, -0.1, 0.0, 0.1, -0.1, 0.0]
    triangle = np.array(triangle, dtype=np.float32)

    VBO = glGenBuffers(1)
    glBindBuffer(GL_ARRAY_BUFFER, VBO)
    glBufferData(GL_ARRAY_BUFFER, triangle.nbytes, triangle, GL_STATIC_DRAW)

    position = glGetAttribLocation(shaderProgram, "position")
    glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, 0, None)
    glEnableVertexAttribArray(position)


class Triangle(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        pass


class Rectangle(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        pass


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

        # TODO: visualize your polygons here
        # * TRIANGLE
        glUseProgram(shaderProgram)
        glDrawArrays(GL_TRIANGLES, 0, 3)
        glUseProgram(0)
        glutSwapBuffers()

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
        initialize()
        glutDisplayFunc(self.display)
        glutKeyboardFunc(self.keyboard)
        glutSpecialFunc(self.special)
        glutMouseFunc(self.mouse)
        glutMotionFunc(self.motion)

        glutMainLoop()


if __name__ == "__main__":
    viewer = Viewer()
    viewer.run()
