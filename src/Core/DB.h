/*
   Copyright 2016 Nidium Inc. All rights reserved.
   Use of this source code is governed by a MIT license
   that can be found in the LICENSE file.
*/
#ifndef core_db_h__
#define core_db_h__

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <string>

namespace leveldb {
class DB;
};

namespace Nidium {
namespace Core {

class DB
{
public:
    explicit DB(const char *name);
    ~DB();

    /*
        Check status after the constructor is caller
    */
    bool ok() const
    {
        return m_Status;
    }

    bool set(const char *key, const uint8_t *data, size_t data_len);
    bool set(const char *key, const char *string);
    bool set(const char *key, const std::string &string);
    bool get(const char *key, std::string &ret);
    bool del(const char *key);
    bool close();
    bool drop();

protected:
    leveldb::DB *m_Database;

private:
    bool m_Status;
    char *m_Name;
};

} // namespace Core
} // namespace Nidium

#endif
