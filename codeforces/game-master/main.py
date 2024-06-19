def main():
    tests = int(input()) 
    for i in range(tests):
        players = int(input())
        if players == 1:
            print(1)
            continue
        res = [] 
        map1 = list(map(int, input().split()))
        map2 = list(map(int, input().split()))
        for p in players:
            res.append(0)
        max1 = map1.index(max(map1))
        max2 = map1.index(max(map2))
        res[max1] = 1
        res[max2] = 1
        if max1 != max2:
            for p in range(players):



        res = ''.join(map(str,res))
        print(res)

if __name__ == "__main__":
    main()
