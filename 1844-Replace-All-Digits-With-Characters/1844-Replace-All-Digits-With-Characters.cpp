string replaceDigits(string s) {
    string result = "";
    int i = 1;
    while (i < s.length()) {
        int temp = s[i] - '0';
        s[i] = s[i - 1] + temp;
        i += 2;
    }
    return s;
}