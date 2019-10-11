const quickSort = (oldArray) => {
    if (oldArray.length <= 1) {
        return oldArray;
    } else {
        let left = [];
        let right = [];
        let sortedArray = [];
        let pivot = oldArray.pop();
        let length = oldArray.length;

        for (let i = 0; i < length; i++) {
            if (oldArray[i] <= pivot) {
                left.push(oldArray[i]);
            } else {
                right.push(oldArray[i]);
            }
        }
        return sortedArray.concat(quickSort(left), pivot, quickSort(right));
    }
};



let arr = [3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48]
console.log('Unsorted: ', arr);
console.log('Sorted: ',  quickSort(arr));
