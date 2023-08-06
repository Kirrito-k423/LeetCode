

class Solution:
    def minimumString(self, a: str, b: str, c: str) -> str:
        def merge(a, b):
            if a in b: return b
            if b in a: return a
            for i in range(min(len(a),len(b)),0,-1):
                if a[-i:] == b[:i]:
                    return a+b[i:]
            return a+b
        
        ans = ""
        for a,b,c in permutations((a,b,c)):
            s = merge(merge(a,b),c)
            if ans == "" or len(s)<len(ans) or (len(s)==len(ans) and s<ans):
                ans=s
        return ans