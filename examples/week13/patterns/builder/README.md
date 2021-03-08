
# Builder Pattern

The builder pattern is an object creation software design pattern. 
Unlike some other creatinal patterns designed to enable polymorphism, 
the goal of the builder pattern is to find a solution to the 'telescoping constructor' anti-pattern.

The Telescoping Constructor is an example of an anti-pattern that is all too often used
 in projects even though there are better alternatives availble. 
In this pattern, your class has numerous constructors each taking a different number of parameters that, 
if the class has been written correctly, delegate to a default constructor.

When confronted with many optional parameters, a builder is a more effective option.

This is not *exactly* consistent with the traditional 'Gang of Four' definition of a 'Builder',
which is a more complex design pattern.

See:
 - [Builder Design Pattern](http://www.oodesign.com/builder-pattern.html) on oodesign.com
 - [Builder Design Pattern](https://en.wikipedia.org/wiki/Builder_pattern) on Wikipedia
 - [Example telescoping constructor](https://gist.github.com/DavidTPate/9041099)
 - [Effective Java item #2 builder](https://books.google.com/books?id=ka2VUBqHiWkC&pg=PA11&lpg=PA11&dq=nutrition+facts+builder+java&source=bl&ots=y_CoNlr6P4&sig=oC2P2Hkg1Ad-ogGbwgvfiPxoBpc&hl=en&sa=X&ved=0ahUKEwjVmfzvtJ7XAhUC6mMKHWpXCXcQ6AEIPjAE#v=onepage&q=nutrition%20facts%20builder%20java&f=false)


