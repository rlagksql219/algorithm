
def solution(numbers):
    numbers.sort()

    num_1 = numbers[0]*numbers[1]
    num_2 = numbers[-2]*numbers[-1]
    num_3 = numbers[0]*numbers[-1]

    return max(num_1,num_2,num_3)