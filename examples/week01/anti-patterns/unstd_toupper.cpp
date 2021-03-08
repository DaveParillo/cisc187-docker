// from http://thedailywtf.com/articles/unstd-toupper
// how not to convert a string to upper case
//
// C++ is a language with a… checkered past. 
// It’s grown, matured and changed over the decades, 
// and modern C++ looks very little like the C++ of yesteryear. 
//
// Standard libraries have grown and improved- these days, std feels 
// nearly as big and complicated as parts of Java’s class library.
//
// One useful function is std::toupper. 
// Given a char, it will turn that char into an upper-case version, 
// in a locale-aware fashion. 
// What if you want to turn an entire string to upper-case?
//
// You might be tempted to use a function like std::transform, 
// which is C++’s version of “map”. 
// It alters the string in-place, turning it into an upper-cased version. 
// With a single line of code, you could easily convert strings to upper-case.
//
// Or, you could do what Tomek’s highly-paid consultant did.

std::string toupper(std::string val)
{
    std::string out;
    if (val.empty())
        return "";
    std::for_each(val.begin(), val.end(), std::toupper);
    return out;
}


// Like a true highly-paid consultant, 
// the developer knew that programmer time is more expensive 
// than memory or CPU time, so instead of wasting keystrokes 
// passing the input as a const-reference, they passed by value. 
// Sure, that means every time this function is called, 
// the string must be copied in its entirety, 
// but think of the developer productivity gains!

// It’s always important to be a defensive programmer, 
// so in true consultant fashion, we’ll check to ensure 
// that the input string isn’t already empty. Of course, 
// since we manipulate the string with std::for_each, 
// we don’t actually need that check, it’s better to be explicit.

// Speaking of for_each, it has one advantage over transform- 
// it won’t modify the string in place. 
// In fact, it won’t modify the string at all, at least as written here. 
// Everyone knows immutable objects cut down on many common bugs, 
// so this is an excellent design choice.

// And finally, they return out, 
// the string variable declared at the top of the function, 
// and never initialized. 
// This, of course, is because while your requirements said 
// you _needed_ to turn strings into fully upper-case versions, 
// you don’t _actually_ need that. 
// 
// This is a better solution that’s more suited to your business needs.
