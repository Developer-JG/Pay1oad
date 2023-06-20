def main():
    while True:
        ans = input("시간을 입력하세요: ")

        if ans[-1] == "초":
            input_type = 1
            second = int(ans[:-1])
            minute = int(second/60)
        elif ans[-1] == "분":
            input_type = 2
            minute = int(ans[:-1])
        else:
            input_type = 0

        if input_type != 0:
            print(f"-> {int(minute/60)}시간 {minute%60}분", end=" ")

            if input_type == 1:
                print(f"{second%60%60}초\n-> {round(float(ans[:-1])/60, 4)}분\n-> {round(float(ans[:-1])/60/60, 8)}시간")
            else:
                print(f"\n-> {round(float(ans[:-1])/60, 4)}시간")

        print("\n"*1)

if __name__ == "__main__":
    main()
