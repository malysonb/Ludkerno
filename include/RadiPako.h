/**
  * Loads or writes a binary file to an a buffer that can be a struct or class (c++).
  * @file RadiPako.h
  * @author Malyson Breno de Souza
  * @version 1.0
  */
#pragma once

#define VersionString "RadiPako 1.0"

typedef struct Rpk RpkFile;

extern int RPK_filesize;

/**
 * Creates the compact file.
 * @param path Path name to create the directory
 * @return 0 if successfully, another one if not.
 */
extern int RPK_CreateFile(const char *path);
/**
 * Assembles your package
 * @param nOfFiles the number of files to be attached.
 * @return 0 if successfully, another one if not.
 */
extern int RPK_CreatePackage(int nOfFiles);

/**
 * Files to be archived.
 * @param numberoffiles the number of files to be attached.
 * @param ... Path to the files.
 * @return 0 if successfully, another one if not.
 */
extern int RPK_JointALotOfFiles(int numberoffiles, ...);

/**
 * Files to be archived.
 * @param numberoffiles the number of files to be attached.
 * @param filepath Path to the files.
 * @return 0 if successfully, another one if not.
 */
extern int RPK_JointFiles(int numberoffiles, char **filepath);

/**
 * Gets the file from an archive.
 * @param RPKpath the archive path
 * @param Filename the file inside the archive.
 * @return the buffer inside an char array.
 */
extern char *RPK_GetFile(const char *RPKpath, const char *Filename);

/**
 * Gets the file from an archive.
 * @param RPKpath the archive path
 * @param Filename the file inside the archive.
 * @return the buffer inside an char array.
 */
unsigned char *RPK_GetFile_Uchar(const char *RPKpath, const char *Filename);