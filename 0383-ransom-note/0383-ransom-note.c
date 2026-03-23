bool canConstruct(char* ransomNote, char* magazine) {
    int *map = calloc(256, sizeof(int));
    for (int i = 0; ransomNote[i]; i++){
        map[ransomNote[i]] += 1;
    }

    for (int i = 0; magazine[i]; i++){
        map[magazine[i]] -= 1;
    }

    for (int i = 0; ransomNote[i]; i++){
        if (map[ransomNote[i]] > 0) return 0;
    }
    free(map);
    return 1;
}