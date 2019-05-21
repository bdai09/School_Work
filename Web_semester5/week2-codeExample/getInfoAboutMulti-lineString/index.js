/**
 * Import the count.js module into our code and
 * access the `processText` property on the imported
 * exports Object.
 */
const { processText } = require('./count');

// Define a multiline string to analyze
const text = `This is the first line
This is the second line.
And this is the third.`;

// Pass our string to `processText`
const info = processText(text);

// Log the result in the console
console.log(info);
