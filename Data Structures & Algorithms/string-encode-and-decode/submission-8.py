class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = ''
        encoded += str(len(strs))
        encoded += '#'
        for i in range(len(strs)):
            encoded += str(len(strs[i]))
            encoded += '#'
            encoded += strs[i]
        print(encoded)
        return encoded

    def decode(self, s: str) -> List[str]:
        k = 0
        while s[k] != '#':
            k += 1
        nofs = int(s[0:k])
        print(nofs)
        decoded = []
        index = k+1
        curlen = -1
        for i in range(nofs):
            l = index
            while s[index] != '#':
                index += 1
            print(l,index,s[l:index])
            curlen = int(s[l:index])
            index += 1
            decoded.append(s[index:index+curlen])
            #print(decoded[i])
            index += curlen
            #print(index,s[index])
            i += 1
        return decoded