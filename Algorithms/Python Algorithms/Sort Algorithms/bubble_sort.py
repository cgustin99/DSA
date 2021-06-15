#Bubble sort is a sorting algorithm that compares
#two adjacent elements and swaps them if they are
#not in the intended order.

def check_sort(array):
    true_sort = 0
    for i in range(0, len(array) - 1):
        if array[i] < array[i + 1]:
            true_sort += 1
    if true_sort == len(array) - 1:
        return True
    else:
        return False

def bubble_sort(array):
    current_element = 0
    while not check_sort(array):
        for i in range(0, len(array) - 1):
            if array[i] > array[i + 1]:
                current_element = array[i]
                array[i] = array[i + 1]
                array[i + 1] = current_element

    return array


my_list = [-2, 0, 11, -9, 45, 102, -12]
print(bubble_sort(my_list))
