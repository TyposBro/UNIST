from math import inf


def fun_fast(A):
    min_num = A[0]
    max_num = A[0]
    for i in A:
        if min_num > i:
            min_num = i
        if max_num < i:
            max_num = i
    min_sum = inf

    for k in range(min_num, max_num + 1):
        temp_sum = abs_sum(A, k)
        if temp_sum < min_sum:
            min_sum = temp_sum
        else:
            break

    print(min_sum)


def abs_sum(A, k):
    sum = 0
    for i in A:
        sum += abs(i-k)

    return sum
