# Know how to pass vector and string data to legacy APIs

## Item 16

From Effective STL by Scott Meyers (Addison-Wesley Professional). 
Copyright 2001 Scott Meyers, 978-0-201-74962-5.

Main ideas:

- std::string and std::vector can prevent common programming errors
  (see Effective STL #13) and allow taking full advantage of
  STL algorithms (Effective STL #31)

- Conversion from a std::vector to something that looks just like an array
  is simply &v[0].

- Conversion from a std::string to a null terminated C string is through
  a function the string provides: s.c\_str().

