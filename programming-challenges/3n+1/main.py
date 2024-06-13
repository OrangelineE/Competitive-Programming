"""
ID: yankun.3
TASK: 3n+1
LANG: PYTHON3 
"""

def main():
    def calculate_cycle_length(x):
        l = 1
        while x != 1:
            if x % 2 == 1:
                x = 3 * x + 1
            else:
                x //= 2
            l += 1
        return l
    
    
            



if __name__=="__main__":
    main()
