class Solution {
    encode(strs) {
        let res = '';
        for (let s of strs) {
            res += s.length + '#' + s;  // "4#neet"
        }
        return res;
    }

    decode(str) {
        const res = [];
        let i = 0;

        while (i < str.length) {
            let j = i;

            // Walk forward until we hit '#'
            while (str[j] !== '#') j++;

            const len = parseInt(str.substring(i, j)); // number before '#'
            const word = str.substring(j + 1, j + 1 + len); // slice the word
            res.push(word);

            i = j + 1 + len; // move i to the next encoded word
        }

        return res;
    }
}