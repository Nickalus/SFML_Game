#include "DirectoryRange.hpp"

DirectoryRange::DirectoryRange(bfs::path p)
: mPath(p)
{
}

bfs::directory_iterator DirectoryRange::begin()
{
  return bfs::directory_iterator(mPath);
}

bfs::directory_iterator DirectoryRange::end()
{
  return bfs::directory_iterator();
}
