int KMP(string text, string pattern)
{
    int ret = 0;
    int n = text.size(), m = pattern.size();
    vector<int> T(m+2);
 	
    int k = T[0] = -1;
    rep(i, 0, m)
    {
        while( ~k && pattern[i] != pattern[k] /*&& ( pattern[k] || pattern[i] <= k )*/ ) k = T[k];
        T[i + 1] = ++k;
    }
    
    k = 0;
    rep(i, 0, n)
    {
        while( ~k && text[i] != pattern[k] /*&& ( pattern[k] || text[i] <= k )*/ ) k = T[k];
        ++k;
        if( k == m ) ++ret, k = T[k];
    }
    
    return ret;
    
}
