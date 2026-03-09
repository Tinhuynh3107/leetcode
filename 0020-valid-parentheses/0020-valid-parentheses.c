bool isValid(char* s) {
    int n = strlen(s);
    char stack[n / 2 + 1];  
    int top = -1;
    
    if (n & 1) return false;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            if (top >= n / 2) return false; 
            stack[++top] = s[i];
        } else {
            if (top < 0) return false;
            if ((s[i] == ')' && stack[top] == '(') ||
                (s[i] == '}' && stack[top] == '{') ||
                (s[i] == ']' && stack[top] == '['))
                top--;
            else
                return false;
        }
    }
    return top == -1;
}