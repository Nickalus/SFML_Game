/* This class was created so that boost filesystem directory iterators
 * would have a begin and end function to make it usable with the c++11 ranged
 * for loops.
*/

#ifndef DIRECTORYRANGE_HPP
#define DIRECTORYRANGE_HPP

#include <boost\filesystem.hpp>

//to clean up code slightly
namespace bfs = boost::filesystem;

class DirectoryRange
{
  public:
    DirectoryRange(bfs::path);
    bfs::directory_iterator begin();
    bfs::directory_iterator end();
  private:
   bfs::path mPath;
};

#endif
