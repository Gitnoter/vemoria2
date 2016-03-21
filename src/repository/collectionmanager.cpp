/// \file
/// \brief	Vemoria collectionmanager cpp file
/// \ingroup	g_repository
//----------------------------------------------------------------------
// This file is part of the Vemoria project.
// Vemoria aims to be an environment for archiving multimedia files.
//
// This file is licensed under the EUPL v.1.1 or a later version.
//----------------------------------------------------------------------

#include "collectionmanager.h"
#include "git2.h"
#include <QDir>
#include <QTextStream>
#include <QDateTime>


#include <QDebug>
#include "vemoria-config.h"
#include <QFile>
#include <QFileInfo>
#include <QPointer>



using namespace LibQGit2;


CollectionManager::CollectionManager()
{
    ///
    ///@brief CollectionManager provides an overview of what
    /// Collections are available.
    ///


}

CollectionManager::~CollectionManager()
{
    //delete repo;
}

void CollectionManager::getCollectionList()
{

}

bool CollectionManager::createCollection(QString collectionName)
{
    ///
    /// \brief new collection with xml-file in the collection folder
    ///
        if(!QDir(collectionName).exists())
        {
            QString date = QDateTime::currentDateTime().toString();
            QString vemoriaVersion = VEMORIA_VERSION;
            QDir directory = QDir::home();
            if(!QDir(directory.path() + "/.vemoria").exists())
                directory.mkdir(".vemoria");

            directory.mkdir(".vemoria/"+ collectionName);

            QFile file;
            file.setFileName(directory.path()+ "/" + ".vemoria/" + collectionName + "/." + collectionName + ".xml");

            file.open(QIODevice::ReadWrite | QIODevice::Text);
            QTextStream stream(&file);
            stream<<"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"<<endl;
            stream<<"<notes>"<<endl;
            stream<<"\t<version>"+vemoriaVersion+"</version>"<<endl;
            stream<<"\t<repName>" + collectionName + "</repName>"<<endl;
            stream<<"\t<createDate>"<< date <<"</createDate>"<<endl;
            stream<<"</notes>"<<endl;
            file.close();

            ///
            ///\todo replace this by appropriate function calls
            ///
            #ifdef _WIN32
                QByteArray ba = collectionName.toLatin1();
                system("attrib +h " + directory.path().toLatin1() + "\\" + ".vemoria\\" + ba + "\\." + ba + ".xml");
            #endif
            create(collectionName);

        }
        else return false;
    ///
    /// \todo gui has to check if return is false or true to give information to the user
    ///


return true;

}


void CollectionManager::deleteCollection()
{

}

void CollectionManager::create(QString& collectionName)
{
    ///
    /// \brief initial commit with repository-xml
    ///

    int error;
    git_libgit2_init();
    QDir directory = QDir::home();
    git_repository *repo = NULL;
    QByteArray repopath;
    QByteArray pather = directory.path().toUtf8().constData();
    QByteArray vem = "/.vemoria/";
    repopath =  pather + vem + collectionName.toUtf8().constData();
    error = 0;
    error = error + 0;
    /* With working directory: */
    git_repository_init(&repo,repopath, false);
#ifndef _WIN32

    git_index *idx = NULL;
    git_repository_index(&idx, repo);

    git_index_update_all(idx, NULL, NULL, NULL);
    git_index_write(idx);

    git_signature *me = NULL;
    git_signature_now(&me, "User17", "inf017@hs-worms.de");

        git_index *index;
        git_oid tree_id, commit_id;
        git_tree *tree;

        if (git_repository_index(&index, repo) < 0)
            ++error;

        if (git_index_write_tree(&tree_id, index) < 0)
            ++error;

        git_index_free(index);

        if (git_tree_lookup(&tree, repo, &tree_id) < 0)
                ++error;

        if (git_commit_create_v(
                  &commit_id, repo, "HEAD", me, me,
                  NULL, "Initial commit", tree, 0) < 0)
              ++error;

        git_tree_free(tree);
            git_signature_free(me);


    git_libgit2_shutdown();
#endif

#ifdef _WIN32
    QByteArray ba = collectionName.toUtf8().constData();
    QByteArray cmd = "cd .vemoria&&cd " + ba + "&&git add -A&&git commit -m \"Initial commit\"";
    system(cmd);
#endif
}

void CollectionManager::commit(QString& collectionName, QString& commiter_name, QString& commiter_mail, QString& commitmessage)
{
    ///
    /// \brief commit with name mail and message
    ///

#ifndef _WIN32
    git_libgit2_init();
    QDir directory = QDir::home();
    git_repository *repo = NULL;
    QByteArray repopath;
    QByteArray pather = directory.path().toUtf8().constData();
    QByteArray vem = "/.vemoria/";
    repopath =  pather + vem + collectionName.toUtf8().constData();

    git_repository_open(&repo, repopath);

    git_index *idx = NULL;
    git_repository_index(&idx, repo);

    git_index_update_all(idx, NULL, NULL, NULL);
    git_index_write(idx);

    git_signature *me = NULL;
    git_signature_now(&me, commiter_name.toUtf8().constData(), commiter_mail.toUtf8().constData());

        git_index *index;
        git_oid tree_id, commit_id;
        git_tree *tree;
        int error=0;

        if (git_repository_index(&index, repo) < 0)
            ++error;

        if (git_index_write_tree(&tree_id, index) < 0)
            ++error;

        git_index_free(index);

        if (git_tree_lookup(&tree, repo, &tree_id) < 0)
                ++error;

        if (git_commit_create_v(
                  &commit_id, repo, "HEAD", me, me,
                  NULL, commitmessage.toUtf8().constData(), tree, 0) < 0)
              ++error;

        git_tree_free(tree);
            git_signature_free(me);


    git_libgit2_shutdown();
#endif

#ifdef _WIN32
    QByteArray ba = collectionName.toUtf8().constData();
    QByteArray commiter;
    commiter = (commiter_name + commiter_mail).toUtf8().constData();
    QByteArray cmd = "cd .vemoria&&cd " + ba + "&&git add -A&&git commit -m \""+commitmessage.toUtf8().constData()+"\"";
    system(cmd);
#endif

}

