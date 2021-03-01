

not_sorted_db = []

path_not_sorted = not_sorted_db.read(r'C:\Users\ht6\Documents\ozornin\sort\get_database.txt')

sorted_db = []

def sort_db(path):
    global not_ok_list
    not_sort = open(path, 'r', encoding='utf-8')     # get not sorted database
    g = not_sort.readlines()         # read the lines of file
    for i in range(len(g)):
        g[i] = g[i].rstrip('\n')
    not_sort.close()
    separate = ''.join(g)
    print(separate.split("\\\\"))
    return g

sorted_db = sort_db(path_not_sorted)








