string Solution::minWindow(string S, string T) {
    auto sizeS = S.length();
    auto sizeT = T.length();
    
    if (sizeS < sizeT)
        return "";
        
    int needToFind[256] = {0};
    int hasFound[256] = {0};
    int count = 0;
    int minLength = INT_MAX;
    string res = ""; 
    
    for (auto i = 0; i<sizeT; ++i)
        needToFind[T[i]]++;
    
    for (int p = 0, q = 0; q<sizeS; ++q)
    {
        if (needToFind[S[q]] == 0)
            continue;
        
        hasFound[S[q]]++;
        
        if (hasFound[S[q]] <= needToFind[S[q]])
            ++count;
        
        if (count == sizeT)
        {
            while (hasFound[S[p]] == 0 || hasFound[S[p]] > needToFind[S[p]])
            {
                if (hasFound[S[p]] > needToFind[S[p]])
                    hasFound[S[p]]--;
                ++p;
            }
            
            auto currLength = q - p + 1; 
            if (currLength < minLength)
            {
                res.clear();
                res.append(S.begin()+p, S.begin()+q+1);
                minLength = currLength;
            }
        }
    }
    
    return res;
}
