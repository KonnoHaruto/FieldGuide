#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using std::string;

/**
 * Read a string from the user
 *
 * @param prompt the message to show the user
 * @returns the string entered
 */
string read_string(string prompt);

/**
 * Read an integer from the user
 *
 * @param prompt the message to show the user
 * @returns the integer entered
 */
int read_integer(string prompt);

/**
 * Read an integer from the user
 *
 * @param prompt the message to show the user
 * @param low the lower border
 * @param high the higher border
 * @returns the integer entered with range
 */
int read_integer(string prompt, int low, int high);


/**
 * Read an double from the user
 *
 * @param prompt the message to show the user
 * @returns the double entered
 */

double read_double(string prompt);

/**
 * Read an integer from the user
 *
 * @param prompt the message to show the user
 * @returns the string entered (y or n)
 */
bool read_bool(string prompt);

#endif