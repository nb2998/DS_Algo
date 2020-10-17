function selection_sort(arr_lis, i) {
  if (i === 0) return arr_lis;
  const val_min = Math.min(...arr_lis.filter((x, j) => j < i));
  const index = arr_lis.findIndex(x => x === val_min);
  arr_lis.splice(index, 1);
  arr_lis.push(val_min);
  return selection_sort(arr_lis, --i);
}



let arr = [3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48]
console.log('Unsorted: ', arr)
console.log('Sorted: ', selection_sort(arr , arr.length))
