#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "AssetMap.hpp"

namespace bfs = boost::filesystem;

template <class T>
AssetMap<T>::AssetMap()
{

}

template <class T>
void AssetMap<T>::LoadContent(const std::string& path, const std::string& ext)
{
  //Create the path with boost filesystem
  bfs::path directory(path);

  //Check to see if the directory exists
  if(bfs::exists(path))
  {
    //create the iterators
    bfs::directory_iterator iterator(directory), end;

    //Loop through all files
    for(; iterator != end; ++iterator)
    {
      //Check the extension of the file
      if(iterator->path().extension() == ext)
      {
        //add to map
        AddContent(iterator->path().filename().string());
      }
    }
  }
  else
  {
    std::cout << path << " Does not exist!" << std::endl;
  }
}

template <class T>
bool AssetMap<T>::AddContent(const std::string& content)
{
  return true;
}
