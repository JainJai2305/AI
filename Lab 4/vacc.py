def clean(floor, i, j):
    floor[i][j] = 0
    return floor


def show(floor, a, b):
    for i in range(len(floor)):
        for j in range(len(floor[0])):
            if i == a and j == b:
                print("X/{}".format(floor[i][j]), end="\t")  # X shows position of vaccum cleaner
            else:
                print(floor[i][j], end="\t")
        print()


print("Enter row and columns: ")
n, m = map(int, input().split())
print("Enter the floor :")
floor = []
for i in range(n):
    a = []
    floor.append(input().split())

for i in range(n):
    if i % 2 == 0:
        for j in range(m):
            print("Moving Right")
            if floor[i][j] == "1":
                print("Dirty!!  Cleaning Now...")
                floor = clean(floor, i, j)
                show(floor, i, j)
                print("*" * 20)
            else:
                print("Clean!!")
                print("*" * 20)

    else:
        for j in range(m - 1, -1, -1):
            print("Moving Left")
            if floor[i][j] == "1":
                print("Dirty!!  Cleaning Now...")
                clean(floor, i, j)
                show(floor,i,j)
                print("*" * 20)
            else:
                print("Clean!!")
                print("*" * 20)

    print("Moving Down")