from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *
import numpy as np
import cv2
import random

width = 1600
length = 900
moving = [0,0,0]
rotation = [0,0,0]

class floor:
    def __init__(self):
        self.k = 0
        self.x = 0
        self.y = -30
        self.z = -12.5
        self.image = cv2.imread("grass.jpg",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
    def draw(self):
        glPushMatrix()
        w = 10
        d = 10000
        h = 4.25
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, self.image)

        glEnable(GL_TEXTURE_2D)

        #Top Bottom Front Back Left Right
        glTranslatef(self.x, self.y, self.z)
        glScalef(1,1,1)
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
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class obstacle2:
    def __init__(self,x=0,y=0,z=-20):
        self.k = 0
        self.x = x
        self.y = y
        self.z = z
        self.image = cv2.imread("images.jpg",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
    def moving(self, speed):
        self.y = self.y - speed
    def draw(self):
        glPushMatrix()
        w = 1
        d = 1
        h = 25
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        glTranslatef(self.x, self.y, self.z)
        glScalef(1,1,1)
        glColor3f(0.5, 0, 0)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(0.0, 1.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(1.0,0.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        #self.y = self.y - 0.5
        glEnd()
        glPopMatrix()
    def collision(self):
        if np.abs(self.x-moving[0])<((1/2)+(4/4)) and np.abs(self.y-moving[1])<((1/2)+(2/4)): #Body
            print("Body")
            print(self.x, self.y,self.z)
            print(moving[0], moving[1],moving[2])
            return True
        return False
class obstacle:
    def __init__(self,x=0,y=0,z=-20):
        self.k = 0
        self.x = x
        self.y = y
        self.z = z
        self.image = cv2.imread("images.jpg",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
    def moving(self, speed):
        self.y = self.y - speed
    def draw(self):
        glPushMatrix()

        w = 10
        d = 1
        h = 2.25
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        #Top Bottom Front Back Left Right
        glTranslatef(self.x, self.y, self.z)
        glScalef(1,1,1)
        glColor3f(0.5, 0, 0)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        #self.y = self.y - 0.5
        glEnd()
        glPopMatrix()
    def collision(self):
        if np.abs(self.y-moving[1]-0.25)<(0.25) and np.abs(self.z-moving[2]+4)<((2.25/2)): #leg
            print("Leg")
            print(self.x, self.y,self.z)
            print(moving[0], moving[1],moving[2])
            return True
        if np.abs(self.y-moving[1])<((1/2)+(1/2)) and np.abs(self.z-moving[2]+2)<((2.25/2)): #head
            print("Head")
            print(self.x, self.y,self.z)
            print(moving[0], moving[1],moving[2])
            return True

        return False
class movingobstacle2:
    def __init__(self,x=0,y=0,z=-20):
        self.k = 0
        self.x = x
        self.y = y
        self.z = z
        self.image = cv2.imread("images.jpg",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
        self.swtich = True
    def moving(self, speed):
        self.y = self.y - speed
        if self.x <-3.7:
            self.swtich = False
        if self.x > 3.7:
            self.swtich = True
        if self.swtich == True:
            self.x = self.x - speed/10
        else:
            self.x = self.x + speed/10

    def draw(self):
        glPushMatrix()
        w = 1
        d = 1
        h = 25
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        #Top Bottom Front Back Left Right
        glTranslatef(self.x, self.y, self.z)
        glScalef(1,1,1)
        glColor3f(0.5, 0, 0)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        #self.y = self.y - 0.5
        glEnd()
        glPopMatrix()
    def collision(self):
        if np.abs(self.x-moving[0])<((1/2)+(4/4)) and np.abs(self.y-moving[1])<((1/2)+(2/4)): #Body
            print("Body")
            print(self.x, self.y,self.z)
            print(moving[0], moving[1],moving[2])
            return True
        return False
class movingobstacle:
    def __init__(self,x=0,y=0,z=-20):
        self.k = 0
        self.x = x
        self.y = y
        self.z = z
        self.image = cv2.imread("images.jpg",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
        self.swtich = True
    def moving(self, speed):
        self.y = self.y - speed
        if self.z <-7.5:
            self.swtich = False
        if self.z > 12.5:
            self.swtich = True
        if self.swtich == True:
            self.z = self.z - speed/10
        else :
            self.z = self.z + speed/10
    def draw(self):
        glPushMatrix()

        w = 10
        d = 1
        h = 2.25
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGB, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        glTranslatef(self.x, self.y, self.z)
        glScalef(1,1,1)
        glColor3f(0.5, 0, 0)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        #self.y = self.y - 0.5
        glEnd()
        glPopMatrix()
    def collision(self):
        if np.abs(self.y-moving[1]-0.25)<(0.25) and np.abs(self.z-moving[2]+4)<((2.25/2)): #leg
            print("Leg")
            print(self.x, self.y,self.z)
            print(moving[0], moving[1],moving[2])
            return True
        if np.abs(self.y-moving[1])<((1/2)+(1/2)) and np.abs(self.z-moving[2]+2)<((2.25/2)): #head
            print("Head")
            print(self.x, self.y,self.z)
            print(moving[0], moving[1],moving[2])
            return True

        return False

class Wall:
    def __init__(self, x = 0):
        self.k = 0
        self.x = x
        self.y = 110
        self.z = 2
        self.temp = []
        self.image = cv2.imread("pngwing.png",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]

    def draw(self):
        glPushMatrix()
        w = 20
        d = 20000
        h = 50
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        glTranslatef(self.x, self.y, self.z)
        glScalef(0.5,0.5,0.5)
        glColor3f(1, 1, 1)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            for j in range(4):
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glNormal3f(v3[0],v3[1],v3[2])
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()

class Head:
    def __init__(self):
        self.k = 0
        self.x = 0
        self.y = 0
        self.z = -2
        self.image = cv2.imread("head.png",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
    def draw(self):
        glPushMatrix()
        vertex =[[-1,1,-1],[1,1,-1],[1,1,1],[-1,1,1],[-1,-1,-1],[1,-1,-1],[1,-1,1],[-1,-1,1]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        #Top Bottom Front Back Left Right
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(rotation[0]*30, 0.0, 0.0, 1.0)
        glRotatef(-rotation[1]*30, 1.0, 0.0, 0.0)
        glColor3f(1, 1, 1)
        glBegin( GL_QUADS )
        for i in range(6):
            v1 = np.array([vertex[order[i][0]][0] - vertex[order[i][1]][0], vertex[order[i][0]][1] - vertex[order[i][1]][1] , vertex[order[i][0]][2] - vertex[order[i][1]][2]])
            v2 = np.array([vertex[order[i][0]][0] - vertex[order[i][3]][0], vertex[order[i][0]][1] - vertex[order[i][3]][1] , vertex[order[i][0]][2] - vertex[order[i][3]][2]])
            v3 = np.cross(v1,v2)
            if i == 1 or i ==3 or i == 5:
                v3 = v3*-1
            for j in range(4):
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
            glNormal3f(v3[0],v3[1],v3[2])
            for j in range(4):
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Body:
    def __init__(self):
        self.k = 0
        self.x = 0
        self.y = 0
        self.z = -4
        self.image = cv2.imread("Body.png",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
    def draw(self):
        glPushMatrix()
        w = 4
        d = 2
        h = 6
        vertex =[[-w/2,d/2,-h/2],[w/2,d/2,-h/2],[w/2,d/2,h/2],[-w/2,d/2,h/2],[-w/2,-d/2,-h/2],[w/2,-d/2,-h/2],[w/2,-d/2,h/2],[-w/2,-d/2,h/2]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
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
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Leftarm:
    def __init__(self):
        self.x = 1.25
        self.y = 0.25
        self.z = -3
        self.switch = True
        self.image = cv2.imread("arm.png",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
    def draw(self,k):
        glPushMatrix()
        w = 0.5
        d = 1
        h = 5

        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(k, 1.0, 0.0, 0.0)
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
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Rightarm:
    def __init__(self):
        self.k = 0
        self.x = -1
        self.y = 0.25
        self.z = -3
        self.image = cv2.imread("arm.png",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
    def draw(self, k):
        glPushMatrix()
        w = 0.5
        d = 1
        h = 5
        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]
        #Top Bottom Front Back Left Right
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(k, 1.0, 0.0, 0.0)
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
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Leftleg:
    def __init__(self):
        self.k = 0
        self.x = 0.5
        self.y = 0.25
        self.z = -4
        self.image = cv2.imread("leg.png",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
        self.switch = True
    def draw(self, k):
        glPushMatrix()
        w = 1
        d = 1
        h = 8
        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]

        #Top Bottom Front Back Left Right
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)
        glRotatef(k, 1.0, 0.0, 0.0)
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
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()
class Rightleg:
    def __init__(self):
        self.k = 0
        self.x = -0.2
        self.y = 0.25
        self.z = -4
        self.image = cv2.imread("leg.png",cv2.IMREAD_UNCHANGED)
        self.image_width = self.image.shape[0]
        self.image_height = self.image.shape[1]
        self.switch = True
    def draw(self, k):
        glPushMatrix()
        w = 1
        d = 1
        h = 8
        vertex =[[-w,0,-h],[0,0,-h],[0,0,0],[-w,0,0],[-w,-d,-h],[0,-d,-h],[0,-d,0],[-w,-d,0]]
        order =[[0,1,2,3],[4,5,6,7],[3,2,6,7],[0,1,5,4],[0,3,7,4],[1,2,6,5]]

        #Top Bottom Front Back Left Right
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, self.image_width, self.image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, self.image)
        glEnable(GL_TEXTURE_2D)
        glTranslatef(self.x+moving[0], self.y+moving[1], self.z+moving[2])
        glScalef(0.5,0.5,0.5)

        glRotatef(k, 1.0, 0.0, 0.0)
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
                if j ==0:
                    glTexCoord2f(0.0, 0.0)
                elif j == 1:
                    glTexCoord2f(1.0, 0.0)
                elif j == 2:
                    glTexCoord2f(1.0, 1.0)
                elif j == 3:
                    glTexCoord2f(0.0,1.0)
                glVertex4f(vertex[order[i][j]][0],vertex[order[i][j]][1],vertex[order[i][j]][2],1)
        glEnd()
        glPopMatrix()

class Viewer:
    #bottom -7.5
    #top :7.5
    #left = 3
    #center = 0
    #right = -3
    def __init__(self):
        self.player = Head()
        self.body = Body()
        self.leftarm = Leftarm()
        self.rightarm = Rightarm()
        self.leftleg = Leftleg()
        self.rightleg = Rightleg()
        self.perspective = 1
        self.rightwall = Wall(-10)
        self.leftwall = Wall(10)
        self.obstacle = obstacle()
        self.floor = floor()
        self.obstacles = []
        self.jumping = False
        self.timer = 0
        self.t = 0
        self.k = 0
        self.switch = True

    def light(self):
        glEnable(GL_COLOR_MATERIAL)
        glEnable(GL_LIGHTING)
        glEnable(GL_DEPTH_TEST)

        # feel free to adjust light colors
        lightAmbient = [0.5, 0.5, 0.5, 1.0]
        lightDiffuse = [0.5, 0.5, 0.5, 1.0]
        lightSpecular = [1.0, 1.0, 1.0, 1.0]
        lightPosition = [10, 10, -10, 0]    # vector: point at infinity
        glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse)
        glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular)
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition)
        glEnable(GL_LIGHT0)

    def display(self):
        glViewport(0,0,width,length)
        glGenTextures(2)
        #self.light()
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
            gluLookAt(0+moving[0],27+moving[1],3+moving[2], 0+moving[0],-2+moving[1], 0+moving[2], 0,-1,0)
        elif self.perspective == 2:
            gluLookAt(-10+moving[0],0+moving[1],0+moving[2],1+moving[0],0+moving[1],0+moving[2],0,0,1)
        self.player.draw()
        self.body.draw()
        self.leftarm.draw(self.k)
        self.rightarm.draw(-self.k)
        self.leftleg.draw(self.k)
        self.rightleg.draw(-self.k)
        if self.perspective !=2:
            self.rightwall.draw()
        self.leftwall.draw()
        self.obstacle.draw()
        self.floor.draw()
        for i in range(len(self.obstacles)):
            self.obstacles[i].draw()
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
            moving[1] = moving[1] - 1*np.abs(1-rotation[0])
            moving[0] = moving[0] + 1*rotation[0]
        if key ==b's':
            moving[1] = moving[1] + 1*np.abs(1-rotation[0])
            moving[0] = moving[0] - 1*rotation[0]
        if key ==b'd':
            moving[0] = moving[0] - 0.1
        if key ==b'a':
            moving[0] = moving[0] + 0.1
        if key == b' ' and self.jumping == False:
            moving[2] = 0.1
            self.jumping = True
            self.t = 0
        if key ==b'0':
            self.perspective = 0
        if key ==b'1':
            self.perspective = 1
        if key ==b'2':
            self.perspective = 2
        glutPostRedisplay()

    def special(self, key, x, y):
        print(f"special key event: key={key}, x={x}, y={y}")

        glutPostRedisplay()
    def mousepassive(self, x, y):
        rotation[0] = -((x/width) - 0.5)
        rotation[1] = -((y/length) - 0.5)

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
    def checkingobstacle2(self,x1,x2,speed):
        x1s = True
        x2s = True
        for i in range(20):
            if x1 < -3.7:
                z1s = False
            if x1 > 3.7:
                x1s = True
            if x2 < -3.7:
                x2s = False
            if x2 > 3.7:
                x2s = True
            if x1s == False:
                x1 = x1 + speed/10
            else :
                x1 = x1 - speed/10
            if x2s == False:
                x2 = x2 + speed/10
            else :
                x2 = x2 - speed/10
        if np.abs(x1-x2) > 2.5:
            return True
        elif np.abs(x1 + 3.7) > (1/2)+(4/4)and np.abs(x2 + 3.7) > (1/2)+(4/4):
            return True
        elif np.abs(x1-3.7) <(1/2)+(4/4) and np.abs(x2-3.7) < (1/2)+(4/4):
            return True
        else:
            return False

    def checkingobstacle(self,z1,z2,speed):
        z1s = True
        z2s = True
        for i in range(20):
            if z1 < -7.5:
                z1s = False
            if z1 > 12.5:
                z1s = True
            if z2 < -7.5:
                z2s = False
            if z2 > 12.5:
                z2s = True
            if z1s == False:
                z1 = z1 + speed/10
            else :
                z1 = z1 - speed/10
            if z2s == False:
                z2 = z2 + speed/10
            else :
                z2 = z2 - speed/10
        if np.abs(z1-z2) > 10:
            return True
        elif np.abs(z1 + 7.5) > (2.25/2)and np.abs(z2 + 7.5) > (2.25/2):
            return True
        elif np.abs(z1-12.5) <(2.25/2) and np.abs(z2-12.5) < (2.25/2):
            return True
        else:
            return False

    def animation(self, x):
        """
        self.temp = obstacle(y = moving[1] + 30, z= 12.5)
        self.tempw = obstacle(y = moving[1] + 30, z= 7.5)
        self.tempc = obstacle(y = moving[1] + 30, z= -7.5)
        self.tempt = obstacle2(x=3, y=moving[1] + 30, z= 0)
        self.tempa = obstacle2(x=0, y=moving[1] + 30, z= 0)
        self.tempb = obstacle2(x=-3, y=moving[1] + 30, z= 0)
        """# x : -3.7~3.7, y : -7.5~12.5
        #print(self.timer)
        if x ==1 and self.perspective == 0:
            if self.timer %300 == 1: # 0 rightbelow 1centerbelow 2leftbelow 3 4 5
                temp = random.randrange(0,7)
                if  temp == 0:
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= 12.5))
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= 7.5))
                    self.obstacles.append(obstacle2(x=3, y=moving[1] + 20, z= 0))
                    self.obstacles.append(obstacle2(x=0, y=moving[1] + 20, z= 0))
                elif temp == 1:
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= 12.5))
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= 7.5))
                    self.obstacles.append(obstacle2(x=3, y=moving[1] + 20, z= 0))
                    self.obstacles.append(obstacle2(x=-3, y=moving[1] + 20, z= 0))
                elif temp == 2:
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= 12.5))
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= 7.5))
                    self.obstacles.append(obstacle2(x=0, y=moving[1] + 20, z= 0))
                    self.obstacles.append(obstacle2(x=-3, y=moving[1] + 20, z= 0))
                elif temp == 3:
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= -2.5))
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= -7.5))
                    self.obstacles.append(obstacle2(x=3, y=moving[1] + 20, z= 0))
                    self.obstacles.append(obstacle2(x=0, y=moving[1] + 20, z= 0))
                elif temp == 4:
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= -2.5))
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= -7.5))
                    self.obstacles.append(obstacle2(x=3, y=moving[1] + 20, z= 0))
                    self.obstacles.append(obstacle2(x=-3, y=moving[1] + 20, z= 0))
                elif temp == 5:
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= -2.5))
                    self.obstacles.append(obstacle(y = moving[1] + 20, z= -7.5))
                    self.obstacles.append(obstacle2(x=0, y=moving[1] + 20, z= 0))
                    self.obstacles.append(obstacle2(x=-3, y=moving[1] + 20, z= 0))
                elif temp == 6:
                    z1 = random.uniform(-7.5,12.5)
                    z2 = random.uniform(-7.5,12.5)
                    while self.checkingobstacle(z1,z2,1.2):
                        z1 = random.uniform(-7.5,12.5)
                        z2 = random.uniform(-7.5,12.5)
                    x1 = random.uniform(-3.7,3.7)
                    x2 = random.uniform(-3.7,3.7)
                    while self.checkingobstacle2(x1,x2,1.2):
                        x1 = random.uniform(-3.7,3.7)
                        x2 = random.uniform(-3.7,3.7)
                    self.obstacles.append(movingobstacle2(x=random.uniform(-3.7,3.7), y=moving[1] + 20, z= 0))
                    self.obstacles.append(movingobstacle2(x=random.uniform(-3.7,3.7), y=moving[1] + 20, z= 0))
                    self.obstacles.append(movingobstacle(y=moving[1] + 20, z= random.uniform(-7.5,12.5)))
                    self.obstacles.append(movingobstacle(y=moving[1] + 20, z= random.uniform(-7.5,12.5)))

            for i in range(len(self.obstacles)):
                self.obstacles[i].moving(1.2)
            i = 0
            while i < len(self.obstacles):
                if self.obstacles[i].y < moving[1] - 110:
                    del self.obstacles[i]
                else:
                    i = i + 1
            if moving[2] > 0:
                moving[2] = moving[2] - 9.8*self.t*self.t/10 + 8*self.t/5
            if moving[2] <= 0:
                self.jumping = False
                moving[2] = 0
            self.t = self.t + 0.05
            if self.perspective == 0:
                if self.switch == True:
                    self.k = self.k + 3
                else :
                    self.k = self.k - 3
            if self.k > 30:
                self.switch = False
            if self.k < -30:
                self.switch = True
            moving[1] = moving[1] - 1
            moving[0] = moving[0] + 1*rotation[0]
            if moving[0]<-3.7:
                moving[0] = -3.7
            if moving[0]>3.7:
                moving[0] = 3.7
            glutPostRedisplay()
            result = False
            for i in range(len(self.obstacles)):
                result = self.obstacles[i].collision()
                if result == True:
                    break
            self.timer = self.timer + 1
            if result == True:
                glutTimerFunc(1, self.animation, 0)
            else:
                glutTimerFunc(1, self.animation, 1)
        elif x == 0:
            self.perspective = 1
        elif self.perspective == 0:
            glutTimerFunc(1, self.animation, 1)
        else:
            glutTimerFunc(1, self.animation, 1)



    def run(self):
        glutInit()
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
        glutInitWindowSize(width, length)
        glutInitWindowPosition(0, 0)
        glutCreateWindow(b"CS471 Computer Graphics #2")
        glutDisplayFunc(self.display)
        glutTimerFunc(100, self.animation, 1) #add
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
