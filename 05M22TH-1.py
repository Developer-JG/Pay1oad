from random import *

POINT_COUNT = 25
SELECT_POINT_LIST = 5
BASE = 10

def auto_sub(converted_list):
    count = 0
    for i in range(len(converted_list)):
        for j in range(len(converted_list)):
            if converted_list[i] - converted_list[j] == 0:
                count += 1
        if count > 1:
            return -1
        else:
            count = 0
    return 0

def overlap_point(point_list):
    convert_point_list = []
    for i in range(len(point_list)):
        convert_point_list.append((point_list[i][0] * 100) + point_list[i][1])
    return auto_sub(convert_point_list)

def print_border():
    for i in range(BASE + 2):
        print('\033[33m' + '◼' + '\033[33m', end='')

def print_base(point_list, length_list, select_length_list, blue_select_length):
    print_point_list = []
    for i in range(len(point_list)):
        print_point_list.append(point_list[i] + [length_list[i]])
    sorted_print_list = sorted(print_point_list)
    print_x_list = []
    print_y_list = []
    print_l_list = []
    for i in range(len(sorted_print_list)):
        print_x_list.append(sorted_print_list[i][0])
        print_y_list.append(sorted_print_list[i][1])
        print_l_list.append(sorted_print_list[i][2])

    print_border()
    print("\033[33m")

    for i in range(1, BASE + 1):
        print("◼",end='')
        if i not in print_x_list:
            print(" " * 10, end='')
        else:
            count = 1
            star = 0
            while True:
                del print_x_list[0]
                print(" " * int(print_y_list[0] - count - star),end='')
                if print_l_list[0] == 0:
                    print('\033[31m' + '*' + '\033[33m', end='')
                elif print_l_list[0] == blue_select_length:
                    print('\033[34m' + '*' + '\033[33m', end='')
                elif print_l_list[0] in select_length_list:
                    print('\033[32m' + '*' + '\033[33m', end='')
                else:
                    print('\033[33m' + '*' + '\033[33m', end='')
                count += print_y_list[0] - count
                if star != 1:
                    star = 1
                del print_y_list[0]
                del print_l_list[0]
                if i not in print_x_list:
                    break
            print(" " * int(10 - count), end='')

        print("◼")

    print_border()


def main():
    while True:
        while True:
            point_list = []
            for i in range(POINT_COUNT):
                point_list.append([randint(1, BASE), randint(1, BASE)])
            result = overlap_point(point_list)
            if result == 0:
                break
        select_point = randint(0, POINT_COUNT - 1)
        length_list = []
        for i in range(POINT_COUNT):
            length_list.append((((point_list[select_point][0] - point_list[i][0]) ** 2) + ((point_list[select_point][1] - point_list[i][1]) ** 2)) ** (1 / 2))
        result = auto_sub(length_list)
        if result == 0:
            break
    select_length_list = sorted(length_list)[1 : SELECT_POINT_LIST + 1]

    blue_select_length = select_length_list[randint(0, SELECT_POINT_LIST - 1)]
    blue_select_point = length_list.index(blue_select_length)
    print_base(point_list, length_list, select_length_list, blue_select_length)

    print(f"\n\033[38m전체에서 무작위로 선택된 점: \033[31m({point_list[select_point][0]},{point_list[select_point][1]})\033[38m\n"
          f"이 점과 가까운 점들 중 무작위로 선택된 점: \033[34m({point_list[blue_select_point][0]},{point_list[blue_select_point][1]})\033[38m\n"
          f"증강된 새로운 점: \033[35m({(point_list[select_point][0] + point_list[blue_select_point][0]) / 2},"
          f"{(point_list[select_point][1] + point_list[blue_select_point][1]) / 2})\033[38m")


if __name__ == "__main__":
    main()
