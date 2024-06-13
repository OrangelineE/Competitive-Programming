
def main():
    n, m, a, b = map(int, input().split())
    # special ticket price is lower
    if b / m < a:
        num = n // m
        remain = n - num * m
        if not remain:
            print(str(num * b))
        else:
            price1 = (num+1)*b
            special = num*b
            remaining = remain * a
            price2 = special + remaining
            print(str(min(price1, price2)))
    # unit price ticket price is lower
    else:
        print(str(n * a))
            
            
if __name__ == "__main__":
    main()