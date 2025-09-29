### Ressource management
The standard library components are designed not to leak resources. To do this, they rely on the
basic language support for resource management using constructor/destructor pairs to ensure that a
resource doesn’t outlive an object responsible for it.

**unique_ptr and shared_ptr** are specific pointer that helps manage ressources on the free store. They will delete an object when it oulive it's necessity even if we forget to do so.

### Concurrency
– the execution of several tasks simultaneously – is widely used to improve throughput (by using several processors for a single computation) or to improve responsiveness (by allowing one part of a program to progress while another is waiting for a response).

The standard library directly supports concurrent execution of multiple threads in a single
address space.

The main standard-library
concurrency support facilities: **threads, mutexes, lock() operations, packaged_tasks, and futures.**

#### Tasks and threads:
We call a computation that can potentially be executed concurrently with other computations a task.
A thread is the system-level representation of a task in a program. 

void f(); // function
struct F { // function object
void operator()(); // F’s call operator (§3.4.3)
};
void user()
{
thread t1 {f}; // f() executes in separate thread
thread t2 {F()}; // F()() executes in separate thread
t1.join(); // wait for t1
t2.join(); // wait for t2
}
The join()s ensure that we don’t exit user() until the threads have completed. To ‘‘join’’ means to
‘‘wait for the thread to terminate.’’

#### Sharing Data

Sometimes tasks need to share data. In that case, the access has to be synchronized so that at most
one task at a time has access. Experienced programmers will recognize this as a simplification
(e.g., there is no problem with many tasks simultaneously reading immutable data), but consider
how to ensure that at most one task at a time has access to a given set of objects.
The fundamental element of the solution is a mutex, a ‘‘mutual exclusion object.’’ A thread
acquires a mutex using a lock() operation:


#### Waiting for Events

Sometimes, a thread needs to wait for some kind of external event, such as another thread completing a task or a certain amount of time having passed. The simplest ‘‘event’’ is simply time passing.
Consider:

***
using namespace std::chrono; // see §35.2
auto t0 = high_resolution_clock::now();
this_thread::sleep_for(milliseconds{20});
auto t1 = high_resolution_clock::now();
cout << duration_cast<nanoseconds>(t1−t0).count() << " nanoseconds passed\n";
***

Note that I didn’t even hav e to launch a thread; by default, this_thread refers to the one and only
thread.

I used duration_cast to adjust the clock’s units to the nanoseconds I wanted and before trying anything more complicated than this with time. The time facilities are found in <chrono>.

#### Communicating Tasks
The standard library provides a few facilities to allow programmers to operate at the conceptual
level of tasks (work to potentially be done concurrently) rather than directly at the lower level of
threads and locks:

[1] future and promise for returning a value from a task spawned on a separate thread
[2] packaged_task to help launch tasks and connect up the mechanisms for returning a result
[3] async() for launching of a task in a manner very similar to calling a function.
These facilities are found in <future>.

**future and promise**
The important point about **future and promise** is that they enable a transfer of a value between two
tasks without explicit use of a lock; ‘‘the system’’ implements the transfer efficiently. The basic
idea is simple: When a task wants to pass a value to another, it puts the value into a **promise**. Somehow, the implementation makes that value appear in the corresponding **future**, from which it can be
read (typically by the launcher of the task).

#### async()

Basically, **async()** separates the ‘‘call part’’ of a function call from the ‘‘get the result part,’’ and separates both from the actual execution of the task. Using **async()**, you don’t hav e to think about
threads and locks. Instead, you think just in terms of tasks that potentially compute their results
asynchronously

### Small utilities components

Not all standard-library components come as part of obviously labeled facilities, such as ‘‘containers’’ or ‘‘I/O.’’ This section gives a few examples of small, widely useful components:
• clock and duration for measuring time.
• Type functions, such as iterator_traits and is_arithmetic, for gaining information about types.
• pair and tuple for representing small potentially heterogeneous sets of values.
The point here is that a function or a type need not be complicated or closely tied to a mass of other
functions and types to be useful. Such library components mostly act as building blocks for more
powerful library facilities, including other components of the standard library

#### Time
The standard library provides facilities for dealing with time. For example, here is the basic way of
timing something:
***
using namespace std::chrono; // see §35.2
auto t0 = high_resolution_clock::now();
do_work();
auto t1 = high_resolution_clock::now();
cout << duration_cast<milliseconds>(t1−t0).count() << "msec\n";
***

The clock returns a time_point (a point in time). Subtracting two time_points giv es a duration (a
period of time). Various clocks give their results in various units of time (the clock I used measures nanoseconds), so it is usually a good idea to convert a duration into a known unit .That’s what duration_cast does.

#### Type Predicates
A standard-library type predicate is a simple type function that answers a fundamental question
about types. For example:

***
bool b1 = Is_arithmetic<int>(); // yes, int is an arithmetic type
bool b2 = Is_arithmetic<string>(); // no, std::str ing is not an arithmetic type
***

### Regular Expressions

Regular expressions are a powerful tool for text processing. They provide a way to simply and tersely describe patterns in text.

In <regex>, the standard library provides
support for regular expressions in the form of the std::regex class and its supporting functions. To
give a taste of the style of the regex library, let us define and print a pattern:

***
regex pat (R"(\w{2}\s∗\d{5}(−\d{4})?)"); // ZIP code pattern: XXddddd-dddd and var iants
cout << "pattern: " << pat << '\n';
***

### Advice

[1] Use resource handles to manage resources (RAII); §5.2.
[2] Use unique_ptr to refer to objects of polymorphic type; §5.2.1.
[3] Use shared_ptr to refer to shared objects; §5.2.1.
[4] Use type-safe mechanisms for concurrency; §5.3.
[5] Minimize the use of shared data; §5.3.4.
[6] Don’t choose shared data for communication because of ‘‘efficiency’’ without thought and
preferably not without measurement; §5.3.4.
[7] Think in terms of concurrent tasks, rather than threads; §5.3.5.
[8] A library doesn’t hav e to be large or complicated to be useful; §5.4.
[9] Time your programs before making claims about efficiency; §5.4.1.
[10] You can write code to explicitly depend on properties of types; §5.4.2.
[11] Use regular expressions for simple pattern matching; §5.5.
[12] Don’t try to do serious numeric computation using only the language; use libraries; §5.6.
[13] Properties of numeric types are accessible through numeric_limits; §5.6.5.