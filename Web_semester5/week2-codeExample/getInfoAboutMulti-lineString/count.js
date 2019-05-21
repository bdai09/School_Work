/**
 * Example module to get info about a multi-line string,
 * written as a node.js module.
 *
 * Takes a multiline string, and returns an Object:
 *
 * "here is a line of text"
 * 
 * {
 *   lines: [
 *     {
 *       line: "here is a line of text",
 *       count: 17
 *     },
 *     {
 *       line: "here is the 2nd line of text",
 *       count: 17
 *     },
 *      
 *   count: 17
 * }

/** 
 * Split the given string into lines, taking into
 * account Windows (\r\n) vs. Unix (\n) line endings.
 */
const splitIntoLines = text => text.split(/\r?\n/);

/*
 * Count the number of non-whitespace (space, tab, etc)
 * characters in the given string, returning the count
 * "here is a           line of text" -> 17
 */
const countNonWhitespace = text => text.replace(/\s+/g, '').length;

/**
 * Process a list of lines (Array of Strings) into an
 * Array of Objects, where each Object has info about
 * the given line:
 * 
 *  - The `line` itself
 *  - The `count` of non-whitespace characters in the line
 *  - The `number` of the line in the string, starting at 1
 */
const processLines = list =>
    list.map((element, index) => {
        return {
            line: element,
            count: countNonWhitespace(element),
            number: index + 1
        };
    });

// Reduce:    arr.reduce(callback(accumulator, currentValue[, index[, array]])[, initialValue])
// 5 + 1 + 2 + 3 + 4
//console.log(array1.reduce(reducer, 5));
// expected output: 15
const getTotalCharacters = lines =>
    lines.reduce((total, element) => total + element.count, 0);

/**
 * Main public entry point to the module.  Take
 * the given multi-line string, and produce an Object
 * with info about each line, as well as a total
 * character count for non-whitespace characters.
 */
function processText(text) {
    const lines = processLines(splitIntoLines(text));

    return {
        lines,
        total: getTotalCharacters(lines)
    };
}

/**
 * Expose the `processText` function on the module's `exports`
 * Object, making it accessible to callers.  All other functions
 * will remain "hidden" within this module.
 */
exports.processText = processText;
