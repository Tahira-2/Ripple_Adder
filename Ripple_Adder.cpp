#include <iostream>
#include <vector>
using namespace std;

/* Nme: Ripple Adders
       : it adds two binary digits bit by bit and then print the sum and carry separately

OPERATIONS: sum = A XOR B XOR C_in
            = sum1 XOR C_in (sum1 = A XOR B)
        carry (C_out) = A.B OR C_in.sum1
 variables:
    A = first binary
    B = second binary
    c_in = input carry bit (first one is 0, then it changes inside the function)

  steps:
    1.we add the right most digits
    2.store the sum inside a list called "list_sum"
    3.we upgrade C_in with the Carry of these two digits
    4.that's how our for loop pass the carry to the next right most digits
    5.finally we print the final carry-bit
    6.get the final sum by printing elements from the list by order
*/

//this function creates XOR gate:  (A OR B) AND NOT (A AND B)
bool get_xor(bool A, bool B) {
    bool xor_gate;

    xor_gate = (A || B) && !(A && B);

    return xor_gate;
}

// this function returns the sum of the digits
bool get_sum(bool A, bool B, bool C_in) {
    bool sum1, sum_final;

    sum1 = get_xor(A, B);
    sum_final = get_xor(sum1, C_in);

    return sum_final;
}

// this function returns the carry digit
bool get_carry(bool A, bool B, bool C_in) {
    bool sum1, carry;

    sum1 = get_xor(A, B);
    carry = (A && B) || (C_in && sum1);

    return carry;
}


// this is the main function that will print the sum and carry of three binary digit, in short it will work as an actual full adder
int main() {
    int num_of_digit;
    cout << "Enter the number of digits in the numbers: ";
    cin >> num_of_digit;

    string num1 = "1100", num2 = "1001";
    cout << "Enter two binary numbers separated by space: ";
    cin >> num1 >> num2;

    int A, B, C_in = 0;  //for the eftmost digits, the intial carry is 0
    int C_out;
    vector<int> list_sum;

    int i, s; // i is used in for loop, and s is to store the sums inside the list_sum vector
    for (i = (num_of_digit - 1); i >= 0; i--) {
        A = num1[i] - '0';    // substract '0' to get convert string to integer
        B = num2[i] - '0';

        s = get_sum(A, B, C_in);
        list_sum.insert(list_sum.begin(), s); //storing the sums inside a list to print later

        C_in = get_carry(A, B, C_in);   //to passe "carry bit" and add them with the digits in the next place
    }
    C_out = C_in;

    //this loop gets the sum bit by bit from the vector and then print it as a whole number
    cout << "The sum is: ";
    for (int i : list_sum) {
        cout << i;
    }

    cout << "\nThe carry is: " << C_out << endl;
}