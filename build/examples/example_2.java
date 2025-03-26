class FactorialCalculator {
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    int main() {
        print(factorial(5));
        return 0;
    }
}
