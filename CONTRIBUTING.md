# CONTRIBUTING

> THIS IS A WORK IN PROGRESS

Contributions to this project are welcomed, however, to keep everyone on the same page, please observe formatting conventions described in this guide.

# Formatting
Some of the formatting conventions used in this project go against the "accepted norm". And that's fine. There are some parts of the "accepted norm" that I truly don't like. So, those things are changed in this project. Please don't bother me with, "You shouldn't do 'x' that way...", this is the way **I** like it, and as Brian Kernighan and Dennis Ritchie say in "The C Programming Language", "Pick a style that suits you and stick to it." Well, this style suits me just fine :wink.

## Indentation
Indent using one tab, not spaces, per level of indentation. I know that some people say that you shouldn't use tabs because some systems do something strange with it. But, I've worked on Mac OS X, Linux, Solaris, FreeBSD, OpenBSD and Windows using tabs with no trouble. I say use tabs because the user can set the tab width to 2, for, or even 8 spaces if they wish, and have it look the same. I personally use a tab width of 4 spaces, gives it a nice feel and makes it easy to distinguish the different levels of indentation at a glance.

## Blocks and Braces (and parenthesis and brackets)
Do **not** put the opening braces, also redundently called curly braces) for a block of code on their own line, keep them on the same line as the rest of the opening of a block of code, with a single space just before them. The code between the opening and closing braces should be indented one more level. The closing brace should be on it's own line, at the same identation level as the opening line. The same goes for parentesis and brackets, also reduntantly known as square brackets.



	##### DO ####
	for(i=0; i<=100; i++) {
		while(true) {
			// Put your own code here
		}
	}

	##### DON'T #####
	for(i=0; i<=100; i++)
	{
		while(true)
		{
			// Put your own code here
		}
	}



### Parenthesis
Parenthesis that are a part of a statement, such as a function declaration, for loop, while loop, etc. shoud **not** have a space before or sfter the opening paren, or before the closing paren.



	##### DO #####
	void someFunction(int i, int j) {
		for(i=0; i<=100; i++) {
			while(j < 100) {
				// Some code here
			}
		}
	}

	##### DON'T #####
	void someFunction ( int i, int j )
	{
		for ( i = 0; i <= 100; i++ )
		{
			while ( j < 100 )
			{
				// Some code
			}
		}
	}



### Naming Classes, Function, Variables, Constants and Defines
*ALL* names, whether classes, functions, variables, constants or defines should be descriptive whenever possible, unless they are iterator variables such as the 'i' in an for statement. Additionally, each type of name should follow the appropriate naming convention below. Doing this helps to make it obvious at a glance what it is.
- Class names should use camel case and start with a capital letter, `MyClass()`
- Function names should use camel case and start with a lower case letter `someFunction()` (except for class constructors, which should be named exactly the same as the class)
- Variable names should have an underscore between "words" and start with a lower case letter, `this_var`
- Constants should start with a capital letter and have an underscore between words, with each word captialized, `This_Const`
- Defines should be in all caps, with an underscore between 'words', `MY_DEF`



	##### DO #####
	define MY_DEF 13;
	define MY_OTHER_DEF 10;

	class MyClass {
		int myVar;
		long myVar2;
		const char My_Const[] = "My constant";
		
		public:MyClass(int myVar, long myVar2) {
			// Some code
		}
		
		void anotherFunction() {
			// More code
		}
	}

