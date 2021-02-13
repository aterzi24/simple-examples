def employee_info(infos, times):
    list = infos.split(",")
    list2 = times.split(",")
    dictlist = []
    for i in range(len(list)):
        temp = list[i].split()
        dict = {"Name": temp[0], "Surname": temp[1].upper(), "Age": int(temp[2]),
            "Position": temp[3], "Employment Time": int(list2[i])}
        dictlist.append(dict)
        return dictlist
