char* makeGood(char* s) {
    char* arr = (char*)malloc(strlen(s) + 1);
    int peek = -1;

    for (int i = 0; s[i]; i++){
        if (peek >= 0 && abs(arr[peek] - s[i]) == 32){
            peek--;
        }
        else{
            arr[++peek] = s[i];
        }
    }
    arr[++peek] = '\0';
    return arr;
}