const numbers = ["100k", "200k", "300k","400k"];

// Custom sort function to handle the "k" suffix in descending order
const customSortDescending = (a, b) => {
    const numA = parseInt(a);
    const numB = parseInt(b);
    return numB - numA;
};

numbers.sort(customSortDescending);

console.log(...numbers);
