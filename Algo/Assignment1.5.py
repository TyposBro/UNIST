# Assignment 1 Problem 5
def foo(start, end):
    l = []
    d = end - start
    step = 1
    ans = 0
    suM = 0
    if d==0:
        return 0
    if d<0:
        return -1
    for i in range(d):
        l.append(step)
        suM+=step
        if suM <d-suM:
            step+=1
        elif suM ==suM-d:
            pass
        elif suM >suM-d:
            if step!=1:
                step-=1
        ans+=1
        
        if suM==d:
            print(l)
            return ans


print(foo(10, 20))
        
    

