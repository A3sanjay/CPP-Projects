#include <cassert>
#include <iomanip>
#include <iostream>

#include "project4.hpp"
#include "History.hpp"
#include "Transaction.hpp"

////////////////////////////////////////////////////////////////////////////////
// Definitions for Transaction class
////////////////////////////////////////////////////////////////////////////////
//
//

// Constructor
// TASK 1
//

Transaction::Transaction (std::string ticker_symbol, 
                          unsigned int day_date, 
                          unsigned int month_date,
                          unsigned int year_date,
                          bool buy_sell_trans,
                          unsigned int number_shares,
                          double trans_amount)
{
  symbol = ticker_symbol;
  day = day_date;
  month = month_date;
  year = year_date;
  if (buy_sell_trans == true) 
    trans_type = "Buy";
  else 
    trans_type = "Sell";

  shares = number_shares;
  amount = trans_amount;
  trans_id = assigned_trans_id;
  assigned_trans_id++;
  p_next = nullptr;
  acb = 0;
  acb_per_share = 0;
  share_balance = 0;
  cgl = 0;
}
// Destructor
// TASK 1
//

Transaction::~Transaction ()
{

}

// Overloaded < operator.
// TASK 2
//

bool Transaction::operator < (Transaction const & other)
{
  symbol;
  other.symbol;
  
  if (this->year < other.year)
    return true;
  if (this->year == other.year && this->month < other.month)
    return true;
  if (this->year == other.year && this->month == other.month && this->day < other.day)
    return true;
  return false;
}
// GIVEN
// Member functions to get values.
//
std::string Transaction::get_symbol() const { return symbol; }
unsigned int Transaction::get_day() const { return day; }
unsigned int Transaction::get_month() const { return month; }
unsigned int Transaction::get_year() const { return year; }
unsigned int Transaction::get_shares() const { return shares; }
double Transaction::get_amount() const { return amount; }
double Transaction::get_acb() const { return acb; }
double Transaction::get_acb_per_share() const { return acb_per_share; }
unsigned int Transaction::get_share_balance() const { return share_balance; }
double Transaction::get_cgl() const { return cgl; }
bool Transaction::get_trans_type() const { return (trans_type == "Buy") ? true: false ; }
unsigned int Transaction::get_trans_id() const { return trans_id; }
Transaction *Transaction::get_next() { return p_next; }

// GIVEN
// Member functions to set values.
//
void Transaction::set_acb( double acb_value ) { acb = acb_value; }
void Transaction::set_acb_per_share( double acb_share_value ) { acb_per_share = acb_share_value; }
void Transaction::set_share_balance( unsigned int bal ) { share_balance = bal ; }
void Transaction::set_cgl( double value ) { cgl = value; }
void Transaction::set_next( Transaction *p_new_next ) { p_next = p_new_next; }

// GIVEN
// Print the transaction.
//
void Transaction::print() {
  std::cout << std::fixed << std::setprecision(2);
  std::cout << std::setw(4) << get_trans_id() << " "
    << std::setw(4) << get_symbol() << " "
    << std::setw(4) << get_day() << " "
    << std::setw(4) << get_month() << " "
    << std::setw(4) << get_year() << " ";


  if ( get_trans_type() ) {
    std::cout << "  Buy  ";
  } else { std::cout << "  Sell "; }

  std::cout << std::setw(4) << get_shares() << " "
    << std::setw(10) << get_amount() << " "
    << std::setw(10) << get_acb() << " " << std::setw(4) << get_share_balance() << " "
    << std::setw(10) << std::setprecision(3) << get_acb_per_share() << " "
    << std::setw(10) << std::setprecision(3) << get_cgl()
    << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
// Definitions for the History class
////////////////////////////////////////////////////////////////////////////////
//
//


// Constructor
// TASK 3
//

History::History() 
{
  this->p_head = nullptr;
}

// Destructor
// TASK 3
//

History::~History()
{
  // Iterate through the linked list and delete every element in the linked list
  Transaction * p_index1{p_head};
  Transaction * p_index2{p_head};
  while (p_index2 != nullptr)
  {
    // Assign first pointer to current element
    // Assign second pointer to next element (get next)
    // Delete first pointer, then use get next on first pointer 
    p_index2 = p_index2 -> get_next();   
    delete p_index1;
    p_index1 = p_index2;
  }
  delete p_index1;
  p_index1 = nullptr;
  delete p_index2;
  p_index2 = nullptr;
}

// read_history(...): Read the transaction history from file.
// TASK 4
//

void History::read_history()
{
  ece150::open_file();
  while (ece150::next_trans_entry() == true)
  {
    Transaction * p_index{new Transaction (ece150::get_trans_symbol(), 
                                          ece150::get_trans_day(),
                                          ece150::get_trans_month(),
                                          ece150::get_trans_year(),
                                          ece150::get_trans_type(),
                                          ece150::get_trans_shares(),
                                          ece150::get_trans_amount())};
  // Use all of the transactions in the .txt file into linked list
  // Use History::insert to dynamically allocate a transaction with the given values
    this -> insert(p_index);
    p_index = p_index -> get_next(); 
  }
  ece150::close_file();
}

// insert(...): Insert transaction into linked list.
// TASK 5
//

void History::insert(Transaction * p_new_trans)
{
  // // Method of traversing the linked list
  // // The transaction identifier will use the private member variable 
  // // trans_id to store the unique identifier

  if (p_head == nullptr) {
    this -> p_head = p_new_trans;
  }
  else {
    Transaction * p_index{p_head};
    while (p_index -> get_next() != nullptr) {
      p_index = p_index -> get_next();
    }
  p_index -> set_next(p_new_trans); 
  } 
}

// sort_by_date(): Sort the linked list by trade date.
// TASK 6
//

void History::sort_by_date()
{
  Transaction * p_front{nullptr};
  Transaction * p_head_new{nullptr};
  while(p_head != nullptr) {
    // Breaks off the first part of the list from the rest
    p_front = p_head;
    p_head = p_head -> get_next();
    p_front -> set_next(nullptr);
    if (p_head_new == nullptr) {
      p_head_new = p_front;
      p_front = nullptr;
    }
    else {
      Transaction * p_traverse{p_head_new};
      if ((*p_front < *p_traverse) == true) { // Front case 
        // Inserts the p_front in between the two spots where it should go
        p_front -> set_next(p_traverse);
        p_head_new = p_front;
        p_front = nullptr;
        p_traverse = nullptr;
      }
      else { // Middle and End case
        while (p_traverse -> get_next() != nullptr && *(p_traverse -> get_next()) < *p_front) {  // Change the condition inside while loop
          p_traverse = p_traverse -> get_next();
        }
        Transaction * temp = p_traverse->get_next(); 
        p_traverse -> set_next(p_front);
        p_front->set_next(temp);
        p_front = nullptr;
        p_traverse = nullptr;
      } 
    }
  }
  p_head = p_head_new;
}

// update_acb_cgl(): Updates the ACB and CGL values.
// TASK 7
//

void History::update_acb_cgl() 
{
  // Calculate and update cgl every time there is a new object passed(acb, number of shares, cgl, acb per share, etc...)
  Transaction * p_index{p_head};
  double acb{};
  double amount{};
  double share_balance{};
  double amount_sb{};
  double acb_share{};
  double number_shares{};
  double old_acb_share{};
  double cgl{};
  double old_acb{};
    while (p_index != nullptr) {
      // Buy
      if (p_index -> get_trans_type() == true) {
      // Computing ACB
      amount = p_index -> get_amount();
      acb = acb + amount;
      p_index -> set_acb(acb);
      // Computing Share Balance
      amount_sb = p_index -> get_shares();
      share_balance = share_balance + amount_sb;
      p_index -> set_share_balance(share_balance);
      // Computing ACB/share
      acb_share = (p_index -> get_acb())/(p_index -> get_share_balance());
      p_index -> set_acb_per_share(acb_share);
      }
      // Sell
      else {
        // Computing ACB
        number_shares = p_index -> get_shares();
        acb = old_acb - (number_shares * old_acb_share);
        p_index -> set_acb(acb);
        // Computing Share Balance
        amount_sb = p_index -> get_shares();
        share_balance = share_balance - amount_sb;
        p_index -> set_share_balance(share_balance);
        // Computing ACB/share
        acb_share = (p_index -> get_acb())/(p_index -> get_share_balance());
        p_index -> set_acb_per_share(acb_share);
        // Computing CGL
        amount = p_index -> get_amount();
        cgl = amount - (number_shares * old_acb_share);
        p_index -> set_cgl(cgl);
      }
    old_acb = p_index -> get_acb();
    old_acb_share = p_index -> get_acb_per_share();
    p_index = p_index -> get_next();
  }
}

// compute_cgl(): Compute the ACB, and CGL.
// TASK 8
double History::compute_cgl(unsigned int year)
{
  // Get cgl values from every year, and add them together
  // temp -> year
  Transaction * p_index{p_head};
  double sum{};
  while (p_index != nullptr) {
    if (p_index -> get_year() == year) {
      sum = sum + p_index -> get_cgl();
    }    
    p_index = p_index -> get_next();
  }
  return sum;
}

// print() Print the transaction history.
//TASK 9
//

void History::print() 
{
  // Iterate through the linked list and print the values (create a temp variable and send it through linked list)
  // temp -> print()
  Transaction * p_index{p_head};
  std::cout << "========== BEGIN TRANSACTION HISTORY ==========" << std::endl;
  while (p_index != nullptr)
  {
    // Use print function to print values
    p_index -> print();
    // Traverses linked list
    p_index = p_index -> get_next();   
  }
  std::cout << "========== END TRANSACTION HISTORY ==========" << std::endl;
}

// GIVEN
// get_p_head(): Full access to the linked list.
//
Transaction *History::get_p_head() { return p_head; }
