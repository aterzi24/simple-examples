def calculate_cgpa(student_id):
    gpa_sum = 0.0
    semester_num = 0
    for i in range(1, 9):
        try:
            temp = get_gpa(student_id, i)
            gpa_sum += temp
            semester_num += 1
        except KeyError:
            return -1.0
        except IndexError:
            gpa_sum += 1.0
            semester_num += 1
        except ValueError:
            semester_num += 0
    calculated_cgpa = gpa_sum / semester_num
    return round(calculated_cgpa, 2)
