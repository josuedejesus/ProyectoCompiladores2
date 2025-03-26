class RefExample {
    void incrementBy(ref int x, int y) {
        x = x + y;
    }

    void applyIncrements() {
        int base;
        int[5] values;
        int i;

        base = 0;
        i = 0;
        while (i < 5) {
            incrementBy(base, i);
            values[i] = base + i;
            i = i + 1;
        }
        print(values[0]);
        print(values[1]);
        print(values[2]);
        print(values[3]);
        print(values[4]);
    }

    int main() {
        applyIncrements();
        return 0;
    }
}

