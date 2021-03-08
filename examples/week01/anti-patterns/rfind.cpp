// from http://pastebin.com/4Gux5jqL
//
// This anti-pattern demonstrates
// how NOT to reverse find slashes in a string

using string = std::string;

string stripDashes(const string &path) // Not slashes, apparently
{
  string stripped = "";
  auto lastPos = path.find_last_of("/");
  if (lastPos != string::npos)
  {
    stripped = path.substr(0, lastPos) + "/";
  }
  auto lastBackPos = path.find_last_of("\\");
  if ((lastBackPos != string::npos) && ((lastPos == string::npos) || (lastBackPos > lastPos)))
  {
    stripped = path.substr(0, lastBackPos) + "\\";
  }
  else
  {
    stripped = "";
  }
  return stripped;
}

// Well, apart from using length-1 null-terminated string literals where characters would do, and stripping off a
// separator immediately to add it back again, and setting an empty string variable to an empty string literal, 
// and not using the knowledge that by definition npos + 1 == 0, why not just use rfind?

string stripSlashes(const string &path)
{
  string::size_type const lastPos = path.rfind("/\\") + 1;
  return path.substr(0, lastPos);
}
