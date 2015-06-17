#include "AssetMap.hpp"
#include "DirectoryRange.hpp"


AssetMap::AssetMap()
{

}

void AssetMap::LoadContent(const std::string& path, const std::string& ext)
{
  //Create a temp vector for the file entries to go to
  std::vector<bfs::directory_entry> files;

  //Create the directory
  bfs::path spriteDir(path);

  spriteDir.make_preferred();

  //Check to see if the directory exists
  if(bfs::exists(path))
  {
    //Loop through all files in the dir
    for(auto file : DirectoryRange(spriteDir))
    {

    }
  }
  else
  {
    std::cout << "'./Data/Images/Sprites' Does not exist" << std::endl;
  }
}
