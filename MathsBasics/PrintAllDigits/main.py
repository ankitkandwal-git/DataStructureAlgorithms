class PrintAllDigits:
    def print_all_digits(self,num):
        if num ==0:
            return 0
        last_digit = num % 10
        print(last_digit)
        num = num // 10
        self.print_all_digits(num)

n = int(input("Enter a number: "))
obj = PrintAllDigits()
obj.print_all_digits(n)