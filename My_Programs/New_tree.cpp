#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>


#include <ext/rope> //header with rope
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff
using namespace __gnu_pbds;

int main()
{
    
    rope <int> v;
    rope <int> :: iterator it;
    
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) v.push_back(i);
        
    int l, r;
    for(int i = 0; i < m; ++i)
    {
        cin >> l >> r; --l, --r;
        
        rope <int> cur = v.substr(l, r - l + 1);
        for( it = cur.mutable_begin(); it != cur.mutable_end(); it++ )
        	cout << *it << " "; cout << '\n';
        
        v.erase(l, r - l + 1);
        v.insert(v.mutable_begin(), cur);
    }
    
    for( it = v.mutable_begin(); it != v.mutable_end(); it++ )
        cout << *it << " ";
        
    return 0;
}

