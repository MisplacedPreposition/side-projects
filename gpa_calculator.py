# Mihir Lele
# GPA Calculator

# a list of all grades and corresponding grade point values
grade_dict = {'a+':4,'a':4,'a-':3.7,'b+':3.3,'b':3,'b-':2.7,'c+':2.3,'c':2,'c-':1.7,'d+':1.3,'d':1,'d-':.7,'f':0}

# keeps track of total credits attempted and total grade points earned
credit_total = 0
grade_point_total = 0

while True:
    # asks for the grade, which should match a key in grade_dict
    grade = input('What grade did you get (lowercase)? ')
    # if the grade is not in the dictionary, ask for another grade
    if not grade in grade_dict.keys():
        print('\nTry again\n')
        continue
    # asks the amount of credits for the course
    credit = int(input('How many credits was it worth? '))

    # updates the grade point total and the credit total
    grade_point_total += (grade_dict[grade])*credit
    credit_total += credit

    # if y, ask for another grade, if n, break the loop
    ask = input('Add another grade(y/n)? ')
    if ask == 'y':
        print()
        continue
    elif ask == 'n':
        break

#prints the GPA
print('\nYour GPA is ',grade_point_total/credit_total)
