class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;

        // Step 1: Trim leading and trailing spaces
        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;

        string temp = "", ans = "";
        while (left <= right) {
            char ch = s[left];

            // If character is not space, add to temp
            if (ch != ' ') {
                temp += ch;
            } else if (temp != "") {
                // Add word to the front of ans
                if (ans != "") ans = temp + " " + ans;
                else ans = temp;
                temp = "";
            }
            left++;
        }

        // Add the last word (if any)
        if (temp != "") {
            if (ans != "") ans = temp + " " + ans;
            else ans = temp;
        }

        return ans;
    }
};
