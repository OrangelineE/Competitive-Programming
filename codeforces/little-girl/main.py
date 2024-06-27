def main():
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))
    arr.sort() # O(nlogn)
    count = []
    for i in range(n):
        count.append(0)
    for _ in range(q):
        l, r = map(int, input().split())
        count[l - 1] += 1
        if r < n:
            count[r] -= 1
    for i in range(1, n):
        count[i] += count[i-1]
    count.sort()
    res = 0
    for i in range(n):
        res += arr[i] * count[i]
    print(res)

if __name__ == "__main__":
    main()
