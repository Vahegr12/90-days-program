let test_1 = (element) => element > 1 && element < 1000;
let test_2 = (element) => element > 100;


let arr_1 = [1,2,3,"https",'a'];
let arr_2 = [12,234,2,42,232,24,23];

//push_back int 12 to arr_1 array
    arr_1.push(12);
    //console.log(arr_1);

// get element from array by index and intialize tmp variable
    let tmp = arr_2.at(1);
    //console.log(arr_2);

//create new array by merging 2 array and initalize arr_3 by it;
    let arr_3 = arr_1.concat(arr_2);
    //console.log(arr_3);

//test every element in array
    //console.log("All elemets are betwen 1 and 1000", arr_2.every(test_1));

//test every element in array and make filterd array
    let arr_2_filtered = arr_2.filter(test_2);
    //console.log(arr_2_filtered);

//decapsulate subarrays by passed depth
    let arr_4 = [10,[10,11],[[12,13],[14,15]]];
    //console.log(arr_4.flat(1));
    //console.log(arr_4.flat(2));
    //console.log(arr_4.flat(3));

//call function for each element of array // increment every element
    function increment(element, index, array) {
        array[index] = element + 1;
    }
    let arr_5 = [1,2,3,4,5,6,7,8,9]
    arr_5.forEach(increment);
    //console.log(arr_5);

//get index or last index of passed element 
    let arr_6 = ["Yerevan",'a',"Hrazdan",12,'a',true];
    //console.log(arr_6.indexOf('a'));
    //console.log(arr_6.indexOf("Hrazdan"));
    //console.log(arr_6.indexOf(5));
    //console.log(arr_6.lastIndexOf('a'));

//call function for every element and store result in new array
    let arr_7 = [1,2,3,4,5,6,7,8,9];
    let arr_7_edited = arr_7.map(el => --el);
    //console.log(arr_7_edited);

//call funtion to reduce array to a single value with using preinitialized acumuliator 
    let arr_8 = [1,2,3,4,5,6,7,8,9];
    let result = arr_8.reduce((accumulator, currentValue) => {
        return accumulator * currentValue;
    }, 1);   
    //console.log(result);   

//reverce positions of element of array
    let arr_9 = [1,2,3,4,5,6,7,8,9];
    arr_9.reverse();
    //console.log(arr_9);

//get copy of elements of array from posintion to position
    let arr_10 = [1,2,3,4,5,6,7,8,9];
    //console.log(arr_10.slice(2,6));

//test if at least one element of array meets requerment (bool function)
    let arr_11 = [1,2,3,4,5,6,7,8,9];
    //console.log(arr_11.some(el => !(el % 10)));

//sort array by alphabetically metod
    let arr_12 = [213,324,9,5,345,5,78,45,3];
    //console.log(arr_12.sort());

//replace/add/delete element(s) of array by passing position, count, element
    let arr_13 = ["Yerevan","Gyumry","Hrazdan","Vanadzor"];
    arr_13.splice(2,1,"Vanadzor");
    arr_13.splice(3,1,"Hrazdan");
    //console.log(arr_13);

//get iterators to key/value pair elements storing index/element   
    let arr_14 = ["Yerevan","Gyumry","Hrazdan","Vanadzor"];
    let iter = arr_14.entries();
    //console.log(iter.next().value);
    //console.log(iter.next().value);

//fill array from position to position by element
    let arr_15 = [1,2,3,4,5,6,7,8,9];
    arr_15.fill(0,3,7);
    //console.log(arr_15);

//get first element of array that meets the requerment
    let arr_16 = [1,2,3,4,5,6,7,8,9];
    //console.log(arr_16.find(el => el > 6));

//get index of first element of array that meets the requerment
    let arr_17 = [1,2,3,4,5,6,7,8,9];
    //console.log(arr_16.findIndex(el => el > 8));

//get index of last element of array that meets the requerment
    let arr_19 = [1,2,3,4,5,6,7,8,9];
    //console.log(arr_16.findLastIndex(el => el < 6));

//get true if array contains the element
    let arr_20 = [1,2,3,4,5,6,7,8,9];
    //console.log(arr_20.includes(9));
    //console.log(arr_20.includes(10));

//get string by mereging elements separated by variable chars // ',' by default
    let arr_21 = ["Yerevan","Gyumry","Hrazdan","Vanadzor"];
    //console.log(arr_21.join());
    //console.log(arr_21.join('-'));
    //console.log(arr_21.join(''));

//get new array with replaced elements
    let arr_22 = ["Yerevan","Gyumry","Hrazdan","Vanadzor"];
    //console.log(arr_22.with(1,"Unknown"));
    //console.log(arr_22);
