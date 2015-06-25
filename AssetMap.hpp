#include <string>
#include <map>
#include <memory>

template<typename T>
class AssetMap
{
  public:
    AssetMap();

    void LoadContent(const std::string&, const std::string&);

    //Overload the subscript operator
    const T& Get(int pos){mMap[pos];}
  private: //Member functions
    bool AddContent(const std::string&);
  private:
    std::map<int, std::unique_ptr<T>> mMap;
};
