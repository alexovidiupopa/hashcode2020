from math import ceil


class Street:
    def __init__(self, start, end, name, duration):
        self.start = start
        self.end = end
        self.name = name
        self.duration = duration
        self.queue = []
        self.coeff = 0

def main():
    d = 0
    i = 0
    s = 0
    v = 0
    f = 0
    street_names = {}
    visited_streets = []


    ans = {}  # asta e raspunsul :)

    streets = []
    paths = []
    with open('e.txt', 'r') as fin:
        first = fin.readline().strip().split(' ')
        d = int(first[0])
        i = int(first[1])
        s = int(first[2])
        v = int(first[3])
        f = int(first[4])
        for j in range(0, s):  # streets
            second = fin.readline().strip().split(' ')
            b = int(second[0])
            e = int(second[1])
            name = second[2]
            l = int(second[3])
            street = Street(b, e, name, l)
            street_names[name] = street
        for j in range(0, v):  # paths
            third = fin.readline().strip().split(' ')
            p = int(third[0])
            paths.append(third[1:])
            if third[1] in street_names.keys():
                street_names[third[1]].queue.append(j)
            for street in paths[j][:-1]:
                if street not in visited_streets:
                    visited_streets.append(street)
                    street_names[street].coeff+=1
                else:
                    street_names[street].coeff+=1

    n = len(visited_streets)
    remaining = s - n

    for street in visited_streets:
        if street_names[street].end not in ans.keys():
            ans[street_names[street].end] = [street_names[street]]
        else:
            ans[street_names[street].end].append(street_names[street])



    #print(ans)

    with open('oute.txt', 'w') as g:
        g.write(str(len(ans)) + "\n")
        for key in ans.keys():
            g.write(str(key) + "\n")
            g.write(str(len(ans[key])) + "\n")
            length = len(ans[key])
            if length == 1:
                g.write(str(ans[key][0].name) + " 1" + "\n")
            else:
                total_coeff = 0
                for values in ans[key]:
                    total_coeff += values.coeff
                ans[key] = sorted(ans[key], key=lambda k: k.coeff, reverse=False)
                counter = 1
                for values in ans[key]:
                    g.write(values.name + " " + str(1) + "\n")
                    counter+=1
                    if counter>d/2:
                        counter = 1



main()
