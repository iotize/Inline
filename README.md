Inline
======

Inline provides a layer upon which to build testing libraries.

Tests, groups, and hooks are added to the root group through the builder's API. This layer of abstraction allows for the DSL language to be visible through the builder's interface.

[OCUnit](http://www.sente.ch/software/ocunit/) uses the `+testInvocations` method on SenTestCase to determine the tests available in that suite. The default implementation retrieves methods which return `void`, have no arguments, and are prefixed with 'test'. This implementation is not easily extendable. Dynamically adding tests would require dynamically adding methods, which is impractical and restrains tests to the rules by which methods must abide.

Calling `+testInvocations` on a subclass of INLTestCase results in a call to `-invocationsForGroup:` on the compiler, which is then responsible for compiling a list of test invocations.

While the SenTestCase class manages all of the invocations in the suite, an instance manages only a single invocation. On `-setInvocation:`, it sets the invocation's target to the test case itself, because it is expecting to invoke a 'test...' method on the subclass. INLTestCase works around this by using instances of INLInvocation. INLInvocation implements the method `+invocationWithTest:`, intended for creating invocations for your INLTest subclass.

INLTestCase also overrides `-name`, the method which [OCUnit](http://www.sente.ch/software/ocunit/) uses to format tests for printing to the console. The default implementation returns the method signature of the `test...` method, but INLTestCase returns the description of the current invocation's test.

Installation
============

Inline is installed via [CocoaPods](https://github.com/CocoaPods/CocoaPods) by adding `pod 'Inline', '~> 0.2.1'` to your Podfile.

Documentation
=============

Comments are written using the [Appledoc](http://gentlebytes.com/appledoc/) syntax, and documentation will be automatically generated and added to Xcode by [CocoaPods](https://github.com/CocoaPods/CocoaPods) upon installation.

License
=======

	Copyright (c) 2013 Ryan Davies

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
