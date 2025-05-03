#pragma once

/**
 * @author Malyson Breno de Souza
 * I just made this bcuz i'm tired of typing, lol.
 **/
class Utils
{
public:

    /**
     * Checks if a value is between a range.
     * @returns True or False.
     **/
    static bool IsBetween(int value, int min, int max);

    /**
     * @param min The starter number.
     * @param max The maximum number.
     * @returns A random number in between two values.
     **/
    static int Rand(int min, int max);

    /**
     * @brief Linear interpolation between two values.
     */
    static float Lerp(float start, float end, float percent);

    /**
     * @brief Clamps a value to ensure it is within the specified range.
     * @param value The value to clamp.
     * @param min The minimum allowed value.
     * @param max The maximum allowed value.
     * @returns The clamped value.
     */
    static int Clamp(int value, int min, int max)
    {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }

    /**
     * @brief Maps a value from one range to another.
     * @param value The value to map.
     * @param inMin The minimum of the input range.
     * @param inMax The maximum of the input range.
     * @param outMin The minimum of the output range.
     * @param outMax The maximum of the output range.
     * @returns The mapped value.
     */
    static float Map(float value, float inMin, float inMax, float outMin, float outMax)
    {
        return (value - inMin) / (inMax - inMin) * (outMax - outMin) + outMin;
    }

    /**
     * @brief Checks if a number is prime.
     * @param number The number to check.
     * @returns True if the number is prime, otherwise false.
     */
    static bool IsPrime(int number)
    {
        if (number <= 1) return false;
        for (int i = 2; i * i <= number; ++i)
        {
            if (number % i == 0) return false;
        }
        return true;
    }
};