bool judgeCircle(char* moves) {
    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; moves[i]; i++){
        if(moves[i] == 'U') cnt1++;
        else if(moves[i] == 'D') cnt1--;
        else if(moves[i] == 'R') cnt2++;
        else cnt2--;
    }

    return cnt1 == 0 && cnt2 == 0;
}