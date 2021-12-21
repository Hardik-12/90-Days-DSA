#DAY1 -> Recursion


Recursion->Function calling itself directly or indirectly.

An example of direct recursive function.


# There is no termination condition here and 
function keeps on calling itself.

void fun1(){
    cout << "fun1" << "\n";
    fun1();
}

int main(){
    fun1();
    return 0;
}

Recursion involves a base condition so that our 
program will stop at particular point.

Structure of recursion
----------------------------------

fun(.........){
    Base Cases
    ...............


    Recursive Call(Call to fun()) # With at least one change in parameter.

}


Some Practice on recursion
----------------------------------------

void fun(int n){
    if(n == 0){
        return;
    }
    cout << n << "\n";
    fun(n-1);
    cout << n << "\n";
}

int main(){
    fun(3);
}
// O/P:- 3 2 1 1 2 3



void fun(int n){
    if(n == 0){
        return;
    }
    fun(n-1);
    cout << n << "\n";
    fun(n-1);
}

int main(){
    fun(3);
}
// O/P:- 1 2 1 3 1 2 1

How recursion works in above example.
main()
   fun(3)
        fun(2)
            fun(1)
                 fun(0)
                     1
                     fun(0)
            2
            fun(1)
                 .....
                 .....

int fun(int n){
    if(n == 0){
        return 0;
    }else{
        return 1 + fun(n/2);
    }
}

int main(){
    fun(16);
}
// O/P:- 4

void fun(){
    if(n == 0){
        return;
    }

    fun(n/2);
    cout << n%2 << "\n";
}
// O/P:- Prints binary equivalent of a decimal number



// Sum of 1st n natural numbers
int sum_1_to_n(int n){
    if(n==0){
        return 0;
    }
    
    return n + sum_1_to_n(n-1);
    
}

int main(){
    cout << sum_1_to_n(6);
}


// Print n to 1 using recursion
// This is a tail recursive function because last call that happens here is a recursive call.

// A function is tail recursive when parent call has nothing to do when child call finishes.

// A tail recursive function takes less time than a non-tail recursive function.

void n_to_1(int n){
    if(n == 0){
        return;
    }
    cout << n << "\n";
    n_to_1(n-1); // In tail recursion modern compiler changes this call to (n = n-1 goto start)
    // Now it is no longer a recursive call.
}

int main(){
    n_to_1(7);
}

// Print 1 to n using recursion.

void one_to_n(int n){
    if(n == 0){
        return;
    }
    one_to_n(n-1);
    cout << n << "\n";
}

int main(){
    one_to_n(7);
}


// This is an equivalent tail recursive function of above function.

void one_to_n(int n, int k){
    if(n == 0){
        return;
    }
    cout << k << "\n";
    one_to_n(n-1, k+1);
}

int main(){
    one_to_n(7,1);
}


// Tail recursive factorial function 
void fact(int n, int k){
    if(n == 0 || n == 1){
        return k;
    }
    fact(n-1, k*n);
}

int main(){
    fact(5, 1);
}