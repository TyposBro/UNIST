CC=g++
CXXFLAGS += -Wall -std=c++11 -O3

all: rotate avl rb

rotate: Tree_rotate_test.cpp Tree.h AVLTree.h RBTree.h
	$(CC) -o rotate $^ $(CXXFLAGS)

avl: AVLtest.cpp Tree.h AVLTree.h RBTree.h
	$(CC) -o avl $^ $(CXXFLAGS)

rb: RBtest.cpp Tree.h AVLTree.h RBTree.h
	$(CC) -o rb $^ $(CXXFLAGS)

clean:
	$(RM) rotate avl rb *.o