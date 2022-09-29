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
        VERTEX_SHADER = '''
        #version 330
 
        in vec3 position;
        in vec3 color;
        out vec3 newColor;
        
        void main() {
         
         gl_Position = vec4(position, 1.0);
         newColor = color;
     
          }
        '''

        FRAGNMENT_SHADER = '''
        #version 330
        
        in vec3 newColor;
        out vec4 outColor;
 
        void main() {
 
          outColor = vec4(newColor, 1.0f);
 
        }
        '''

        triangle = [0, 0.1, 0, 0.2, 0.6, 0.8,
                    -0.1, -0.1, 0, 0.2, 0.6, 0.8,
                    0.1, -0.1, 0,  0.2, 0.6, 0.8, ]

        # convert to 32bit float

        triangle = np.array(triangle, dtype=np.float32)
        global shaderProgram

        vertexshader = shaders.compileShader(VERTEX_SHADER, GL_VERTEX_SHADER)
        fragmentshader = shaders.compileShader(
            FRAGNMENT_SHADER, GL_FRAGMENT_SHADER)

        shaderProgram = shaders.compileProgram(vertexshader, fragmentshader)

        VBO = glGenBuffers(1)
        glBindBuffer(GL_ARRAY_BUFFER, VBO)
        glBufferData(GL_ARRAY_BUFFER, triangle.nbytes,
                     triangle, GL_STATIC_DRAW)

        position = glGetAttribLocation(shaderProgram, "position")
        glVertexAttribPointer(position, 3, GL_FLOAT,
                              GL_FALSE, 24, ctypes.c_void_p(0))
        glEnableVertexAttribArray(position)
        # get the color from  shader
        color = glGetAttribLocation(shaderProgram, 'color')
        glVertexAttribPointer(color, 3, GL_FLOAT, GL_FALSE,
                              24, ctypes.c_void_p(12))
        glEnableVertexAttribArray(color)

        glUseProgram(shaderProgram)


class Rectangle(Polygon):
    def __init__(self):
        super().__init__()

    def draw(self):
        # Positions           #Colors
        rectangle = [-0.1, 0.1, 0,   0.2, 0.6, 0.8,
                     0.1, 0.1, 0,     0.2, 0.6, 0.8,
                     0.1, -0.1, 0,      0.2, 0.6, 0.8,
                     -0.1, -0.1, 0,     0.2, 0.6, 0.8, ]
        # convert to 32bit float

        rectangle = np.array(rectangle, dtype=np.float32)

        # Creating Indices

        indices = [0, 1, 2,
                   2, 3, 0]

        indices = np.array(indices, dtype=np.uint32)
        VERTEX_SHADER = """

            #version 330

            in vec3 position;
            in vec3 color;
            out vec3 newColor;

            void main() {

            gl_Position = vec4(position, 1.0);
            newColor = color;

            }
        """

        FRAGMENT_SHADER = """
            #version 330

            in vec3 newColor;
            out vec4 outColor;

            void main() {

            outColor = vec4(newColor, 1.0f);

            }
        """

        shader = shaders.compileProgram(shaders.compileShader(VERTEX_SHADER, GL_VERTEX_SHADER),
                                        shaders.compileShader(FRAGMENT_SHADER, GL_FRAGMENT_SHADER))

        # Create Buffer object in gpu
        VBO = glGenBuffers(1)

        # Create EBO
        EBO = glGenBuffers(1)
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO)
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices, GL_STATIC_DRAW)

        # Bind the buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO)
        glBufferData(GL_ARRAY_BUFFER, 96, rectangle, GL_STATIC_DRAW)

        # get the position from  shader
        position = glGetAttribLocation(shader, 'position')
        glVertexAttribPointer(position, 3, GL_FLOAT,
                              GL_FALSE, 24, ctypes.c_void_p(0))
        glEnableVertexAttribArray(position)

        # get the color from  shader
        color = glGetAttribLocation(shader, 'color')
        glVertexAttribPointer(color, 3, GL_FLOAT, GL_FALSE,
                              24, ctypes.c_void_p(12))
        glEnableVertexAttribArray(color)

        glUseProgram(shader)

        glClearColor(0.0, 0.0, 0.0, 1.0)


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
            glVertex2f(
                1.4 * (x + (100 * cos(i * 2*pi / triangleAmount))),
                1.111 * (y + (100 * sin(i * 2*pi / triangleAmount)))
            )
        glutSwapBuffers()


class Viewer:
    key = None
    x = None
    y = None

    def __init__(self):
        pass

    def display(self):
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glClearColor(0, 0, 0, 1)
        glMatrixMode(GL_MODELVIEW)

        # TODO: visualize your polygons here

        if self.key == b"1":
            # * TRIANGLE
            t = Triangle()
            t.draw()
            glDrawArrays(GL_TRIANGLES, 0, 3)

        elif self.key == b"2":
            r = Rectangle()
            r.draw()
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,  None)

        elif self.key == b"3":
            e = Ellipse()
            e.draw()

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
