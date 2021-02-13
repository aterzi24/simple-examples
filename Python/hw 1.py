def marble_game(str_list):
    max = 0
    for list in str_list:
        point = 0
        for str in list:
            if str == 'red':
                point += 2
            elif str == 'white':
                point += 5
            elif str == 'green':
                point += 8
            elif str == 'yellow':
                point += 0
            else:
                point += 1
        if max <= point:
            max = point
            max_list = list
    return [max_list, max]
