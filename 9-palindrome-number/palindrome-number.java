class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;

        char[] arr = String.valueOf(x).toCharArray();

        int i = 0, j = arr.length - 1;

        while (i < j) {
            // swap using temp
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }

        String reversed = new String(arr);

        return String.valueOf(x).equals(reversed);
    }
}