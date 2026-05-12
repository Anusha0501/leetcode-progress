class Solution {
    public String removeOccurrences(String s, String part) {

        StringBuilder sb = new StringBuilder();
        int n = part.length();

        for(char ch : s.toCharArray()){

            sb.append(ch);

            if(sb.length() >= n &&
               sb.substring(sb.length() - n).equals(part)){

                sb.delete(sb.length() - n, sb.length());
            }
        }

        return sb.toString();
    }
}