class Solution {
    public int trap(int[] height) {
        int h = height.length;

        // left max
        int[] leftmax = new int[h];
        leftmax[0] = height[0];
        for (int i = 1; i < h; i++) {
            leftmax[i] = Math.max(leftmax[i - 1], height[i]);
        }

        // right max
        int[] rightmax = new int[h];
        rightmax[h - 1] = height[h - 1];
        for (int i = h - 2; i >= 0; i--) {
            rightmax[i] = Math.max(rightmax[i + 1], height[i]);
        }

        // trapped water
        int trappedwater = 0;

        for (int i = 0; i < h; i++) {
            int waterlevel = Math.min(leftmax[i], rightmax[i]);
            trappedwater += waterlevel - height[i];
        }

        return trappedwater;
    }
}