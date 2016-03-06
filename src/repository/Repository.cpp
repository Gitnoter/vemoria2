////////////////////////////////////////////////////////////////////////
/// Project Vemoria                                                    /
///                                                                    /
/// Vemoria aims to be an environment for archiving multimedia files.  /
///                                                                    /
///                                                                    /
/// This project is licensed under the EUPL v.1.1 or a later version.  /
////////////////////////////////////////////////////////////////////////
#include "Repository.h"
#include "qgit2.h"

Repository::Repository()
{
    // TODO: What should we do if init... returns false?
    // raise an exception?
    (void) LibQGit2::initLibQGit2();
}

Repository::~Repository()
{
    // we ignore the return code silently - what should we do?
    (void) LibQGit2::shutdownLibQGit2();
}

bool Repository::isOk()
{
    // TODO: Implement
    return false;
}
