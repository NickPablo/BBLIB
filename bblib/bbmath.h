/*! @file bbmath.h
 *  @brief A collection of common mathematical functions
 * 
 */

/*! @brief Used to map a number from a set interval [a,b] to another [c,d]
 *  @param x The value to be mapped
 *  @param in_min The minimum possible value of x
 *  @param in_max The maximum possible value of x
 *  @param out_min The minimum possible output of map
 *  @param out_max The maximum possible output of map
 *  @return x mapped from interval [in_min, in_max] to [out_min, out_max]
 */
double map(double x, double in_min, double in_max, double out_min, double out_max);

/*! @brief Returns the greatest value
 *  @param a A number to be compaired
 *  @param b A number to be compaired
 *  @return The largest value passed into max
 */
double max(double a, double b);
