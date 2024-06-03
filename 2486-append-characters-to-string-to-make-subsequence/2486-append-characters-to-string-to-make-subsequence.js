/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var appendCharacters = function(s, t) {
    let n = s.length;
    let m = t.length;
    let j = 0;
    for(let i = 0; i < n; i++)
    {
        if(s[i] == t[j])
        {
            j++;
        }
    }
    return m - j;
};