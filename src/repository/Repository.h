////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef REPOSITORY_H
#define REPOSITORY_H


class Repository
{
    public:
        Repository();
        ~Repository();

        bool isOk();
        operator bool () { return isOk(); }
};

#endif // REPOSITORY_H
