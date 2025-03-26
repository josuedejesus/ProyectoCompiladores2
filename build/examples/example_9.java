class ArrayMaxFinder {
    int findMax(int[5] arr) {
        int max, i;
        max = arr[0];
        i = 1;
        while (i < 5) {
            if (arr[i] > max) {
                max = arr[i];
            }
            i = i + 1;
        }
        return max;
    }

    int main() {
        int[5] array;
        array[0] = 11;
        array[1] = 52;
        array[2] = 34;
        array[3] = 27;
        array[4] = 39;

        print(findMax(array));

        return 1;
    }
}
