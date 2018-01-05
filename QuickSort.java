
public class QuickSort {
    public static void quicksort(int[] arr) {
        quicksort0(arr, 0, arr.length - 1);
    }

    private static void quicksort0(int[] arr, int left, int right) {
        if (left >= right)
            return;
        int key = arr[left], l = left, r = right;
        while (l < r) {
            //一定要先从右边往左边找，因为每次新的基准值都在最左边，右边的数值和基准值交换可以保证顺序，左边的数值和基准值交换也不会有影响
            while (r > l && arr[r] >= key) {
                r--;
            }
            while (l < r && arr[l] <= key) {
                l++;
            }
            if (l < r) {
                swap(arr, l, r);
            }
        }
        arr[left] = arr[l];
        arr[l] = key;
        quicksort0(arr, left, l - 1);
        quicksort0(arr, l + 1, right);
    }

    private static void swap(int[] arr, int i, int j) {
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }

    public static void main(String[] args) {

    }
}
