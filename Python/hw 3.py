def satisfactory(filename):
    f = open(filename, "r")
    lines = f.readlines()
    count = 0
    for i in lines:
        grades = i.split()
        finalGrade = (int(grades[0]) + int(grades[1])) / 20;
        finalGrade += (int(grades[2]) + int(grades[3])) / 5;
        finalGrade += int(grades[4]) / 2;
        if (finalGrade >= 55):
            count += 1
    f.close()
    return count
