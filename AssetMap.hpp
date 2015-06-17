#include <string>

class AssetBase
{
  public:
    virtual void LoadContent(const std::string&) = 0;
  private:
};

template<typename T>
class AssetMap : public AssetBase
{
  public:
    AssetMap();

    void LoadContent(const std::string&, const std::string&);

    //Overload the subscript operator
    const T& operator [](int);
  private:
    std::map<int, std::unique_ptr<T>> mMap;
};

template <typename T>
const T& AssetMap::operator [](int pos)
{
  return mMap.find(pos)->second;
}
