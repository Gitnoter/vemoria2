////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#ifndef DOCUMENT_H
#define DOCUMENT_H
#include "logic/item.h"
#include <QString>


class Document: Item
{
    //!
    //! \brief Metadata of Class Document
    //! \param title;
    //! \param subject;
    //! \param creator;
    //! \param company;
    //! \param alterationdate;
    //! \param numberofpages;
    //! \param miscellaneous;
    //!
    QString title;
    QString subject;
    QString creator;
    QString company;
    QString alterationdate;
    QString numberofpages;
    QString miscellaneous;
public:
    Document();
};

#endif // DOCUMENT_H
