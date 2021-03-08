
# Chain of Responsibility Pattern

The Chain of Responsibility pattern is a 'behavioral' software design pattern. 
The goal of the pattern is to separate request senders and request handlers,
while giving more than one object a chance to handle the request.

The Chain of Responsibility design pattern allows an object to send a command 
without knowing what object will receive and handle it. 
The request is sent from one object to another making them parts of a chain and 
each object in this chain can handle the command, pass it on or do both.
The most usual example of a machine using the Chain of Responsibility is the 
vending machine coin slot: rather than having a slot for each type of coin, 
the machine has only one slot for all of them. 
The dropped coin is routed to the appropriate storage place that is determined 
by the receiver of the command.



See:
 - [Chain of Responsibility Design Pattern](http://www.oodesign.com/chain-of-responsibility-pattern.html) on oodesign.com
 - [Chain of Responsibility Design Pattern](https://en.wikipedia.org/wiki/Chain-of-responsibility_pattern) on Wikipedia


