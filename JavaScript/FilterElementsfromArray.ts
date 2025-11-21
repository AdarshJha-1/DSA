type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
    let ans: number[] = [];
    arr.forEach((e, i) => {
        if(fn(e, i)) {
            ans.push(e);
        }
    })

    return ans;
};
