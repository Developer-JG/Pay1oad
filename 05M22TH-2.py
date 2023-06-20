def main():
    while True:
        end_num = change_int(input("2 이상의 자연수 중, 몇까지의 소수를 검사할까요?: "))
        if end_num > 2:
            all_number_list = [x for x in range(2, end_num+1)]
            prime_number_list = all_number_list[:]
            sieve_of_eratosthenes = []
            for i in range(len(all_number_list)):
                sieve_of_eratosthenes.append([i+2])
                for j in range(i+1, len(all_number_list)):
                    if all_number_list[j] % all_number_list[i] == 0:
                        if j != 0 and all_number_list[j] in prime_number_list:
                            prime_number_list.remove(all_number_list[j])
                        sieve_of_eratosthenes[i].append(all_number_list[j])
            result_print(all_number_list, prime_number_list, sieve_of_eratosthenes)
        else:
            print("올바른 숫자를 입력하세요.\n")
        print()


def result_print(all_number_list, prime_number_list, sieve_of_eratosthenes):
    not_prime_number_list = list(set(all_number_list) - set(prime_number_list))
    print(f"\n2부터 {all_number_list[-1]}까지 소수인 수는 총 {len(prime_number_list)}개 발견되었습니다:\n{prime_number_list}\n\n"
          f"2부터 {all_number_list[-1]}까지 소수가 아닌 수는 총 {len(not_prime_number_list)}개 발견되었습니다:\n{not_prime_number_list}\n\n"
          f"만들어진 에라토스테네스의 체는 다음과 같습니다:")
    for i in range(len(prime_number_list)):
        print(f"소수 {prime_number_list[i]}의 배수: {sieve_of_eratosthenes[prime_number_list[i]-2]}")



def change_int(in_put):
    try:
        if '.' in in_put:
            out_put = int(float(in_put))
            print(f"{in_put}은 자동적으로 {out_put}으로 전환되었습니다.")
        else:
            out_put = int(in_put)
    except:
        out_put = -1
    return out_put


if __name__ == "__main__":
    main()
