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
};