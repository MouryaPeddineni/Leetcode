/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let mpp = [];
    for(let i=0;i<arr.length;i++){
        mpp[i] = fn(arr[i], i);
    }
    return mpp;
};