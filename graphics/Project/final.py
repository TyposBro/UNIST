from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import numpy as np

width = 1600
length = 900
moving = [0,0,0]
rotation = [0,0,0]
walking = 0

class Player:
    def __init__(self):
        self.mat = np.eye(4)
        pass

class Head(Player):
    def __init__(self):
        self.k = 0
        self.x = 0
        self.y = 0
        self.z = -2
        super().__init__()
    def draw(self):
        glPushMatrix()
        vertex =[[-1,1,-1],[1,1,-1],[1,1,1],[-1,1,1],[-1,-1,-1],[1,-1,-1],[1,-1,1],[-1,-1,1]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(rotation[0]*30, 0.0, 0.0, 1.0)
        glRotatef(-rotation[1]*30, 1.0, 0.0, 0.0)
        glColor3f(0.5, 0.5, 0.5)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Body(Player):
    def __init__(self):
        self.k = 0
        self.x = 0
        self.y = 0
        self.z = -4
        super().__init__()
    def draw(self):
        glPushMatrix()
        w = 4
        d = 2
        h = 6
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(self.k, 1.0, 0.0, 0.0)
        glRotatef(self.k, 0.0, 1.0, 0.0)
        glColor3f(1, 0, 0)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Leftarm(Player):
    def __init__(self):
        self.k = 0
        self.x = 1.25
        self.y = 0
        self.z = -3
        self.switch = True
        super().__init__()
    def draw(self):
        glPushMatrix()
        w = 0.5
        d = 2
        h = 5
        if self.k < -60:
            self.switch = False
        if self.k > 60:
            self.switch = True

        if self.switch == True:
            self.k = self.k - 10
        elif self.switch == False:
            self.k = self.k + 10

        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(self.k, 1.0, 0.0, 0.0)
        glColor3f(0, 1, 0)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Rightarm(Player):
    def __init__(self):
        self.k = 0
        self.x = -1
        self.y = 0
        self.z = -3
        self.switch = True
        super().__init__()
    def draw(self):
        glPushMatrix()
        w = 0.5
        d = 2
        h = 5
        if self.k < -60:
            self.switch = True
        if self.k > 60:
            self.switch = False

        if self.switch == True:
            self.k = self.k + 10
        elif self.switch == False:
            self.k = self.k - 10
        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(self.k, 1.0, 0.0, 0.0)
        glColor3f(0, 1, 0)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Leftleg(Player):
    def __init__(self):
        self.k = 0
        self.x = 0.5
        self.y = 0
        self.z = -6
        self.switch = True
        super().__init__()
    def draw(self):
        glPushMatrix()
        w = 1
        d = 2
        h = 3
        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        if self.k < -60:
            self.switch = True
        if self.k > 60:
            self.switch = False

        if self.switch == True:
            self.k = self.k + 10
        elif self.switch == False:
            self.k = self.k - 10
        #Top Bottom Front Back Left Right
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(self.k, 1.0, 0.0, 0.0)
        glColor3f(0, 0, 1)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Rightleg(Player):
    def __init__(self):
        self.k = 0
        self.x = -0.2
        self.y = 0
        self.z = -6
        self.switch = True
        super().__init__()
    def draw(self):
        glPushMatrix()
        w = 1
        d = 2
        h = 3
        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]

        if self.k < -60:
            self.switch = False
        if self.k > 60:
            self.switch = True

        if self.switch == True:
            self.k = self.k - 10
        elif self.switch == False:
            self.k = self.k + 10
        #Top Bottom Front Back Left Right
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        
        glRotatef(self.k, 1.0, 0.0, 0.0)
        glColor3f(0, 0, 1)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()

class Viewer:
    def __init__(self):
        self.player = Head()
        self.body = Body()
        self.leftarm = Leftarm()
        self.rightarm = Rightarm()
        self.leftleg = Leftleg()
        self.rightleg = Rightleg()
        self.perspective = 0


    def light(self):
        glEnable(GL_COLOR_MATERIAL)
        glEnable(GL_LIGHTING)
        glEnable(GL_DEPTH_TEST)

        # feel free to adjust light colors
        lightAmbient = [0.5, 0.5, 0.5, 1.0]
        lightDiffuse = [0.5, 0.5, 0.5, 1.0]
        lightSpecular = [0.5, 0.5, 0.5, 1.0]
        lightPosition = [1, 1, -1, 0]    # vector: point at infinity
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse)
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular)
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition)
        glEnable(GL_LIGHT0)

    def display(self):
        glViewport(0,0,width,length)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glClearColor(0, 0, 0, 1)
        glMatrixMode(GL_PROJECTION)
        glLoadIdentity()
        # projection matrix
        # use glOrtho and glFrustum (or gluPerspective) here
        glFrustum(-1,1,-1,1,1,100.0)
        glMatrixMode(GL_MODELVIEW)
        glLoadIdentity()
      #  glLoadMatrixf(self.cammat)
        # do some transformations using camera view
        #glLoadMatrixf(worldtocamera())
        if self.perspective == 0:
            gluLookAt(0+moving[0],0+moving[1],0+moving[2],0+moving[0]+rotation[0],-1+moving[1]+rotation[1],0+moving[2]+rotation[1],0,0,1)
        elif self.perspective == 1:
            gluLookAt(0+moving[0],7.5+moving[1],1+moving[2], 0+moving[0],-2+moving[1], 0+moving[2], 0,-1,0)
        self.player.draw()
        self.body.draw()
        self.leftarm.draw()
        self.rightarm.draw()
        self.leftleg.draw()
        self.rightleg.draw()
        glTranslatef(1, -10, -5)
        glutSolidTeapot(0.7)
        glutSwapBuffers()

    def keyboard(self, key, x, y):
        print(f"keyboard event: key={key}, x={x}, y={y}")
        if glutGetModifiers() & GLUT_ACTIVE_SHIFT:
            print("shift pressed")
        if glutGetModifiers() & GLUT_ACTIVE_ALT:
            print("alt pressed")
        if glutGetModifiers() & GLUT_ACTIVE_CTRL:
            print("ctrl pressed")
        if key ==b'w':
            moving[1] = moving[1] - 1*np.abs(rotation[1])
            moving[0] = moving[0] + 1*rotation[0]
        if key ==b's':
            moving[1] = moving[1] + 1*np.abs(rotation[1])
            moving[0] = moving[0] - 1*rotation[0]
        if key ==b'0':
            self.perspective = 0
        if key ==b'1':
            self.perspective = 1
        glutPostRedisplay()

    def special(self, key, x, y):
        print(f"special key event: key={key}, x={x}, y={y}")

        glutPostRedisplay()
    def mousepassive(self, x, y):
        print("x :", x ,"y :", y)
        rotation[0] = -((x/width) - 0.5)
        rotation[1] = -((y/length) - 0.5)
        
        print(rotation[0],"and ", rotation[1])
        glutPostRedisplay()
    def mouse(self, button, state, x, y):
        # button macros: GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, GLUT_RIGHT_BUTTON
        print(f"mouse press event: button={button}, state={state}, x={x}, y={y}")

        glutPostRedisplay()

    def motion(self, x, y):
        print(f"mouse move event: x={x}, y={y}")

        glutPostRedisplay()

    def reshape(self, w, h):
        # implement here
        print(f"window size: {w} x {h}")

        glutPostRedisplay()

    def run(self):
        glutInit()
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
        glutInitWindowSize(width, length)
        glutInitWindowPosition(0, 0)
        glutCreateWindow(b"CS471 Computer Graphics #2")

        glutDisplayFunc(self.display)
        glutKeyboardFunc(self.keyboard)
        glutSpecialFunc(self.special)
        glutMouseFunc(self.mouse)
        glutPassiveMotionFunc(self.mousepassive) #add
        glutMotionFunc(self.motion)
        glutReshapeFunc(self.reshape)

        self.light()

        glutMainLoop()


if __name__ == "__main__":
    viewer = Viewer()
    viewer.run()