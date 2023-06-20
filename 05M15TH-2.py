from random import *

length = 3

def main():
    while True:
        plag = 0
        correct_number = []

        for i in range(0, length):
            correct_number.append(randint(0, 9))

        for i in range(0,length):
            for j in range(0,length):
                if correct_number[i] == correct_number[j]:
                    plag += 1

        if plag == length:
            break

    while True:
        strike = 0
        ball = 0

        ans = list(input("당신의 예상은: "))

        if len(ans) == length:
            for i in range(0,length):
                for j in range(0,length):
                    if int(ans[i]) == int(correct_number[j]):
                        if i == j:
                            strike += 1
                        else:
                            ball += 1

            if strike == length:
                print("정답입니다!")
                break

            if strike == 0 and ball == 0:
                print("아웃!")
            else:
                print(f"{strike} 스트라이크 {ball} 볼.")

        else:
            print("잘못된 길이의 문자를 입력했습니다. 기회가 1회 소모됩니다.")

if __name__ == "__main__":
    main()
