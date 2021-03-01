

path_not_sorted = "/home/joker/Desktop/answerdatabase/answer_datebase1.txt"

sorted_db = []


def sort_db(path):
    global not_ok_list
    not_sort = open(path, 'r', encoding='utf-8')     # get not sorted database
    g = not_sort.readlines()         # read the lines of file
    for i in range(len(g)):
        g[i] = g[i].rstrip('\n')
    not_sort.close()
    return g
    sorted_db = g
sort_db()








