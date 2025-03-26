class Sorter {
    void bubbleSort(int[5] arr) {
        int i, j, temp;
        i = 0;
        while (i < 5) {
            j = 0;
            while (j < 5 - i - 1) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
                j = j + 1;
            }
            i = i + 1;
        }
    }

    void printArray(int[5] arr) {
        int i;
        i = 0;
        while (i < 5) {
            print(arr[i]);
            i = i + 1;
        }
    }

    int main() {
        int[5] arr;
        arr[0] = 1;
        arr[1] = 5;
        arr[2] = 8;
        arr[3] = 2;
        arr[4] = 3;
        bubbleSort(arr);
        printArray(arr);        
        return 0;
    }
}
