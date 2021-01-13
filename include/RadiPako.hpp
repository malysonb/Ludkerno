#pragma once

#include <vector>

namespace RadiPako
{
    struct RPK_File
    {
        int size = 0;
    public:
        std::string name;
        unsigned char *content;
        ~RPK_File();
        int getSize();
    };

    class RPK
    {
    public:
        const char *MagicNumber = "RPKO";
        int size = 0;
        char Version[4];
        int NumOfFiles = 0;
        std::vector<RPK_File *> Files;
        ~RPK();
        void Dispose();
    };

    const char *VersionString();

    /**
    * Gets the file from an archive.
    * @param RPKpath the archive path
    * @param Filename the file inside the archive.
    * @return the buffer inside an char array.
    */
    char *GetFile_Content(RPK *file, const char *Filename);

    char *GetFile_Content(RPK_File *file);

    /**
    * Gets the file from an archive.
    * @param File the archive path
    * @param Filename the file inside the archive.
    * @return the buffer inside an char array.
    */
    unsigned char *GetFile_Content_Uchar(RPK *file, const char *Filename);
    /**
     * @brief 
     * Gets a file buffer
     * @param File 
     * @param Filename 
     * @return unsigned char* 
     */
    unsigned char *GetFile_Content_Uchar(RPK_File *file);

    RPK_File *GetFile(RPK *File, const char *Filename);

    /**
    * Files to be archived.
    * @param numberoffiles the number of files to be attached.
    * @param filepath Path to the files.
    * @return 1 if successfully, another one if not.
    */
    RPK *JointFiles(int numberoffiles, char **filepath);

    RPK *JointFiles(int numberoffiles, std::vector<std::string> filepath);

    /**
    * Creates the compact file.
    * @param path Path name to create the directory
    * @return 1 if successfully, another one if not.
    */
    int CreateFile(RPK *file_rpk, const char *path);
    /**
    * Assembles your package
    * @param nOfFiles the number of files to be attached.
    * @return 1 if successfully, another one if not.
    */
    /*static int CreatePackage(int nOfFiles);*/

    RPK *LoadRPKFile(const char *path);

} // namespace RadiPako

//class RadiPako
//{
//private:
//public:
//
//    static const char *VersionString();
//
//    /**
//    * Gets the file from an archive.
//    * @param RPKpath the archive path
//    * @param Filename the file inside the archive.
//    * @return the buffer inside an char array.
//    */
//    static char *GetFile_Content(RPK *file, const char *Filename);
//
//    static char *GetFile_Content(RPK_File *file, const char *Filename);
//
//    /**
//    * Gets the file from an archive.
//    * @param File the archive path
//    * @param Filename the file inside the archive.
//    * @return the buffer inside an char array.
//    */
//    static unsigned char *GetFile_Content_Uchar(RPK *file, const char *Filename);
//    /**
//     * @brief
//     * Gets a file buffer
//     * @param File
//     * @param Filename
//     * @return unsigned char*
//     */
//    static unsigned char *GetFile_Content_Uchar(RPK_File *file);
//
//    static RPK_File *GetFile(RPK *File, const char *Filename);
//
//    /**
//    * Files to be archived.
//    * @param numberoffiles the number of files to be attached.
//    * @param filepath Path to the files.
//    * @return 1 if successfully, another one if not.
//    */
//    static RPK *JointFiles(int numberoffiles, char **filepath);
//
//    static RPK *JointFiles(int numberoffiles, std::vector<std::string> filepath);
//
//    /**
//    * Creates the compact file.
//    * @param path Path name to create the directory
//    * @return 1 if successfully, another one if not.
//    */
//    static int CreateFile(RPK *file_rpk, const char *path);
//    /**
//    * Assembles your package
//    * @param nOfFiles the number of files to be attached.
//    * @return 1 if successfully, another one if not.
//    */
//    /*static int CreatePackage(int nOfFiles);*/
//
//    static RPK *LoadRPKFile(const char *path);
//};