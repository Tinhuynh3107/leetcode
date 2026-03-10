bool judgeCircle(char* moves) {
    int size = strlen(moves);
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0; i < size; i++){
        if(moves[i] == 'U') cnt1++;
        else if(moves[i] == 'D') cnt1--;
        else if(moves[i] == 'R') cnt2++;
        else if(moves[i] == 'L') cnt2--;
    }

    return cnt1 == 0 && cnt2 == 0;
}