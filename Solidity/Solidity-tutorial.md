# Solidity Tutorial

YT Course: https://www.youtube.com/watch?v=ipwxYa-F1uY&ab_channel=freeCodeCamp.org

##  Intro to solidity

Solidity is a contract-oriented, high-level language for implementing smart contracts. It is designed to target the Etherenum Virtual Machine (EVM).

It is statically typed, supports inheritance, libraries and complex user-defined types among other features.

[Click this link to run solidity online - Remix IDE](https://remix.ethereum.org/#optimize=false&runs=200&evmVersion=null&version=soljson-v0.8.7+commit.e28d00a7.js)

### Pragma
Pragma is generally the first line of code within any Solidity file. pragma is a directive that specifies the compiler version to be used for current Solidity file.
```
pragma solidity ^0.4.24; // Use solidity version > 0.4.24

```

### Smart Contracts
Smart contract is a piece of code that gets executed on the ethereum blockchain. It is like a microservice on the web. Users will be able to see it, read it, write data on it and execute any code that we write in it.

```
contract MyContract {
	string value;
}
```

*value* is a variable that the entire contract will know about, it is NOT a local variable. For a smart contract, this means that the data is actually stored on the blockchain. Whenever we set its value, we'll be writing data onto the blockchain.

```
contract MyContract {
	string value;

	function get() public returns(string) {
		return value;
	}
}
```

The *public* keyword tells the blockchain the visibility of the function, in this case it can be accessed by anyone who has access to the smart contract on the blockchain.

On compiling this piece of code, we get the following error:

```
from solidity:

MyContract.sol:6:2: Warning: Function state mutability can be restricted to view function get() public returns(string) {

^ (Relevant source part starts here and spans across multiple lines).
```

This pops up because we aren't changing the value of the variable. To avoid this error, we add an additional modifier- *view*. The code ends up looking like this:

```
contract MyContract {
	string value; // This is a global variable.

	function get() public view returns(string) {
		return value;
	}
}
```

Now, we're going to set the value of the variable *value*.

```
contract MyContract {
	string value;

	function get() public view returns(string) {
		return value;
	}

	function set(string _value) public {
		value = _value;
		// _value is a local variable
	}
}
```

Whenever this smart contract is deployed or generated for the first time, we can set the initial values using a constructor function.

A constructor functuon is called whenever the contract is created or whenever the smart contract is deployed in the blockchain.

```
pragma solidity ^0.4.24;

contract MyContract {
	string value;

	constructor() public {
		value = "myValue";
	}

	function get() public view returns(string) {
		return value;
	}

	function set(string _value) public {
		value = _value;
	}
}
```

The above block of code is how your final program should look like.  Compile the contract with default settings and deploy it with the following values:
- Environment: JavaScript VM
- Leave the rest as defaults.

Once you hit the deploy button, you should be able to see MyContract as one of the deployed contracts. On expanding it, you'll be able to set and get the value for the variable *value*.

## Data types and data structures

For this section, we're going to update the code to support a newer version of solidity.

```
pragma solidity ^0.5.1;

contract MyContract {
	string value;

	constructor() public {
		value = "myValue";
	}

	function get() public view returns(string memory) {
		return value;
	}

	function set(string memory _value) public {
		value = _value;
	}
}
```

For the version 0.8.13,

```
// SPDX-License-Identifier: MIT

pragma solidity ^0.8.13;

contract MyContract {
	 string value;

	 constructor() {
		 value = "myValue";
	 }

	 function get() public view returns(string memory) {
		 return value;
	 }

	 function set(string memory _value) public {
		 value = _value;
	 }

}
```

For the rest of the section, we'll be using solidity 0.5.1.

### Visibility
If we change the visibility of the variable *value* to public, we don't need the *get()* function.

```
string public value;
```

### Default Value
We can also get rid of the constructor and set a default value for the variable *value*.

```
string public value = "myValue";
```

### Constants
If we want to declare a constant, we use the *constant* keyword. Along with this, we also get rid of methods that modify the identifier.

```
pragma solidity ^0.5.1;

contract MyContract {
	string public constant value = "myValue";
}
```

### Supported datatypes
Datatypes supported by solidity includes boolean, integers (signed or unsigned) among many others.

```
bool public myBool = true;
int public myInt = 1;
uint public myUint = 1;
uint256 public myUint256 = 9999;
uint8 public myUint8 = 8;
```

### Address
The *address* datatype can be classified into two types:
- *address*: It holds a 20 byte value (the size of Ethereum address).
- *address payable*: Has the same properties as *address*, but with the additional members- *transfer* and *send*.
The difference between the two is that an *address payable* is an address you can send Ether to, whereas a plain address may not accept Ether because it might be a smart contract that wasn't built to recieve Ether.

### Enum
The *enum* data structure are a way of keeoing track of enumerated lists in Solidity.

```
enum State { Waiting, Ready, Active}
State public state;

constructor() public {
	state = State.waiting;
}

function activate() public {
	state = State.Active;
}

functon isActive() public view returns (bool) {
	return state == State.Active;
}
```

### Structs
Structs are a way to define your own data structure in solidity. We can model any kind of data we want with arbitrary attributes of varying datatypes.

```
struct Person {
	string _firstName;
	string _lastName;
}
```

### Arrays
Let's say that we're storing the data of couple of people. In that case, we're gonna need an **array** of structures. The code for declaring an array of the datatype *person* is:

```
Person[] public people;
```

By assigning the array to the state variable *people*, we are provided with a function that allows us to access the people inside the array.

```
people(0); // returns the value at index 0
```

Let's create a method to add a person to this array.

```
function addPerson(string memory _firstName, string memory _lastName) public {
	people.push(Person(_firstName, _lastName));
}
```

The entire  contract looks like:

```
contract MyContract {
	Person[] public people;

	uint256 public peopleCount;

	struct Person {
		string _firstName;
		string _lastName;
	}

	function addPerson(string memory _firstName, string memory _lastName) public {
		people.push(Person(_firstName, _lastName));
		peopleCount += 1;
	}
}
```

We use the state variable *peopleCount* as a counter cache. Since we cannot return the entire *people* array using the *people()* function, this variable lets us know the number of times we must call the function to get each *Person*.

### Mappings
Solidity provides us with a data structure called *mapping* which allows us to store key-value pairs (Like unordered_map in C++ STL or dictionaries in python). An example of the syntax would look like:

```

contract MyContract {
	mapping(uint => Person) public people;
	uint256 public peopleCount;

	struct Person {
		uint _id;
		string _firstName;
		string _lastName;
	}

	function addPerson(string memory _firstName, string memory _lastName) public {
		peopleCount += 1;
		people[peopleCount] = Person(peopleCount, _firstName, _lastName);

	}
}
```

## Function visibility, Modifiers & Time
### Function visibility specifier
The following specifiers determine how a function can be accessed in a smart contract:

| Specifier| Remarks |
|:---:|:---|
|*public*|  Visible externally and internally (creates a [getter function](https://docs.soliditylang.org/en/v0.8.13/contracts.html#getter-functions) for storage/state variables)|
|*private*|Only visible in the current contract|
|*external*|Only visible externally (only for functions) - i.e. can only be message-called (via `this.func`)|
|*internal*|Only visible internally.|

### Function Modifiers
Function modifiers are used to amend the semantics of functions in a declarative way. Function modifier overloading i.e having the same modifier name with different parameters isn't possible. However, they can be **overridden**.

They are inheritable properties of contracts and may be overriden by derived contracts, only if they are marked *virtual*. [Modifier Overriding](https://docs.soliditylang.org/en/v0.8.13/contracts.html#modifier-overriding)

```
contract MyContract {
	mapping(uint => Person) public people;
	uint256 public peopleCount;

	address owner;

	modifier onlyOwner() {
		require(msg.sender == owner); // throws an error when false
		_; // Uncommon instruction: Tells the compiler to execute the function.
	}
	struct Person {
		uint _id;
		string _firstName;
		string _lastName;
	}

	constructor() public {
		owner = msg.sender;
	}

	function addPerson(string memory _firstName, string memory _lastName) public onlyOwner{
		peopleCount += 1;
		people[peopleCount] = Person(peopleCount, _firstName, _lastName);

	}
}
```

### Time Units
```
contract MyContract {
	mapping(uint => Person) public people;
	uint256 public peopleCount;

	uint256 openingTime = 1649326481; // Change this to see how the modifier works.

	modifier onlyWhileOpen() {
		require(block.timestamp >= openingTime);
		_; // Uncommon instruction: Tells the compiler to execute the function.
	}
	struct Person {
		uint _id;
		string _firstName;
		string _lastName;
	}

	function addPerson(string memory _firstName, string memory _lastName) public onlyWhileOpen{
		peopleCount += 1;
		people[peopleCount] = Person(peopleCount, _firstName, _lastName);

	}
}

```

Time stamps are expressed in seconds in Solidity. Suffixes like *seconds*, *minutes*, *hours*, *days*, and *weeks* are used after literal numbers to specify units of time.
### Modifiers
We can add words to the function definition inorder to change how it behaves.

| Modifier | For| Remarks |
| :---:|:---:|:---|
|*pure*|Functions|Disallows modification or access of state|
|*view*|Functions|Disallows modification of state|
|*payable*|Functions|Allows them to recieve Ether together with a call|
|*constant*|State Variables|Disallows assignment (except initialosation), does not ooccupy storage slot|
|*immutable*|State Variables|Allows exactly one assignment at construction time and is constant afterwards. Is stored in code.|
|*anonymous*|Events|Does not store event signature as topic.|
|*indexed*|Event Parameters|Stores the parameter as topic.|
|*virtual*|Functions, Modifiers|Allows the function's or modifier's behaviour to be changed in derived contracts.|
|*override*|-|States that this function, modifier or public state variable changes the behaviour of a function or modifier on in the base contract.

## Sending Ether, and Events
### Sending ether
```
contract MyContract {

	mapping(address => uint256) public balances;
	address payable wallet;

	constructor(address payable _wallet) public {
		wallet = _wallet;
	}

	function() external payable {
		// This is a fallback function
		buyToken();

	}

	function buyToken() public payable{
		// Function to simulate buying tokens
		// Whenever someone buys a token, this function sends the ether to seller's wallet

		balances[msg.sender] += 1;
		wallet.transfer(msg.value);
	}
}
```
A **fallback function** is a function that is executed when no other function matches the function identifier. It is ececuted if no data was given in the call. The fallback function has to be marked payable to recieve Ether and add it to the entire balance of the contract.

## Events
Events are a way for external consumers to kind of listen for things that happen ins a smart contract. They allow logging to the ethereum blockchain. Some use cases for events are:
- Listening for events and updating user interface
- A cheap form of storage.
```
contract MyContract {

	mapping(address => uint256) public balances;
	address payable wallet;

	event Purchase(
		address _buyer,
		uint256 _amount
	);
	constructor(address payable _wallet) public {
		wallet = _wallet;
	}

	function() external payable {
		// This is a fallback/default function
		buyToken();

	}

	function buyToken() public payable{
		// Function to simulate buying tokens
		// Whenever someone buys a token, this function sends the ether to seller's wallet

		balances[msg.sender] += 1;
		wallet.transfer(msg.value);
		emit Purchase(msg.sender, 1);
	}
}
```

If we want to listen about purchase from certain buyers, we can change the event *Purchase* to have the following definition:
```
event Purchase(
		address indexed _buyer,
		uint256 _amount
	);
function buyToken() public payable{
		// Function to simulate buying tokens
		// Whenever someone buys a token, this function sends the ether to seller's wallet

		balances[msg.sender] += 1;
		wallet.transfer(msg.value);
		emit Purchase(msg.sender, 1);
	}
```

## Smart contract interaction and Inheritance

```
contract ERC20Token {
	string public name;
	mapping(address => uint256) public balances;

	function mint() public{
		balances[msg.sender]++;
	}
}

contract MyContract {
	address payable wallet;
	address payable token;

	event Purchase(
		address _buyer,
		uint256 _amount
	);
	constructor(address payable _wallet, address _token) public {
		wallet = _wallet;
		token = _token;
	}

	function() external payable {
		buyToken();

	}

	function buyToken() public payable{
		ERC20Token _token = ERC20Token(address(token));
		_token.mint();
		wallet.transfer(msg.value);
	}
}
```

---
## **A short note on the ERC-20 token**
The ethereum blockchain allows us to create our own token (like cryptocurrencies) that can be purchased using Ether. ERC-20 is the standard that specifies how these tokens behave.

Ethereum is a blockchain, that keeps track of all the balances of ether. You can make your own cryptocurrency without making your own blockchain using smart contracts (it'll be built on the ethereum blockchain).

---

If we were to observe the code in the function `mint()`, we would see that it wouldn't mint any coins for us rather the address of `MyContract` which calls the function from its `buyToken()` function. To fix this, we change `msg.sender` to `tx.origin`.

Smart contracts can be referenced in many other ways. We can use a one-line expression like this:
```
function buyToken() public payable {
	ERC20Token(addres(token)).mint();
	wallet.transfer(msg.value);
}
```

We can also refactor the token in a state variable like this:
```
contract MyContract {
	ERC20Token public token;
	// ...
}
```

Then we can simply call the `mint()` function like this:
```
function buyToken() public payable {
	token.mint();
	wallet.transfer(msg.value);
}
```

### Inheritance in solidity

Solidity allows us to create smart contracts that inherit from each other. The syntax is as follows:

```
contract MyToken is ERC20Token {
	// ...
}
```

We can keep track of the the token name in the parent smart contract like this:

```
contract ERC20Token {
	string public name;
	mapping(address => uint256) public balances;

	constructor(string memory _name) public {
		name = _name;
	}

	function mint() public {
		balances[tx.origin] ++;
	}
}
```

We can override the name of the parent token inside the constructor of the child token. We can also create a symbol for the child token and set it in the constructor.

```
contract MyToken is ERC20TOken {
	string public symbol;

	constructor ( string memory, _name, string memory _symbol) ERC20Token(_name) public {
		symbol = _symbol;
	}
}
```

We can refer to the parent  `mint()` function by using the `super` keyword:

```
function mint() public {

        super.mint();

        ownerCount ++;

        owners.push(msg.sender);

    }
```

The final code is:
```
pragma solidity ^0.5.15;

contract ERC20Token {

    string public name;

    mapping(address => uint256) public balances;



    constructor (string memory _name) public {

        name = _name;

    }



    function mint() public{

        balances[tx.origin]++;

    }

}



contract MyToken is ERC20Token {

    string public symbol;

    address[] public owners;

    uint256 public ownerCount;



    constructor(string memory _name, string memory _symbol) ERC20Token(_name) public {

        symbol = _symbol;

    }



    function mint() public {

        super.mint();

        ownerCount ++;

        owners.push(msg.sender);

    }



}
```

## Libraries in Solidity

If we have a function that needs to be used across different smart contracts, we define it in a library. We do this to follow the programming principle of DRY - "Don't repeat yourself". The following are the steps to define/create a library in solidity.

1. Use the keyword `library`
```
library Math {
	// ...
}
```

2. Define functions inside the library

```
library Math {
	function divide(uint256 a, uint256 b) {
		require(b > 0);
		uint256 c = a / b;
		return c;
	}
}
```

3. Using the library functions.

```
contract MyContract {
	uint256 public value;

	function calculate(uint _value1, uint _value2) public {
		value = Math.divide(_value1, _value2);
	}
}
```

4. This is how you import libraries from other files:
```
import "./Math.sol";
```

Some of the commonly used libraries are:
1. [OpenZeppelin - Safe Math](https://github.com/OpenZeppelin/openzeppelin-contracts/blob/master/contracts/utils/math/SafeMath.sol)

